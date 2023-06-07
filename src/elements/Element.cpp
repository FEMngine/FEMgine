#include "Element.h"


// CONSTRUCTORS & DESTRUCTORS


Element::Element(): Entity(){
	// Default constructor
	dimension = 2;
	type.init_shape("Triangles");
	curvilinear_order = 1;
}

Element::Element(int arg_global_index, std::vector<Point> arg_nodes): Entity(arg_global_index){
	// Parametric constructor
	for(auto node : arg_nodes){
		nodes.add_entity(node);
	}

	dimension = nodes.get_head().get_dimension();
	curvilinear_order = 1;

	// Determine the shape of the element
	infere_type();

	// Determine the local edges and faces of the element
	init_edges();
	init_faces();
}

Element::Element(Element &copy_element, EntityList<Line> arg_edges): Entity(copy_element.get_index()){
	// Copy constructor
	nodes = copy_element.get_nodes();
	edges = arg_edges;

	dimension = nodes.get_head().get_dimension();
	
	type.init_shape(copy_element.get_type());
	family = copy_element.get_family();

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
		//std::cout << edges.get_length() << "\n";
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

void Element::infere_type(){
	if(dimension==2){
		if(nodes.get_length()==3){
			type.init_shape("Triangle");
		}
		else if(nodes.get_length()==4){
			type.init_shape("Quadrilateral");
		}
	}
	else if(dimension==3){
		//
	}
}