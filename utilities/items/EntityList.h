// PRIVATE HEADER
#pragma once

#include "FEMgine.h"

template <class EntityType>
class EntityList{
public:
	// Default constructor
	EntityList();
	// Other constructors
	EntityList(int arg_length);
	// Destructor
	~EntityList() = default;

	// Special method (makes the class compatible with range-based for-loops)
	std::vector<EntityType> get_list();
	// Accessors
	int get_length();
	int get_largest_index();
	EntityType get_entity(int arg_index, bool local=false);
	EntityType get_head();
	EntityType get_tail();
	// Other methods
	void clear();
	void pop(int arg_index);
	void add_entity(EntityType arg_entity);
	bool it_exists(EntityType* arg_entity);
	void insert(int arg_index, EntityType arg_entity);
	void swap(std::vector<EntityType> arg_entity_list);
	void fill_in(EntityList<EntityType>* arg_newlist);

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	int length = 0;
	std::vector<EntityType> entity_list;
	// Private methods
};