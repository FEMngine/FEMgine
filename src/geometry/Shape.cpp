#include "Shape.h"


// CONSTRUCTORS & DESTRUCTORS


Shape::Shape(){
	// Default constructor
}


// ACCESSORS


std::string Shape::get_shape(){
	return shape;
}

void Shape::init_shape(std::string arg_shape){
	shape = arg_shape;
}

matrix<int> Shape::sort_edges(EntityList<Point>* arg_nodes){
	int it;
	for(it=0; it<4; it++){
		if(shape==shape_list[it]){
			break;
		}
	}

	std::vector<int> node_couple;
	matrix<int> iterable_nodes;
	switch(it){
		// Hard-coded (needs refactoring)

		case(0): // Triangles
		node_couple.push_back(arg_nodes -> get_entity(0, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(1, true).get_index());
		iterable_nodes.push_back(node_couple);

		node_couple.erase(node_couple.begin(), node_couple.end());

		node_couple.push_back(arg_nodes -> get_entity(1, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(2, true).get_index());
		iterable_nodes.push_back(node_couple);

		node_couple.erase(node_couple.begin(), node_couple.end());

		node_couple.push_back(arg_nodes -> get_entity(2, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(0, true).get_index());
		iterable_nodes.push_back(node_couple);
		break;

		case(1): // Tetrahedra
		break;

		case(2): // Quadrilaterals
		break;

		case(3): // Hexahedra
		break;
	}

	return iterable_nodes;
}

matrix<int> Shape::sort_faces(){
	matrix<int> iterable_nodes;
	return iterable_nodes;
}


// OTHER METHODS

// OVERLOADED METHODS

// PRIVATE METHODS