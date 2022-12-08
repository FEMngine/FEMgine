// PRIVATE HEADER
#pragma once

// Base class header
#include "MeshReader.h"

class GidReader: public MeshReader{
public:
	// Default constructor
	GidReader();
	// Other constructors
	GidReader(std::string arg_filename);
	// Destructor
	~GidReader() = default;

	// Accessors
	// Other methods
	void read_list();

private:
	// Attributes
	// Private methods
	void set_endlines();
	void set_position();
	void format_entity(int arg_entity_list_index);
};