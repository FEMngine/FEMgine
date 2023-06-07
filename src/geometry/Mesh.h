// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../../utilities/items/EntityList.h"
#include "../../utilities/items/DOF.h"
#include "../../src/geometry/Point.h"
#include "../../src/geometry/Line.h"
#include "../../src/geometry/Surface.h"
#include "../../src/elements/Lagrange.h"
#include "../../src/elements/Nedelec.h"

class Mesh{
public:
	// Default constructor
	Mesh();
	// Destructor
	~Mesh() = default;

	// Accessors
	// Other methods
	void print_mesh();
	void write_mesh();

protected:
	// Attributes to be inherited
	EntityList<Point>   inner_nodes;
	EntityList<Point>   boundary_nodes;
	EntityList<DOF>     dofs;

	EntityList<Line>    edges;
	EntityList<Surface> faces;

	EntityList<Element> elements;
	EntityList<Lagrange> Lelements;
	EntityList<Nedelec>  Nelements;
	// Overloaded methods
	virtual void process();
	virtual void build_dofs();
	// Methods to be inherited
	void init(std::string* arg_family, int* arg_order);

private:
	// Attributes
	int dimension;
	int nnodes;
	int ndofs;
	int nelements;
	int nedges;
	int nfaces;
	int polynomial_order;
	std::string element_type;
	std::string element_family; 
	// Private methods
};