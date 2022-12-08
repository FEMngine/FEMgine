// PRIVATE HEADER
#pragma once

#include "tools.h"

class Line{
public:
	// Default constructor
	Line();
	// Other constructors
	Line(std::string arg_line);
	// Destructor
	~Line() = default;

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