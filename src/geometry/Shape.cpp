#include "Shape.h"


// CONSTRUCTORS & DESTRUCTORS


Shape::Shape(){
	// Default constructor
}


// ACCESSORS


std::string Shape::get_type(){
	return type;
}

Point Shape::get_G(){
	return centroid;
}

double Shape::get_area(){
	return area;
}


// OTHER METHODS


void Shape::init_type(std::string arg_type, EntityList<Point>* arg_nodes){
	// Initialise the type string
	type = arg_type;
	// Compute the centroid
	double Xg=0.0, Yg=0.0;
	for(int j=0; j<arg_nodes -> get_length(); j++){
		Xg += arg_nodes -> get_entity(j,true) -> get_x();
		Yg += arg_nodes -> get_entity(j,true) -> get_y();
	}
	centroid.set_x(Xg/3.0);
	centroid.set_y(Yg/3.0);
	// Compute the area (as the determinant of the three vertice's coordinates)
	area = 0.5*((arg_nodes -> get_entity(1,true) -> get_x())*(arg_nodes -> get_entity(2,true) -> get_y() - arg_nodes -> get_entity(3,true) -> get_y()) - (arg_nodes -> get_entity(1,true) -> get_y())*(arg_nodes -> get_entity(2,true) -> get_x() - arg_nodes -> get_entity(3,true) -> get_x()) + ((arg_nodes -> get_entity(2,true) -> get_x())*(arg_nodes -> get_entity(3,true) -> get_y())) - ((arg_nodes -> get_entity(3,true) -> get_x())*(arg_nodes -> get_entity(2,true) -> get_y())));
}

matrix<int> Shape::sort_edges(EntityList<Point>* arg_nodes){
	int it;
	for(it=0; it<4; it++){
		if(type==shapes[it]){
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
		node_couple.push_back(arg_nodes -> get_entity(0, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(1, true).get_index());
		iterable_nodes.push_back(node_couple);

		node_couple.erase(node_couple.begin(), node_couple.end());

		node_couple.push_back(arg_nodes -> get_entity(1, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(2, true).get_index());
		iterable_nodes.push_back(node_couple);

		node_couple.erase(node_couple.begin(), node_couple.end());

		node_couple.push_back(arg_nodes -> get_entity(2, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(3, true).get_index());
		iterable_nodes.push_back(node_couple);

		node_couple.erase(node_couple.begin(), node_couple.end());

		node_couple.push_back(arg_nodes -> get_entity(3, true).get_index());
		node_couple.push_back(arg_nodes -> get_entity(0, true).get_index());
		iterable_nodes.push_back(node_couple);
		break;

		case(3): // Hexahedra
		break;
	}

	return iterable_nodes;
}


// OTHER METHODS

// OVERLOADED METHODS

// PRIVATE METHODS