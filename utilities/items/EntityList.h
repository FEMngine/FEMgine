// PRIVATE HEADER
#pragma once

#include "tools.h"

template <class EntityType>
class EntityList{
public:
	// Default constructor
	EntityList();
	// Other constructors
	EntityList(int arg_length);
	// Destructor
	~EntityList() = default;

	// Special methods (make the class compatible with range-based for-loops)
	std::vector<EntityType> get_list();
	// Accessors
	int get_length();
	int get_largest_index();
	EntityType get_entity(int arg_index, bool local=false);
	EntityType get_head();
	EntityType get_tail();
	// Other methods
	void add_entity(EntityType arg_entity);

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	int length = 0;
	std::vector<EntityType> entity_list;
	// Private methods
};