// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../../utilities/items/EntityList.h"
#include "../../src/geometry/Point.h"
#include "../../src/geometry/Line.h"
#include "../../src/geometry/Surface.h"
#include "../../src/elements/Element.h"

class Mesh{
public:
	// Default constructor
	Mesh();
	// Destructor
	~Mesh() = default;

	// Accessors
	// Other methods
	void print_mesh();

protected:
	// Attributes to be inherited
	EntityList<Point> inner_nodes;
	EntityList<Element> elements;
	EntityList<Point> boundary_nodes;
	EntityList<Line> edges;
	EntityList<Surface> faces;
	// Overloaded methods
	virtual void process();
	void init();

private:
	// Attributes
	int dimension;
	int nnodes;
	int nelements;
	int nedges;
	int nfaces;
	int polynomial_order;
	std::string element_type;
	std::string element_family; 
	// Private methods
};