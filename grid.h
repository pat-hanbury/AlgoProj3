//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//header grid.h

#include <iostream>
#include <fstream>
#include <vector>

//include all the header 


class grid{
	
private:
	int NumberOfRows, NumberOfColumns;
	std::vector < std::vector<char> > letters;

	
public:
	int getRows();
	int getColumns;
	char location(int, int);
	void Grid(std::string);
	
	
};
