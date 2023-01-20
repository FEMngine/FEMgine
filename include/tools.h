// PUBLIC HEADER
#pragma once

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>


// ALIAS TEMPLATES


template<typename NumberType>
using matrix = std::vector<std::vector<NumberType>>;


//  PRINTING ROUTINES


template<typename NumberType>
void print(std::vector<NumberType>* ptr_arg_vector){
	for(int j=0; j < ptr_arg_vector -> size(); j++){
		std::cout << "[j=" << j+1 << "]  " << ptr_arg_vector -> at(j) << "\n";
	}
}

template<typename NumberType>
void print(matrix<NumberType>* ptr_arg_matrix){
	for(int j=0; j < ptr_arg_matrix -> size(); j++){
		std::cout << "Row = " << j+1 << "\n";
		for(int k=0; k < ptr_arg_matrix -> at(j).size(); k++){
			std::cout << "  Column = " << k+1 << ": " << ptr_arg_matrix -> at(j).at(k) << "\n";
		}
	}
}