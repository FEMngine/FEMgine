#include "DOF.h"


// CONSTRUCTORS & DESTRUCTORS


DOF::DOF(): Point(){
	// Default constructor
}

DOF::DOF(Point &copy_point, int arg_local_index): Point(){
	// Copy constructor
	global_index = copy_point.get_index();
	dimension = copy_point.get_dimension();

	coord_x = copy_point.get_x();
	coord_y = copy_point.get_y();
	coord_z = copy_point.get_z();

	local_index = arg_local_index;
}


// ACCESSORS


double DOF::get_f(){
	return f_value;
}

double DOF::get_Fx(){
	return Fx_value;
}

double DOF::get_Fy(){
	return Fy_value;
}

double DOF::get_Fz(){
	return Fz_value;
}

int DOF::get_local_index(){
	return local_index;
}

std::vector<double> DOF::get_F(){
	return F_value;
}

std::vector<int> DOF::get_supp(){
	return support;
}


// OTHER METHODS


void DOF::update(double arg_Fx, double arg_Fy, double arg_Fz){
	if(arg_Fy==std::numeric_limits<double>::epsilon() and arg_Fz==std::numeric_limits<double>::epsilon()){
		f_value = arg_Fx;
	}
	else{
		Fx_value = arg_Fx;
		Fy_value = arg_Fy;
		Fz_value = arg_Fz;

		F_value[0] = Fx_value;
		F_value[1] = Fy_value;
		F_value[2] = Fz_value;
	}
}


void DOF::update(int arg_index){
	for(int j=0; j<support.size(); j++){
		if(support[j]==arg_index){
			return;
		}
	}
	support.push_back(arg_index);
}


// OVERLOADED METHODS


// PRIVATE METHODS