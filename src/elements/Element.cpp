#include "Element.h"


// CONSTRUCTORS & DESTRUCTORS


Element::Element(){
	// Default constructor
	type = "2-simplex";
	family = "Lagrange";
	polynomial_order = 1;
}

Element::Element(int arg_index, std::vector<Point> arg_nodes){
	// Parametric constructor
	index = arg_index;

	for(auto node : arg_nodes){
		nodes.push_back(node);
	}

	type = "2-simplex";
	family = "Lagrange";
	polynomial_order = 1;
}


// ACCESSORS


int Element::get_index(){
	return index;
}

std::string Element::get_type(){
	return type;
}

std::string Element::get_family(){
	return family;
}

int Element::get_poly_order(){
	return polynomial_order;
}

std::vector<Point> Element::get_nodes(){
	return nodes;
}


// OTHER METHODS


// OVERLOADED METHODS


// PRIVATE METHODS