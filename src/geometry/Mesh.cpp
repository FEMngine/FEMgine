#include "Mesh.h"


// CONSTRUCTORS & DESTRUCTORS


Mesh::Mesh(){
	// Default constructor
}


// ACCESSORS


std::string Mesh::get_family(){
	return element_family;
}


// OTHER METHODS


void Mesh::print_mesh(){
	std::cout << "\n\n ****  MESH INFORMATION  ****" << "\n\n\n";
	// Printing the recap and general info
	std::cout << "------------------Overview-----------------" << "\n";
	std::cout << "Type: " << element_type << "\n";
	std::cout << "Family: " << element_family << "\n";
	std::cout << "Pol. order: " << polynomial_order << "\n";
	std::cout << "Geo. order: " << geometrical_order << "\n";
	std::cout << "N° elements: " << nelements << "\n";
	std::cout << "N° DOFs: " << dofs.get_length() << "\n";
	std::cout << "N° nodes: " << nnodes << "\n";
	std::cout << "N° boundary nodes: " << boundary_nodes.get_length() << "\n";
	switch(dimension){
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
	std::cout << "-------------------------------------------" << "\n";

	// Printing the elements
	std::cout << "\n------------------Elements-----------------" << "\n";
	for(int j=1; j<=nelements; j++){
		if(element_family=="Lagrange"){
			Lagrange element = lagrangian.get_entity(j);
			std::cout << "(global idx=" << element.get_index() << ")   ";
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
			std::cout << "\n                  ";
			std::cout << "G = (" << element.get_shape().get_G().get_x() << ", " << element.get_shape().get_G().get_y() << ")";
			std::cout << "\n                  ";
			std::cout << "area = " << element.get_shape().get_area();
			std::cout << "\n";
		}
		else if(element_family=="Nedelec"){
			//
		}
		else{
			//
		}
	}
	std::cout << "-------------------------------------------" << "\n";

	// Printing the nodes
	std::cout << "\n--------------------Nodes------------------" << "\n";
	for(int j=0; j<nodes.get_length(); j++){
		Point node = nodes.get_entity(j,true);
		std::cout << "(global idx=" << node.get_index() << ")   ";
		switch(dimension){
			// Print coordinates according to the spatial dimension of the domain
			case 1:
			std::cout << "x=" << node.get_x() << "\n";
			break;

			case 2:
			std::cout << "x=" << node.get_x() << ", " << "y=" << node.get_y() << "\n";
			break;

			case 3:
			std::cout << "x=" << node.get_x() << ", " << "y=" << node.get_y() << ", " << "z=" << node.get_z() << "\n";
			break;
		}
	}
	std::cout << "------------------------------------" << "\n";

	// Printing the DOFs
	std::cout << "\n--------------------DOFs-------------------" << "\n";
	for(int j=0; j<ndofs; j++){
		DOF dof = dofs.get_entity(j,true);
		std::cout << "(global idx=" << dof.get_index() << ")   ";
		std::vector<int> dof_support = dof.get_supp();
		int local_node_idx=1;
		for(int k=0; k<dof_support.size(); k++){
			std::cout << "e" << local_node_idx << "=" << dof_support[k] << ", ";
			local_node_idx++;
		}
		std::cout << "\n";
	}
	std::cout << "-------------------------------------------" << "\n";

	// Printing the boundary nodes
	std::cout << "\n---------------Boundary Nodes--------------" << "\n";
	for(int j=1; j<=boundary_nodes.get_largest_index(); j++){
		try{
			// Get boundary node stored at index j
			Point node = boundary_nodes.get_entity(j);
			std::cout << "(global idx=" << node.get_index() << ")   " << "Label=" << node.get_BClabel() << ",   BC=" << node.get_BCvalue() << "\n";
		}
		catch(const std::invalid_argument& stod_exception){
			// ... unless there is no boundary node for that index, in that case just skip through
		}
	}
	std::cout << "-------------------------------------------" << "\n";

	// Printing the edges
	std::cout << "\n--------------------Edges------------------" << "\n";
	for(int j=1; j<=edges.get_length(); j++){
		Line edge = edges.get_entity(j);
		std::cout << "(global idx=" << edge.get_index() << ")   ";
		std::cout << "initial point = " << edge.get_initial().get_index() <<  ", " << "final point = " << edge.get_final().get_index() << "\n";
	}
	std::cout << "-------------------------------------------" << "\n";

	std::cout << "\n\n ****  END MESH INFORMATION  ****" << "\n\n\n";
}

void Mesh::write_mesh(){
	// TO BE WRITTEN LATER
}

void Mesh::assemble(double arg_temp, double arg_diff, double arg_adv, double arg_reac){
	// Initialise the size of the linear system
	A.resize(ndofs, ndofs);
	Ag.resize(ndofs, nBCs);
	b.resize(ndofs);
	g.resize(nBCs);

	std::cout << A.size() << "\n";
	
	if(arg_temp!=0.0){
		M.resize(ndofs, ndofs);
	}

	if(element_family=="Lagrange"){
		for(auto element : lagrangian.get_list()){
			for(auto dof_trial : element.get_dofs().get_list()){
				// Get local and global indices of the trial function
				int j = dof_trial.get_local_index();
				int jg = dof_trial.get_index();
				// Assemble the stiffness matrix (A)
				for(auto dof_test : element.get_dofs().get_list()){
					// Get local and global indices of the test function
					int k = dof_test.get_local_index();
					int kg = dof_test.get_index();
					A(jg,kg) += arg_diff*0.0 + 
								arg_adv*0.0 +
								arg_reac*0.0; // TO BE WRITTEN LATER
				}
			}
			for(int trial=0; trial<element.get_nodes().get_length(); trial++){
				// Get local and global indices of the trial function
				int j = trial+1;
				int jg = element.get_nodes().get_entity(trial,true).get_index();
				if(element.get_nodes().get_entity(trial,true).get_dof()){
					// Assemble the source vector (b)
					b(jg) += 0.0; // TO BE WRITTEN LATER
				}
				else{
					for(int test=0; test<element.get_nodes().get_length(); test++){
						// Get local and global indices of the test function
						int k = test+1;
						int kg = element.get_nodes().get_entity(test,true).get_index();
						if(!element.get_nodes().get_entity(test,true).get_dof()){
							// Assemble the boundary matrix (Ag), boundary vector (g) and source vector
							Ag(jg,kg) += arg_diff*0.0 + 
										 arg_adv*0.0 +
										 arg_reac*0.0; // TO BE WRITTEN LATER
							g(jg) += 0.0; // TO BE WRITTEN LATER
						}
					}
				}
			}
		}
	}
	else if(element_family=="Nedelec"){
		// TO BE WRITTEN LATER
	}

	// Reduce the linear system to the form Ax=b
	b = b - Ag*g;
}


// OVERLOADED METHODS


void Mesh::process(){/*  */};

void Mesh::build_dofs(){/*  */};


// METHODS TO BE INHERITED


void Mesh::init(std::string* arg_family, int* arg_order){
	// Initialises the fundamental information about the mesh as provided by the input raw mesh
	dimension = nodes.get_entity(1).get_dimension(); 
	element_type = elements.get_entity(1).get_shape().get_type();
	
	nnodes = nodes.get_length()+1;
	ndofs = dofs.get_length();
	nedges = edges.get_length();
	nfaces = faces.get_length();
	nelements = elements.get_length();
	
	// Initialises the custom information about the mesh as provided by the user
	element_family = *arg_family;
	polynomial_order = *arg_order;
	geometrical_order = elements.get_entity(1).get_curve_order();
}

// PRIVATE METHODS