//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//wordlist.h

#ifndef WORDLIST_H
#define WORDLIST_H

#include <iostream>
#include <istream>
#include <cstdlib>
#include <vector>
#include <string>
#include "hashTable.h"

//class wordList declaration
class wordList {
public:
	//creates a string to store the words
	std::vector<std::string> list; 
	//initializes the variables necessary for partition
	int partition(int, int); 
	
	//void function that reads words from the wordlist file
	void readWords();
	
	//bool functions for the binary searches
	bool binarySearch(std::string &);
	bool binarySearchAux(std::string &key, int left, int right); 
	
	//overloaded operator, that prints every item in the list
	friend std::ostream& operator << (std::ostream&, wordList &); 
	
	//void functions for all the sorts
	void mergeSort(int, int); 
	void insertionSort(); 
	void quickSort(int, int);
	void merge(int, int , int); 
	
	//newly added
	void heapSort();
};

#endif
