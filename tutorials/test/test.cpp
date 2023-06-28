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

	// Define the PDE
	double alpha = 0.0; // Temporal coefficient
	double beta  = 1.0; // Diffusion coefficient
	double gamma = 1.0; // Advection coefficient
	double delta = 1.0; // Reaction coefficient

	// Assemble the linear system

	return 0;
}