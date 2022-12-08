// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../../utilities/items/EntityList.h"

class Mesh{
public:
	// Default constructor
	Mesh();
	// Destructor
	~Mesh() = default;

	// Accessors
	// Other methods
	virtual void print_mesh();

protected:
	// Attributes to be inherited
	EntityList<Point> inner_nodes;
	EntityList<Element> elements;
	EntityList<Point> boundary_nodes;
	// Overloaded methods

private:
	// Attributes
	// Private methods
};