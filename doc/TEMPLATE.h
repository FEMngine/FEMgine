// PRIVATE HEADER
#pragma once

#include "tools.h"

class Lagrange{
public:
	// Default constructor
	Lagrange();
	// Other constructors
	Lagrange(std::string arg_line);
	// Destructor
	~Lagrange() = default;

	// Accessors
	void method_one();
	// Other methods
	void method_two();

protected:
	// Attributes to be inherited
	// Overloaded methods
	virtual void method_three();

private:
	// Attributes
	// Private methods
	void method_four();
};