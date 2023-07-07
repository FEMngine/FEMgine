#include "Point.h"


// CONSTRUCTORS & DESTRUCTORS


Point::Point(): Entity(){
	// Default constructor
}

Point::Point(int arg_global_index): Entity(arg_global_index){
	// Parametric constructor
	bool dof = false;
}

Point::Point(int arg_global_index, double arg_x): Entity(arg_global_index){
	// Parametric constructor
	dimension = 1;
	coord_x = arg_x;
}

Point::Point(int arg_global_index, double arg_x, double arg_y): Entity(arg_global_index){
	// Parametric constructor
	dimension = 2;
	coord_x = arg_x;
	coord_y = arg_y;
}

Point::Point(int arg_global_index, double arg_x, double arg_y, double arg_z): Entity(arg_global_index){
	// Parametric constructor
	dimension = 3;
	coord_x = arg_x;
	coord_y = arg_y;
	coord_z = arg_z;
}


// ACCESSORS


double Point::get_x(){
	return coord_x;
}


double Point::get_y(){
	return coord_y;
}


double Point::get_z(){
	return coord_z;
}


int Point::get_BClabel(){
	return boundary_label;
}


double Point::get_BCvalue(){
	return boundary_condition;
}


// OTHER METHODS


void Point::set_x(double arg_x){
	coord_x = arg_x;
}

void Point::set_y(double arg_y){
	coord_y = arg_y;
}

void Point::set_z(double arg_z){
	coord_z = arg_z;
}

bool Point::is_dof(){
	return dof;
}


void Point::set_BClabel(int arg_BClabel){
	boundary_label = arg_BClabel;
}


void Point::set_BCvalue(double arg_BCvalue){
	boundary_condition = arg_BCvalue;
}


// OVERLOADED METHODS

// PRIVATE METHODS