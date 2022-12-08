// PRIVATE HEADER
#pragma once

#include "tools.h"

class Volume{
public:
	// Default constructor
	Volume();
	// Other constructors
	Volume(std::string arg_line);
	// Destructor
	~Volume() = default;

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