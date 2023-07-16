// PRIVATE HEADER
#pragma once

#include "../geometry/Point.h"
#include "../../utilities/items/Entity.h"
#include "../../utilities/items/EntityList.h"

class Line: public Entity{
public:
	// Default constructor
	Line();
	// Other constructors
	Line(Point arg_initial, Point arg_final);
	// Destructor
	~Line() = default;

	// Accessors
	Point get_initial();
	Point get_final();
	// Other methods
	void set_global_index(int arg_global_index);

protected:
	// Attributes to be inherited
	// Overloaded methods

private:
	// Attributes
	int length;
	Point initialPoint;
	Point finalPoint;
	EntityList<Point> midPoints; // use add_entity();
	// Private methods
};