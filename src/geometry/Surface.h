// PRIVATE HEADER
#pragma once

#include "../../utilities/items/Entity.h"
#include "../../utilities/items/EntityList.h"

class Surface: public Entity{
public:
	// Default constructor
	Surface();
	// Other constructors
	Surface(int arg_global_index);
	// Destructor
	~Surface() = default;

	// Accessors
	// Other methods

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	// Private methods
};