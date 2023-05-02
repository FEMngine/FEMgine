#include "../../utilities/interface/GidReader.h"

int main(int argc, char* argv[]){
	GidReader gid("triangle_linear.txt");
	
	gid.read_list();
	gid.process();
	gid.print_mesh();

	return 0;
}