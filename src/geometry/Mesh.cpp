#include "Mesh.h"


// CONSTRUCTORS & DESTRUCTORS


Mesh::Mesh(){
	// Default constructor
}


// ACCESSORS


// OTHER METHODS


void Mesh::print_mesh(){
	std::cout << "\n\n\n ****  MESH INFORMATION  ****" << "\n\n";
	// Printing the finite elements
	std::cout << "------------Elements----------" << "\n";
	std::cout << "Type: " << element_type << "\n";
	std::cout << "Family: " << element_family << "\n";
	std::cout << "Pol. order: " << polynomial_order << "\n";
	std::cout << "Geo. order: " << elements.get_entity(1).get_curve_order() << "\n";
	std::cout << "N° elements: " << nelements << "\n";
	std::cout << "------------------------------" << "\n";

	for(int j=1; j<=nelements; j++){
		Element element = elements.get_entity(j);
		std::cout << "\n(global idx=" << element.get_index() << ")   ";
		// Initialise the local index for the nodes
		int local_node_idx=1;
		for(auto node : element.get_nodes().get_list()){
			// Print the nodes
			std::cout << "v" << local_node_idx << "=" << node.get_index() << ", ";
			local_node_idx++;
		}

		std::cout << "\n                  ";
		// Initialise the local index for the edges
		int local_edge_idx=1;
		for(auto edge : element.get_edges().get_list()){
			// Print the edges
			std::cout << "e" << local_edge_idx << "=" << edge.get_index() << ", ";
			local_edge_idx++;
		}
	}

	// Printing all the nodes in the mesh
	std::cout << "\n\n------------Geometry-----------" << "\n";
	std::cout << "N° nodes: " << nnodes << "\n";
	std::cout << "(of which on the boundary): " << boundary_nodes.get_length() << "\n";
	switch(dimension){
		// Print the additional info according to the spatial dimension of the domain
		case 1:
		std::cout << "\n";
		break;

		case 2:
		std::cout << "N° edges: " << nedges << "\n";
		break;

		case 3:
		std::cout << "N° edges: " << nedges << "\n";
		std::cout << "N° faces: " << nfaces << "\n";
		break;
	}
	std::cout << "-------------------------------" << "\n";

	// Printing the DOFs
	for(int j=1; j<=nnodes; j++){
		Point node = inner_nodes.get_entity(j);
		std::cout << "\n(global idx=" << node.get_index() << ")   ";
		switch(dimension){
			// Print coordinates according to the spatial dimension of the domain
			case 1:
			std::cout << "x=" << node.get_x();
			break;

			case 2:
			std::cout << "x=" << node.get_x() << ", " << "y=" << node.get_y();
			break;

			case 3:
			std::cout << "x=" << node.get_x() << ", " << "y=" << node.get_y() << ", " << "z=" << node.get_z();
			break;
		}
	}

	// Printing the boundary nodes
	std::cout << "\n-----------------------------" << "\n";
	for(int j=1; j<=boundary_nodes.get_largest_index(); j++){
		try{
			// Get boundary node stored at index j
			Point node = boundary_nodes.get_entity(j);
			std::cout << "\n(global idx=" << node.get_index() << ")   " << "BC=" << node.get_BC();
		}
		catch(const std::invalid_argument& stod_exception){
			// ... unless there is no boundary node for that index, in that case just skip through
		}
	}

	// Printing the edges
	std::cout << "\n-----------------------------" << "\n";
	for(int j=1; j<=edges.get_length(); j++){
		Line edge = edges.get_entity(j);
		std::cout << "\n(global idx=" << edge.get_index() << ")   ";
		std::cout << "initial point = " << edge.get_initial().get_index() <<  ", " << "final point = " << edge.get_final().get_index();
	}

	std::cout << "\n\n ****  END MESH INFORMATION  ****" << "\n\n\n";
}

void Mesh::write_mesh(){
	//
}


// OVERLOADED METHODS


void Mesh::process(){/*  */};

void Mesh::build_dofs(){/*  */};


// METHODS TO BE INHERITED


void Mesh::init(std::string* arg_family, int* arg_order){
	// Initialises the fundamental information about the mesh as provided by the input raw mesh
	dimension = inner_nodes.get_entity(1).get_dimension(); 
	element_type = elements.get_entity(1).get_type();
	
	nnodes = inner_nodes.get_length();
	nedges = edges.get_length();
	nfaces = faces.get_length();
	nelements = elements.get_length();
	
	// Initialises the custom information about the mesh as provided by the user
	element_family = *arg_family;
	polynomial_order = *arg_order;
}

// PRIVATE METHODS