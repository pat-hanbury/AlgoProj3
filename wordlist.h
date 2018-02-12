//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//wordlist.h

#include <iostream>
#include <istream>
#include <cstdlib>
#include <vector>
#include <string>

//comments 

//da
class wordlist {
public:
	std::vector<std::string> list;  
	
	int partition(int, int); 
	void readWords();
	
	
	
	bool binarySearch(std::string &);
	bool binarySearchAux(std::string &key, int left, int right); 
	
	friend std::ostream& operator << (std::ostream&, wordList &); 
	
	void mergeSort(int, int); 
	void insertionSort(); 
	void quickSort(int, int);
	void merge(int, int , int); 

};
