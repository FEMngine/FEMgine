#include "Nedelec.h"


// CONSTRUCTORS & DESTRUCTORS


Nedelec::Nedelec(): Element(){
	// Default constructor
}

Nedelec::Nedelec(Element &copy_element, std::string* arg_family, int* arg_order): Element(copy_element){
	// Copy constructor
	family = *arg_family;
	polynomial_order = *arg_order;
}


// ACCESSORS


// OTHER METHODS


// OVERLOADED METHODS


// PRIVATE METHODS