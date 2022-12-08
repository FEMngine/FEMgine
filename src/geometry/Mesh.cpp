#include "Mesh.h"
#include <iomanip>


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
	std::cout << "Type: " << elements.get_entity(1).get_type() << "\n";
	std::cout << "Family: " << elements.get_entity(1).get_family() << "\n";
	std::cout << "Pol. order: " << elements.get_entity(1).get_poly_order() << "\n";
	std::cout << "N° elements: " << elements.get_length() << "\n";
	std::cout << "------------------------------" << "\n";

	for(int j=1; j<=elements.get_length(); j++){
		Element element = elements.get_entity(j);
		std::cout << "\n(idx=" << element.get_index() << ")   ";
		// Initialise the local index for the nodes
		int k=1;
		for(auto node : element.get_nodes()){
			std::cout << "v" << k << "=" << node.get_index() << ", ";
		}
	}

	// Printing all the nodes in the mesh
	std::cout << "\n\n-------------Nodes-----------" << "\n";
	std::cout << "N° DOFs: " << inner_nodes.get_length() << "\n";
	std::cout << "N° boundary nodes: " << boundary_nodes.get_length() << "\n";
	std::cout << "-----------------------------" << "\n";

	// Printing the DOFs
	for(int j=1; j<=inner_nodes.get_length(); j++){
		Point node = inner_nodes.get_entity(j);
		std::cout << "\n(global idx=" << node.get_index() << ")   ";
		switch(node.get_dimension()){
			// Print coordinates according to the dimensionality of the domain
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
			std::cout << "global idx=" << node.get_index() << ", " << "BC=" << node.get_BC() << "\n";
		}
		catch(const std::invalid_argument& stod_exception){
			// ... unless there is no boundary node for that index, in that case just skip through
		}
	}

	std::cout << "\n\n ****  END MESH INFORMATION  ****" << "\n\n\n";
}


// OVERLOADED METHODS


// PRIVATE METHODS