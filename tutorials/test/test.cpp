#include "../../utilities/interface/GidReader.h"

int main(int argc, char* argv[]){
	// Define the family of Finite Elements to be used (DOFs)
	std::string family = "Lagrange"; 
	// Define the polynomial order of the approximation subspace
	int order = 1;

	// Read the raw mesh and process it
	GidReader gid("triangle_linear.txt");
	gid.read_list();
	gid.process(family, order);
	gid.print_mesh();

	// Assemble the linear system

	return 0;
}