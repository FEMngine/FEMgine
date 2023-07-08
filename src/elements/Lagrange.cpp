#include "Lagrange.h"


// CONSTRUCTORS & DESTRUCTORS


Lagrange::Lagrange(): Element(){
	// Default constructor
}

Lagrange::Lagrange(Element &copy_element, EntityList<Point> arg_nodes, std::string* arg_family, int* arg_order): Element(copy_element){
	// Copy constructor
	nodes = arg_nodes;
	edges = copy_element.get_edges();

	dimension = nodes.get_head().get_dimension();
	type.init_type(copy_element.get_shape().get_type(), &nodes);

	family = *arg_family;
	polynomial_order = *arg_order;
	curvilinear_order = 1;

	init_dofs();
}


// ACCESSORS


EntityList<DOF> Lagrange::get_dofs(){
	return dofs;
}


// OTHER METHODS


// OVERLOADED METHODS


// PRIVATE METHODS


void Lagrange::init_dofs(){
	if(polynomial_order==1){
		for(int j=0; j<nodes.get_length(); j++){
			Point node = nodes.get_entity(j,true);
			if(node.get_dof()){
				dofs.add_entity(DOF(node));
			}
		}
	}
	else if(polynomial_order==2){
		//
	}
	else if(polynomial_order==3){
		//
	}
	else{
		//
	}
}