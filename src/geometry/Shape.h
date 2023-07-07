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
	std::string get_type();
	Point get_G();
	double get_area();
	// Other methods
	void init_type(std::string arg_type, EntityList<Point>* arg_nodes);
	matrix<int> sort_edges(EntityList<Point>* arg_nodes);

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	Point centroid;
	double area;
	std::string type;
	std::vector<std::string> shapes = {"Triangle", "Tetrahedron", "Quadrilateral", "Hexahedron"};
	// Private methods
};