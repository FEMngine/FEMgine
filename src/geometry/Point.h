// PRIVATE HEADER
#pragma once

#include "tools.h"

// Base class header
#include "../../utilities/items/Entity.h"

class Point: public Entity{
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
	double get_x();
	double get_y();
	double get_z();
	int get_BClabel();
	double get_BCvalue();
	// Other methods
	bool is_dof();
	void set_x(double arg_x);
	void set_y(double arg_y);
	void set_z(double arg_z);
	void set_BClabel(int arg_BClabel);
	void set_BCvalue(double arg_BCvalue);

protected:
	// Attributes to be inherited
	double coord_x, coord_y, coord_z;
	bool dof = true;
	int boundary_label;
	double boundary_condition;
	// Overloaded methods

private:
	// Attributes
	// Private methods
};