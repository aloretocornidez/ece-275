#ifndef HAVEYOUSEENTHSISNAIL_BOARD
#define HAVEYOUSEENTHSISNAIL_BOARD

#include "Cell.hpp"
#include "Gary.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

typedef std::vector< std::vector<Cell> > matrix;

class Board {
public:
	//Contructors
	Board(int size) {
		//Set Dimensions of the keyboard
		dimensions(size);
		//Set a Default filename
		fileName = "output.txt";
		
		//Set up the cell map
		setCells();

		//Setup of Our snail
		snail.setGaryPosition(this->rows, this->columns);
	}
	//Destructor
	~Board() {
		myFile.close();
	}

	//Functions

	void move_gary(int steps) {
		//Begin moving the steps.
		for (int i = 0; i <= steps; i++) {

			//Print the output of cells to the console and file.
			printCells();

			if (i < steps) {
				snail.move(&cellMap[snail.get_row()][snail.get_col()]);
			}
		}
	}

	void dimensions(int size) {
		//Check statement to make sure board has odd side length.
		if (size % 2 == 0) {
			std::cout << "Board dimension must be an odd number!! Got " << size <<
				" and adding 1 to equal " << size + 1 << std::endl;
			size++;
		}
		rows = size;
		columns = size;
	}

	void setCells() {
		cellMap.resize(0);
		cellMap.resize(rows);
		for (unsigned int i = 0; i < rows; i++) {
			cellMap[i].resize(columns);
		}

		for (unsigned int i = 0; i < rows; i++) {
			for (unsigned int k = 0; k < columns; k++) {
				cellMap[i][k].setCoords(i, k, columns);
			}
		}
	}

	void printCells() {

		//Printing to the console
		std::cout << "[Gary Location] {" << snail.get_row() << ", " << snail.get_col() <<
			"} [Gary Orientation] " << snail.get_orientation_string() << " ";

		//Printing to the file
		this->myFile << "[Gary Location] {" << snail.get_row() << ", " << snail.get_col() <<
			"} [Gary Orientation] " << snail.get_orientation_string() << " ";


		for (unsigned int i = 0; i < rows; i++) {
			std::cout << "[Row " << i << "] ";
			this->myFile << "[Row " << i << "] ";

			for (unsigned int j = 0; j < columns; j++) {
				std::cout << cellMap[i][j].get_color_string() << " ";
				this->myFile << cellMap[i][j].get_color_string() << " ";
			}
		}
		std::cout << std::endl;
		this->myFile << std::endl;

	}

	void setOutputFilename(std::string input) {
		fileName = input;
		myFile.open(fileName, std::ios_base::trunc);
	}

	//Getter Functions
	int getRows() {
		//std::cout << "Rows: " << rows << std::endl;
		return rows; 
	}
	int getColumns() {
		//std::cout << "Columns: " << columns << std::endl;
		return columns;
	}
	std::string getFilename() { 
		//std::cout << "fileName: " << fileName << std::endl;
		return fileName; }

private:
	unsigned int rows;
	unsigned int columns;
	std::string fileName;
	matrix cellMap;
	Gary snail;
	std::ofstream myFile;
};

#endif