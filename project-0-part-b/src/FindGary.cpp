#include "Cell.hpp"
#include "Board.hpp"
#include "Gary.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char** argv){

	// Check that the arguments are given correctly
	if (not (argc == 3 or argc == 4)) {
		std::cerr << "Arguments invalid. Call program as ./FindGary BoardSize Steps"
				<< " or as ./FindGary BoardSize Steps OutputFilename"
				<< std::endl;
		return -1;
	}

	//Initializing main variables
	unsigned int boardSize = atoi(argv[1]);
	unsigned int numberSteps = atoi(argv[2]);
	std::string outputFileName;
	
	//Initialize the board
	Board B(boardSize);

	if (argc == 4) {
		outputFileName = argv[3];
		B.setOutputFilename(outputFileName);
		////Function to print out all cells to file
	}
	B.move_gary(numberSteps);
	
	return 0;
}
