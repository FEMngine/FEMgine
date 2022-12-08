// PRIVATE HEADER
#pragma once

#include "tools.h"

class ClassName{
public:
	// Default constructor
	ClassName();
	// Other constructors
	ClassName(std::string arg_line);
	// Destructor
	~ClassName() = default;

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