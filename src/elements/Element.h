// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../geometry/Point.h"
#include "../geometry/Line.h"
#include "../geometry/Surface.h"
#include "../geometry/Shape.h"
#include "../../utilities/items/EntityList.h"

class Element: public Entity{
public:
	// Default constructor
	Element();
	// Other constructors
	Element(int arg_global_index, std::vector<Point> arg_nodes);
	// Copy constructor
	Element(Element &copy_element, EntityList<Line> arg_edges);
	// Destructor
	~Element() = default;

	// Accessors
	std::string get_type();
	std::string get_family();
	int get_poly_order();
	int get_curve_order();
	
	EntityList<Point>   get_nodes();
	EntityList<Line>    get_edges();
	EntityList<Surface> get_faces();
	// Other methods

protected:
	// Attributes to be inherited
	Shape type;
	int curvilinear_order;

	EntityList<Point>   nodes;
	EntityList<Line>    edges;
	EntityList<Surface> faces;

	std::string family;
	int polynomial_order;
	// Overloaded methods

private:
	// Attributes
	// Private methods
	void init_edges();
	void init_faces();
	void infere_type();
};