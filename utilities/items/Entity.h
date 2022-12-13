// PRIVATE HEADER
#pragma once

#include "tools.h"

class Entity{
public:
	// Default constructor
	Entity();
	// Other constructors
	Entity(int arg_global_index);
	// Destructor
	~Entity() = default;

	// Accessors
	int get_index();
	int get_dimension();
	// Other methods

protected:
	// Attributes to be inherited
	int global_index;
	int dimension;
	// Overloaded methods

private:
	// Attributes
	// Private methods
};