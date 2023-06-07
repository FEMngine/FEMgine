#include "EntityList.h"


// CONSTRUCTORS & DESTRUCTORS


template<class EntityType>
EntityList<EntityType>::EntityList(){
	// Default constructor with later explicit instantiation
}

template<class EntityType>
EntityList<EntityType>::EntityList(int arg_length){
	// Parametric constructor
	length = arg_length;
}


// SPECIAL METHODS (COMPLIANCE WITH RANGE-BASED FOR-LOOPS)


template<class EntityType>
std::vector<EntityType> EntityList<EntityType>::get_list(){
	return entity_list;
}


// ACCESSORS


template<class EntityType>
int EntityList<EntityType>::get_length(){
	return length;
}

template<class EntityType>
int EntityList<EntityType>::get_largest_index(){
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

template<class EntityType>
EntityType EntityList<EntityType>::get_entity(int arg_index, bool local){
	if(local){
		// Get the entity in the list based on the index of the vector
		int counter = 0;
		for(auto entity : entity_list){
			if(arg_index==counter){
				return entity;
			}
			counter++;
		}
		// If control reaches the end of the loop throw an exception
		throw std::invalid_argument("There is no entity at specified index");
	}
	else{
		// Get the entity in the list based on the index of the entity itself
		for(auto entity : entity_list){
			if(arg_index==entity.get_index()){
				return entity;
			}
		}
		// If control reaches the end of the loop throw an exception  
		throw std::invalid_argument("There is no entity at specified index");
	}
}

template<class EntityType>
EntityType EntityList<EntityType>::get_head(){
	return entity_list[0];
}

template<class EntityType>
EntityType EntityList<EntityType>::get_tail(){
	return entity_list[length-1];
}


// OTHER METHODS


template<class EntityType>
void EntityList<EntityType>::clear(){
	entity_list.clear();
	length = 0;
}

template<class EntityType>
void EntityList<EntityType>::pop(int arg_index){
	// TO BE WRITTEN LATER
	return;
}

template<class EntityType>
void EntityList<EntityType>::add_entity(EntityType arg_entity){
	entity_list.push_back(arg_entity);
	length++;
}

template<class EntityType>
bool EntityList<EntityType>::it_exists(EntityType* arg_entity){
	for(auto entity : entity_list){
		if(entity.get_index()==arg_entity -> get_index()){
			return true;
		}
	}
	return false;
}

template<class EntityType>
void EntityList<EntityType>::insert(int arg_index, EntityType arg_entity){
	// TO BE WRITTEN LATER
	return;
}

template<class EntityType>
void EntityList<EntityType>::swap(std::vector<EntityType> arg_entity_list){
	entity_list = arg_entity_list;
}

template<class EntityType>
void EntityList<EntityType>::fill_in(EntityList<EntityType>* arg_newlist){
	clear();
	entity_list = arg_newlist -> get_list();
	length = arg_newlist -> get_length();
}


// OVERLOADED METHODS

// PRIVATE METHODS

// EXPLICIT INSTANTIATION OF TEMPLATISED CLASS' CONSTRUCTOR


#include "../../src/geometry/Point.h"
template class EntityList<Point>;

#include "DOF.h"
template class EntityList<DOF>;

#include "../../src/geometry/Surface.h"
template class EntityList<Surface>;

#include "../../src/elements/Element.h"
template class EntityList<Element>;

#include "../../src/elements/Lagrange.h"
template class EntityList<Lagrange>;

#include "../../src/elements/Nedelec.h"
template class EntityList<Nedelec>;


// EXPLICIT (FULL) TEMPLATE SPECIALISATION 
#include "../../src/geometry/Line.h"

template<>
bool EntityList<Line>::it_exists(Line* arg_edge){
	for(auto edge : entity_list){
		if(edge.get_initial().get_index()==arg_edge -> get_initial().get_index() && edge.get_final().get_index()==arg_edge -> get_final().get_index()){
			arg_edge -> set_global_index(edge.get_index());
			return true;
		}
		else if(edge.get_initial().get_index()==arg_edge -> get_final().get_index() && edge.get_final().get_index()==arg_edge -> get_initial().get_index()){
			arg_edge -> set_global_index(-1*edge.get_index());
			return true;
		}
	}
	return false;
}

template class EntityList<Line>;