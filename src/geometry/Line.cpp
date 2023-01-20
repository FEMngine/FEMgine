#include "Line.h"


// CONSTRUCTORS & DESTRUCTORS


Line::Line(): Entity(){
	// Default constructor
}

Line::Line(Point arg_initial, Point arg_final): Entity(){
	// Parametric constructor
	initialPoint = arg_initial;
	finalPoint = arg_final;

	length = sqrt(pow(finalPoint.get_x()-initialPoint.get_x(), 2.0)+(finalPoint.get_y()-initialPoint.get_y(), 2.0)+(finalPoint.get_z()-initialPoint.get_z(), 2.0));
}


// ACCESSORS


Point Line::get_initial(){
	return initialPoint;
}

Point Line::get_final(){
	return finalPoint;
}


// OTHER METHODS


void Line::set_global_index(int arg_global_index){
	global_index = arg_global_index;
}

// OVERLOADED METHODS

// PRIVATE METHODS