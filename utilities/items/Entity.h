// PRIVATE HEADER
#pragma once

#include "tools.h"

class Entity{
public:
	// Default constructor
	Entity();
	// Other constructors
	Entity(std::string arg_line);
	// Destructor
	~Entity() = default;

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