#include "../../utilities/interface/GidReader.h"

int main(int argc, char* argv[]){
	GidReader gid("mesh.txt");
	
	gid.read_list();
	gid.print_mesh();

	return 0;
}