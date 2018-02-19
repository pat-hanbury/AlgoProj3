//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//class grid.cpp

#include "grid.h"
#include "wordList.h"

//function to rturn the numberofrows
int grid::getRows(){
	return NumberOfRows;
}

//function to return the numberofcolumns
int grid::getColumns() {
	return NumberOfColumns;
}

//Function location that access characters in the RXC location
char grid::location(int row, int column){
	return letters[row].at(column);
}

//function that reads the letters in the grid from the text file.
void grid::readGrid(std::string filename){
	//ifstream variable to read files
	std::ifstream fin;
	//vector that stores a row
	std::vector<char> storeRow;
	//variable to store the letter 
	char storeLetter;
	//Open the the text file
	fin.open(filename);
	
	//If statement that checks if the file is there or not
	//Outputs a message if file is not there
	if (!fin){
		std::cout << "Can not find file";
		system("pause");
		exit(0);
	}
	
	//Storing the numberofrows and numberofcolumns
	fin >> NumberOfRows >> NumberOfColumns;
	
	//for statement that iterates through the rows
	for (int i=0; i < NumberOfRows; i++){
		//for statement that iterates through the columns
		for (int i=0; i < NumberOfColumns; i++){
			//sstores the letter
			fin >> storeLetter;
			//increases the size of the vector that stores the row
			storeRow.push_back(storeLetter);
			}
			//stores the entire row into letters
			letters.push_back(storeRow);
			//resizes the vector that stores the row
			storeRow.resize(0);
	}
	//cloes the text file
	fin.close();
	
}
