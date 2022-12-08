// PRIVATE HEADER
#pragma once

#include "tools.h"

class Point{
public:
	// Default constructor
	Point();
	// Other constructors
	Point(int arg_global_index);
	Point(int arg_global_index, double arg_x);
	Point(int arg_global_index, double arg_x, double arg_y);
	Point(int arg_global_index, double arg_x, double arg_y, double arg_z);
	// Destructor
	~Point() = default;

	// Accessors
	int get_dimension();
	int get_index();
	double get_x();
	double get_y();
	double get_z();
	double get_BC();
	// Other methods
	bool is_dof();
	void set_BC(double arg_BC);

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	int dimension;
	int global_index;
	double coord_x, coord_y, coord_z;

	bool dof = true;

	double boundary_condition;
	// Private methods
};