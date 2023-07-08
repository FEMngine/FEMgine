#include "../../utilities/interface/GidReader.h"

int main(int argc, char* argv[]){
	// Define the family of Finite Elements to be used (DOFs)
	std::string family = "Lagrange"; 
	// Define the polynomial order of the approximation subspace
	int order = 1;

	// Read the raw mesh and process it
	GidReader gid("triangle_linear.txt");
	gid.process(family, order);

	// Impose the BCs
	gid.apply_BC(0, 10.5);
	gid.apply_BC(1, 5.3);
	gid.apply_BC(2, 3.1, "NEU");

	// Print the mesh (debug purposes)
	gid.print_mesh();

	// Define the PDE
	double α = 0.0; // Temporal coefficient
	double β = 1.0; // Diffusion coefficient
	double γ = 1.0; // Advection coefficient
	double δ = 1.0; // Reaction coefficient

	// Assemble the linear system
	gid.assemble(α, β, γ, δ);

	return 0;
}