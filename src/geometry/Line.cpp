#include "Line.h"


// CONSTRUCTORS & DESTRUCTORS


Line::Line(): Entity(){
	// Default constructor
}

Line::Line(Point arg_initial, Point arg_final): Entity(){
	// Parametric constructor
	initialPoint = arg_initial;
	finalPoint = arg_final;
}


// ACCESSORS

// OTHER METHODS


void Line::set_global_index(int arg_global_index){
	global_index = arg_global_index;
}

// OVERLOADED METHODS

// PRIVATE METHODS