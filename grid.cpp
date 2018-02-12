//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//class grid.cpp

#include grid.h



//includeheaders

//nocomments
int grid::getRows(){
	return NumberOfRows;
}

int grid::getColumns() {
	return NumberOfColumns;
}

char grid::location(int row, int column){
	return letters[row].at(column);
}

void grid::Grid(std::string filename){
	std::ifstream fin;
	std::vector<char> storeRow;
	char storeLetter;
	fin.open(filename);
	if (!fin){
		std::cout << "Can not find file";
		system("pause");
		exit(0);
	}
	fin >> NumberOfRows >> NumberOfColumns;
	for (int i=0; i < NumberOfRows; i++){
		for (int i=0; i < numColumns; i++){
			fin >> storeLetter;
			storeRow.push_back(storeRow);
			}
			letters.push_back(storeRow);
			storeRow.resize(0);
	}
	fin.close();
	
}
