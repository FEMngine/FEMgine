// PRIVATE HEADER
#pragma once

#include "tools.h"

class MeshWriter{
public:
	// Default constructor
	MeshWriter();
	// Other constructors
	MeshWriter(std::string arg_line);
	// Destructor
	~MeshWriter() = default;

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