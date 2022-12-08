#include "MeshReader.h"


// CONSTRUCTORS & DESTRUCTORS


MeshReader::MeshReader(): Mesh(){
	// Default constructor
	std::cout << "Provide filename: ";
	std::string arg_filename;
	std::cin >> arg_filename;

	set_filename(arg_filename);
}

MeshReader::MeshReader(std::string arg_filename): Mesh(){
	// Parametric constructor
	filename = arg_filename;
}


// ACCESSORS


std::string MeshReader::get_filename(){
	return filename;
}


std::streampos MeshReader::get_beginning_position(){
	return beginning_position;
}


std::streampos MeshReader::get_end_position(){
	return end_position;
}


// OTHER METHODS


void MeshReader::read_list(){/*  */}


// OVERLOADED METHODS


void MeshReader::set_endlines(){/*  */}

void MeshReader::set_position(){/*  */}

void MeshReader::format_entity(int arg_entity_list_index){/*  */}


// PRIVATE METHODS


void MeshReader::set_filename(std::string arg_filename){
	filename = arg_filename;
}