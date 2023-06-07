// PRIVATE HEADER
#pragma once

// Base class header
#include "Element.h"

class Nedelec: public Element{
public:
	// Default constructor
	Nedelec();
	// Other constructors
	// Copy constructor
	Nedelec(Element &copy_element, std::string* arg_family, int* arg_order);
	// Destructor
	~Nedelec() = default;

	// Accessors
	// Other methods

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	// Private methods
};