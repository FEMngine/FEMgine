// PRIVATE HEADER
#pragma once

#include "../../utilities/items/DOF.h"

// Base class header
#include "Element.h"

class Lagrange: public Element{
public:
	// Default constructor
	Lagrange();
	// Other constructors
	// Copy constructor
	Lagrange(Element &copy_element, EntityList<Point> arg_nodes, std::string* arg_family, int* arg_order);
	// Destructor
	~Lagrange() = default;

	// Accessors
	EntityList<DOF> get_dofs();
	// Other methods

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	EntityList<DOF> dofs;
	// Private methods
	void init_dofs();
};