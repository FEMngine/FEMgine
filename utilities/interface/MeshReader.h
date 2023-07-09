// PRIVATE HEADER
#pragma once

#include "../../src/geometry/Mesh.h"

class MeshReader: public Mesh{
public:
	// Default constructor
	MeshReader();
	// Other constructors
	MeshReader(std::string arg_filename);
	// Destructor
	~MeshReader() = default;

	// Accessors
	std::string get_filename();
	std::streampos get_beginning_position();
	std::streampos get_end_position();
	// Other methods
	virtual void read_list();


protected:
	// Attributes to be inherited
	std::string filename;
	std::string listname;
	std::string readline;
	
	std::string opening_line, closing_line;
	std::streampos beginning_position, end_position;

	// Overloaded methods
	virtual void process();
	virtual void set_endlines();
	virtual void set_position();
	virtual void format_entity();
	virtual void build_missing_entity_list();

private:
	// Attributes
	// Private methods
	void set_filename(std::string arg_filename);
};