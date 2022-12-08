// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../geometry/Point.h"

class Element{
public:
	// Default constructor
	Element();
	// Other constructors
	Element(int arg_index, std::vector<Point> arg_nodes);
	// Destructor
	~Element() = default;

	// Accessors
	int get_index();
	std::string get_type();
	std::string get_family();
	int get_poly_order();
	std::vector<Point> get_nodes();
	// Other methods;

protected:
	// Attributes to be inherited
	// Overloaded methods;

private:
	// Attributes
	int index;
	std::string type;
	std::string family;
	int polynomial_order;
	std::vector<Point> nodes;
	// Private methods;
};