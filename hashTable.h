//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3b
//hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>
#include <vector>
#include <math.h>

//hashTable template declarataion
template <typename T> class hashTable{ 
//private members
private:
	//Initializes hashData object that returns key for every element
	std::hash<T> hashData; 
	//Initiazlies Table to store vectors
	std::vector<std::vector<T> > table; 
	//Initiazlies the number of rows in hash Table
	int numRows; 

//public members
public:
	//hash function that takes item and returns the hash value of the item
	int hash(T &item){
		//Uses the hashData object and uses mod to find remainder from numRows
		//Hash value of the item is simply a number from 0 to numRows. 
		return hashData(item) % numRows; 
	}
	
	//void function initializes the hash table and takes in a type T vector
	void initializeHashTable(std::vector<T> &list){ 
		//Initialize number of rows to 3 collisions per row.
		numRows = floor(list.size() / 3); 
		//Initializes number of rows in the hash Table
		table.resize(numRows); 
		//for statement that iterates over the entire list.
		for (int i=0; i<list.size(); i++){ 
			//calls addItem function to add an item in the hash Table
			addItem(list.at(i)); 
		}
	}
	
	//void function that adds an item to the hash Table
	void addItem(T &item){ 
		//Initializes integer key for the item
		int key; 
		//Sets the key to the item using function hash() to return hash value for the item
		key = hash(item); 
		//push back function to insert the item into the hash Table.
		table[key].push_back(item); 
	}

	//void function that deletes an item from the hash Table
	void deleteItem(T &item){
		//Initializes integer key for the item using function hash()
		int key = hash(item); 
		
		//for statement that iterates over the the entire list.
		for (int i=0; i < table[key].size(); i++){
			//if statement that checks to see if the key at i finds the item  
			if (table[key].at(i) == item){
				//Initializes a temp variable to set the key at i
				std::string temp = table[key].at(i); 
				//Swaps the item with the last item in the row
				table[key].at(i) = table[key].at(table[key].size() - 1);
				//sets the last item in the row to the temp variable
				table[key].at(table[key].size() - 1) = temp;
				//pop back function to delete the item form the row
				table[key].pop_back();
				return; 
			}
		}
	}

	//bool function that checks to see if item is found
	bool inList(T &item){
		//Initializes integer key for the item using the function hash()
		int key = hash(item); 
		
		//for statement that iterates over the entire hash row
		for (int i=0; i<table[key].size(); i++){ 
			//if statement that checks to see if the key at i finds the item
			//returns true if found, return false if not.
			if (table[key].at(i) == item) 
				return true; 
		}
		return false; 
	}
};

#endif 
