#include "EntityList.h"


// CONSTRUCTORS & DESTRUCTORS


template <class GeometryType>
EntityList<GeometryType>::EntityList(){
	// Default constructor with later explicit instantiation
}

template <class GeometryType>
EntityList<GeometryType>::EntityList(int arg_length){
	// Parametric constructor
	length = arg_length;
}


// ACCESSORS


template <class GeometryType>
int EntityList<GeometryType>::get_length(){
	return length;
}

template <class GeometryType>
int EntityList<GeometryType>::get_largest_index(){
	// Initialise the largest index
	int largest_index = 0;
	// Loop over the entities to find the one with the largest index
	for(auto entity : entity_list){
		if(entity.get_index()>largest_index){
			largest_index = entity.get_index();
		}
	}

	return largest_index;
}

template <class GeometryType>
GeometryType EntityList<GeometryType>::get_entity(int arg_index){
	for(auto entity : entity_list){
		if(arg_index==entity.get_index()){
			return entity;
		}
	}
	// If control reaches the end of the loop throw an exception  
	throw std::invalid_argument("There is no entity at specified index");
}

template <class GeometryType>
GeometryType EntityList<GeometryType>::get_head(){
	return entity_list[0];
}

template <class GeometryType>
GeometryType EntityList<GeometryType>::get_tail(){
	return entity_list[length-1];
}


// OTHER METHODS


template <class GeometryType>
void EntityList<GeometryType>::add_entity(GeometryType arg_entity){
	entity_list.push_back(arg_entity);
	length++;
}


// OVERLOADED METHODS

// PRIVATE METHODS

// EXPLICIT INSTANTIATION OF TEMPLATISED CLASS' CONSTRUCTOR
template class EntityList<Point>;
template class EntityList<Element>;
