#include "Element.h"


// CONSTRUCTORS & DESTRUCTORS


Element::Element(): Entity(){
	// Default constructor
	dimension = 2;
	type.init_shape("Triangles");
	family = "Lagrange";
	polynomial_order = 1;
	curvilinear_order = 1;
}

Element::Element(int arg_global_index, std::vector<Point> arg_nodes): Entity(arg_global_index){
	// Parametric constructor
	for(auto node : arg_nodes){
		nodes.add_entity(node);
	}

	// Determine the local edges and faces of the element
	type.init_shape("Triangles");
	init_edges();
	init_faces();

	dimension = nodes.get_head().get_dimension();
	
	family = "Lagrange";
	polynomial_order = 1;
	curvilinear_order = 1;
}


// ACCESSORS


std::string Element::get_type(){
	return type.get_shape();
}

std::string Element::get_family(){
	return family;
}

int Element::get_poly_order(){
	return polynomial_order;
}

int Element::get_curve_order(){
	return curvilinear_order;
}

EntityList<Point> Element::get_nodes(){
	return nodes;
}

EntityList<Line> Element::get_edges(){
	return edges;
}

EntityList<Surface> Element::get_faces(){
	return faces;
}

// OTHER METHODS


// OVERLOADED METHODS


// PRIVATE METHODS


void Element::init_edges(){
	if(dimension < 2){
		return;
	}
	else
	{
		matrix<int> iterable_nodes = type.sort_edges(&nodes);
		for(int row=0; row<iterable_nodes.size(); row++){
			Line edge(nodes.get_entity(iterable_nodes[row][0]), nodes.get_entity(iterable_nodes[row][1]));
			edges.add_entity(edge);
		}
		return;
	}
}

void Element::init_faces(){
	if(dimension < 3){
		return;
	}
	else
	{
		return;
	}
}