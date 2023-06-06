// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../geometry/Point.h"
#include "../../utilities/items/EntityList.h"

class Shape{
public:
	// Default constructor
	Shape();
	// Destructor
	~Shape() = default;

	// Accessors
	std::string get_shape();
	// Other methods
	void init_shape(std::string arg_shape);
	matrix<int> sort_edges(EntityList<Point>* arg_nodes);
	matrix<int> sort_faces();

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	std::string shape;
	std::vector<std::string> shape_list = {"Triangle", "Tetrahedron", "Quadrilateral", "Hexahedron"};
	// Private methods
};