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
			inner_nodes.add_entity(Point(global_index, coordinates[0], coordinates[1], coordinates[2]));
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
			elements.add_entity(Element(index, nodes_indices));
			break;
		}

		case 3:{
			// Boundary nodes
			std::vector<double> boundary_node;
			// Loop over the remaining words in the broke-up readline
			while(sentence >> word){
				try{
					// In Gid's mesh file the Boundary nodes list's lines contain characters which should be ignored
					boundary_node.push_back(std::stod(word));
				}
				catch(const std::invalid_argument& stod_exception){/* Do nothing here */}
			}
			// Create the Point object with constructor for the boundary nodes
			Point boundaryNode(static_cast<int>(boundary_node[0]));
			// Set the boundary condition specified for the boundary node
			boundaryNode.set_BC(boundary_node[1]);
			// Update the corresponding entity list
			boundary_nodes.add_entity(boundaryNode);
			break;
		}
	}
}