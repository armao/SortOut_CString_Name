#include <iostream>
#include"nameutils.h"

int main(int argc, char* argv[])
{
	std::cout<<"[SpaceCheck]" << argv[1] << "[SpaceCheck]" << std::endl;
	nameutile::capitalize(argv[1]);
	nameutile::trim_midle_names(argv[1]);
	std::cout << std::endl;
	std::cout << "[SpaceCheck]" << argv[1] << "[SpaceCheck]" << std::endl;
}

