#include "Point.h"


// CONSTRUCTORS & DESTRUCTORS


Point::Point(){
	// Default constructor
}

Point::Point(int arg_global_index){
	// Parametric constructor
	global_index = arg_global_index;

	bool dof = false;
}

Point::Point(int arg_global_index, double arg_x){
	// Parametric constructor
	global_index = arg_global_index;
	
	coord_x = arg_x;
	
	dimension = 1;
}

Point::Point(int arg_global_index, double arg_x, double arg_y){
	// Parametric constructor
	global_index = arg_global_index;
	
	coord_x = arg_x;
	coord_y = arg_y;

	dimension = 2;
}

Point::Point(int arg_global_index, double arg_x, double arg_y, double arg_z){
	// Parametric constructor
	global_index = arg_global_index;
	
	coord_x = arg_x;
	coord_y = arg_y;
	coord_z = arg_z;

	dimension = 3;
}


// ACCESSORS


int Point::get_index(){
	return global_index;
}


int Point::get_dimension(){
	return dimension;
}


double Point::get_x(){
	return coord_x;
}


double Point::get_y(){
	return coord_y;
}


double Point::get_z(){
	return coord_z;
}


double Point::get_BC(){
	return boundary_condition;
}


// OTHER METHODS


bool Point::is_dof(){
	return dof;
}


void Point::set_BC(double arg_BC){
	boundary_condition = arg_BC;
}


// OVERLOADED METHODS

// PRIVATE METHODS