#include "Entity.h"


// CONSTRUCTORS & DESTRUCTORS


Entity::Entity(){
	// Default constructor
}

Entity::Entity(int arg_global_index){
	// Parametric constructor
	global_index = arg_global_index;
}


// ACCESSORS


int Entity::get_index(){
	return global_index;
}

int Entity::get_dimension(){
	return dimension;
}


// OTHER METHODS

// OVERLOADED METHODS

// PRIVATE METHODS