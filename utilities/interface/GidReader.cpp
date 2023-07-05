#include "GidReader.h"


// CONSTRUCTORS & DESTRUCTORS


GidReader::GidReader(): MeshReader(){
	// Default constructor
}

GidReader::GidReader(std::string arg_filename): MeshReader(arg_filename){
	// Parametric constructor
}


// ACCESSORS


// OTHER METHODS


void GidReader::read_list(){
	std::vector<std::string> entities{"Coordinates", "Elements", "Boundary Nodes"};
	// Read the mesh file from beginning_position to end_position and store the data accordingly 
	std::ifstream mesh_file(filename, std::ios::in | std::ios::app);
	for(int j=0; j<3; j++){
		// This method is ran three times, once for each list of entities in the mesh file
		listname = entities[j];
		// For the given entity's list set the opening and closing lines bounding the list ...
		set_endlines();
		// ... and initialise the position of the lines in the mesh file
		set_position();

		if(mesh_file.is_open()){
			// Set the reading to start from beginning_position
			mesh_file.seekg(beginning_position);
			// Read each line until the reading index reaches the end_position
			while(std::getline(mesh_file, readline) && mesh_file.tellg() < end_position){
				// Fill-in the list matrix with the entity's information converted into number types
				format_entity(j+1);
			}
		}
	}
	mesh_file.close();
}


void GidReader::process(std::string arg_family, int arg_order){
	// Get the edges and the faces of the mesh from Gid
	build_missing_entity_list();
	// Modify the order (local index) of the edges of the elements to comply with TAP'97
	rearrange();
	// Create the type of Finite Elements based on the specified Degrees Of Freedom (DOFs)
	build_dofs(&arg_family, &arg_order);
	// Initialise the mesh charateristics with the updated info
	init(&arg_family, &arg_order);
	// Permanently erase the uncategorazed elements list
	elements.clear();
	// Write mesh into separate files
	write_mesh();
}


void GidReader::apply_BC(int arg_label, double arg_value, std::string arg_type){
	EntityList<Point> new_boundary_nodes;
	// Apply Dirichlet Boundary Conditions
	if(arg_type=="DIR"){
		for(int j=1; j<boundary_nodes.get_length(); j++){
			if(boundary_nodes.get_entity(j,true).get_BClabel()==arg_label){
				Point new_boundary_node = boundary_nodes.get_entity(j,true);
				new_boundary_node.set_BCvalue(arg_value);
				new_boundary_nodes.add_entity(new_boundary_node);
			}
		}
	}
	// Apply Neumann Boundary Conditions
	else if(arg_type=="NEU"){
		// TO BE WRITTEN LATER
	}
}


// PRIVATE METHODS


void GidReader::set_endlines(){
	// Based on the name of the list of entities define the opening and closing lines that bound such list
	opening_line = listname;
	closing_line = "End " + opening_line;
}

void GidReader::set_position(){
	std::string line;
	// Reading the mesh file to detect the position of the opening and closing lines that bound the list
	std::ifstream mesh_file(filename, std::ios::in | std::ios::app);
	if(mesh_file.is_open()){
		while(std::getline(mesh_file, line)){
			if(line==opening_line){
				// Found the list's beginning position
				beginning_position = mesh_file.tellg();
			}
			else if(line==closing_line){
				// Found the list's end position
				end_position = mesh_file.tellg();
				break;
			}
		}
	}
	else{
		std::cout << "Unable to open the file" << "\n";
	}
	mesh_file.close();
}


void GidReader::format_entity(int arg_entity_list_index){
	std::string word;
	// Transform the entity from a unique string of chars into a sequence of strings, each being a sigle word (i.e. broke-up sentence), by removing the empty spaces
	std::stringstream sentence(readline);
	// Discriminate among the three entities' lists
	switch(arg_entity_list_index){
	
		case 1:{
			// Coordinates (inner_nodes)
			sentence >> word;
			int global_index = std::stoi(word);

			std::vector<double> coordinates;
			// Loop over the remaining words in the broke-up readline
			while(sentence >> word){
				coordinates.push_back(std::stod(word));
			}

			// Update the entity list of the class
			inner_nodes.add_entity(Point(global_index, coordinates[0], coordinates[1]));
			break;
		}

		case 2:{
			// Elements
			sentence >> word;
			int index = std::stoi(word);

			std::vector<Point> nodes_indices;
			// Loop over the remaining words in the broke-up readline
			while(sentence >> word){
				nodes_indices.push_back(inner_nodes.get_entity(std::stoi(word)));
			}

			// Update the entity list of the class
			temp_elements.add_entity(Element(index, nodes_indices));
			break;
		}

		case 3:{
			// Boundary nodes
			std::vector<int> boundary_node;
			// Loop over the remaining words in the broke-up readline
			while(sentence >> word){
				try{
					// In Gid's mesh file the Boundary nodes list's lines contain characters which should be ignored
					boundary_node.push_back(std::stod(word));
				}
				catch(const std::invalid_argument& stod_exception){/* Do nothing here */}
			}
			// Create the Point object with constructor for the boundary nodes
			Point boundaryNode(boundary_node[0]);
			// Set the boundary condition specified for the boundary node
			boundaryNode.set_BClabel(boundary_node[1]);
			// Update the corresponding entity list
			boundary_nodes.add_entity(boundaryNode);
			break;
		}
	}
}

void GidReader::build_missing_entity_list(){
	// Initialise the global index that will iteratively be assigned to the edges
	int line_global_index = 1;
	// Gid does not provide any info regarding the edges in the mesh therefore...
	for(auto element : temp_elements.get_list()){
		EntityList<Line> elementEdges;
		// ... we must iterate over each element in the elements' list and ...
		for(auto edge : element.get_edges().get_list()){
			// ... for each of the edges that define such element check if it already exists in the mesh's edges list
			if(!edges.it_exists(&edge)){
				// ... and if it does not then initialise the edge's global index and update the mesh's edges list!
				edge.set_global_index(line_global_index);
				edges.add_entity(edge);
				// Now we need to update the edges list of the element
				elementEdges.add_entity(edge);
				// Finally don't forget to update the global index counter
				line_global_index++;
			}
			else{
				elementEdges.add_entity(edge);
			}
		}
		// We then fill-in the real elements list of the mesh...
		elements.add_entity(Element(element, elementEdges));
	}
	// ... and temporarly erase the temporary one!
	temp_elements.clear();
}

void GidReader::rearrange(){
	// Loop over each element
	for(auto element : elements.get_list()){
		// Get the current edges list and initialise an empty rearranged edges list
		EntityList<Line> current = element.get_edges(); 
		EntityList<Line> rearranged;
		// Rearrange the edges' local index based to the element type
		if(element.get_shape().get_type()=="Triangle"){
			// Hard coded
			rearranged.add_entity(current.get_entity(1, true));
			rearranged.add_entity(current.get_entity(2, true));
			rearranged.add_entity(current.get_entity(0, true));
		}
		else if(element.get_shape().get_type()=="Quadrilateral"){
			// Hard coded
			rearranged.add_entity(current.get_entity(2, true));
			rearranged.add_entity(current.get_entity(3, true));
			rearranged.add_entity(current.get_entity(0, true));
			rearranged.add_entity(current.get_entity(1, true));
		}
		// Add the new element (with rearranged edges) to the temporary list
		temp_elements.add_entity(Element(element, rearranged));
	}
	// Erase the Mesh's elements list and update it with the temporary one
	elements.fill_in(&temp_elements);
	// Permanently erase the temporary elements list
	temp_elements.clear();
}

void GidReader::build_dofs(std::string* arg_family, int* arg_order){
	// Initialise Element's child class
	if(*arg_family=="Lagrange"){	
		for(auto element : elements.get_list()){
			// Populate the Lagrange elements's list
			Lagrange new_element(element, arg_family, arg_order);
			lagrangian.add_entity(new_element);
			// Populate the DOFs' list
			EntityList<DOF> elemental_dofs = new_element.get_dofs();
			for(auto dof : elemental_dofs.get_list()){
				if(!dofs.it_exists(&dof)){
					// Populate DOF's elemental support
					for(auto search_element : elements.get_list()){
						for(int j=0; j<search_element.get_nodes().get_length(); j++){
							Point node = search_element.get_nodes().get_entity(j,true);
							if(node.get_index()==dof.get_index()){
								dof.update(search_element.get_index());
							}
						}
					}
					dofs.add_entity(dof);
				}
			}
		}
	}
	else if(*arg_family=="Nedelec"){
		
		for(auto element : elements.get_list()){
			// Populate the Nedelec elements's list
			Nedelec new_element(element, arg_family, arg_order);
			curl_conf.add_entity(new_element);
			// Populate the DOFs' list (TO BE WRITTEN LATER)
		}
	}
}