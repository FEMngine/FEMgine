// PRIVATE HEADER
#pragma once

#include "tools.h"
#include "../../src/geometry/Point.h"
#include "../../src/elements/Element.h"

template <class GeometryType>
class EntityList{
public:
	// Default constructor
	EntityList();
	// Other constructors
	EntityList(int arg_length);
	// Destructor
	~EntityList() = default;

	// Accessors
	int get_length();
	int get_largest_index();
	GeometryType get_entity(int arg_index);
	GeometryType get_head();
	GeometryType get_tail();
	// Other methods
	void add_entity(GeometryType arg_entity);

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	int length = 0;
	std::vector<GeometryType> entity_list;
	// Private methods
};