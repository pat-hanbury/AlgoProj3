//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//header grid.h

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
#include <vector>

//class grid declaration
class grid{
//private variables
private:
	//initializes numberofrows and numberofcolumns
	int NumberOfRows, NumberOfColumns;
	//vector to store the characters found in the grid
	std::vector < std::vector<char> > letters;

//public variables	
public:
	//functions to return their respective private member
	int getRows();
	int getColumns();
	//function to return the character at a location
	char location(int, int);
	//function that strings from the text file
	void readGrid(std::string);	
};

#endif
