// PRIVATE HEADER
#pragma once

// Base class header
#include "../../src/geometry/Point.h"

class DOF: public Point{
public:
	// Default constructor
	DOF();
	// Other constructors
	// Copy constructor
	DOF(Point &copy_point);
	// Destructor
	~DOF() = default;

	// Accessors
	double get_f();
	double get_Fx();
	double get_Fy();
	double get_Fz();
	std::vector<double> get_F();
	// Other methods
	void update(double arg_Fx, double arg_Fy=std::numeric_limits<double>::epsilon(), double arg_Fz=std::numeric_limits<double>::epsilon());

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	double f_value;
	double Fx_value;
	double Fz_value;
	double Fy_value;
	std::vector<double> F_value;
	// Private methods
};