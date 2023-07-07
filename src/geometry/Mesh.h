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

	void assemble(double arg_temp, double arg_diff, double arg_adv, double arg_reac);

protected:
	// Attributes to be inherited
	EntityList<Point>   inner_nodes;
	EntityList<Point>   boundary_nodes;
	EntityList<DOF>     dofs;

	EntityList<Line>    edges;
	EntityList<Surface> faces;

	EntityList<Element>  elements;
	EntityList<Lagrange> lagrangian;
	EntityList<Nedelec>  curl_conf;

	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Stif;
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Mass;
	Eigen::Vector<double, Eigen::Dynamic> Source;
	Eigen::Vector<double, Eigen::Dynamic> BCs;

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
	int nBCs;
	int nelements;
	int nedges;
	int nfaces;
	int polynomial_order;
	int geometrical_order;
	std::string element_type;
	std::string element_family; 
	// Private methods
};