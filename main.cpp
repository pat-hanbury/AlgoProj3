//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//main file

#include "grid.h"
#include "wordList.h"
#include <time.h>
#include "heap.h"
#include "hashTable.h"

//newly overloaded function that takes a wordlist and a string
//returns a binary search function 
bool compareSearch(wordList &w, std::string &compare){ 
	return w.binarySearch(compare);
}

//newly overloaded function that takes in a hash table and a string 
//returns the inlist function from hash table
bool compareSearch(hashTable<std::string> &w, std::string &compare){
	return w.inList(compare);
}

//Overloaded output operator to print the word list
std::ofstream& operator << (std::ofstream &out, wordList &list){
	
	//for loop that iterates from the start of the list to the last element in the list
	for (int i=0; i<list.list.size(); i++)
		//Implementation of the at function of the vector class
		out << list.list.at(i)<< std::endl;
	//returns out
	return out;
}


//for part 3b, newly implemented operator
//overloaded output operator to print heap
std::ofstream& operator << (std::ofstream &out, heap<std::string> &list){
	
	//for statement that iterates from start of heap list to last 
	for (int i =0; i<list.heapSize; i++) 
		//Implementation of the at function of the vector class
		out << list.getItem(i) << std::endl; 
	return out;
}

//Global function findMatches() that is passsed the word list and the grid as the parameter
// for part 3b we added a function that takes in an X type object so it can either use hash tables or wordlist as first parameters
template <typename X>
void findMatches(X &words, grid &searchGrid){
	//initialized variable to store strings
	std::string compare;
	//object declaration that will store the strings found in the grid
	wordList foundStrings;
	
	//for loop that iterates over the rows
	for (int i=0; i<searchGrid.getRows(); i++){
		//another for loop that iterates over the columns
		for (int j=0; j<searchGrid.getColumns(); j++){
			//another for loop that searches each of the 8 directions
			for (int k=0; k<8; k++){
				//another for loop that searches through the rnage of word lengths for each of the 8 directions
				for (int l=5; l<10; l++){
					
					//string variable compare is reset to store a new string from the grid
					compare = "";
					//x and y represent grid coordinates for the string to be added
					int x = i;
					int y = j;
					
					//final for loop that iterates over the current word that was found in the grid
					for (int h=0; h<l; h++){
						//adds the current word letter to the string compare
						compare += searchGrid.location(x, y);
						//These set of case statements explores each of the possible 8 directions
						//Variable k determines the location of the direction
						switch (k)
						{
							//East direction
							case 0:
								y++;
								break;
							//South Direction
							case 1:
								x++;
								break;
							//North Direction
							case 2:
								x--;
								break;
							//West Direction
							case 3:
								y--;
								break;
							//Northeastern
							case 4:
								x--;
								y++;
								break;
							//Southeast Direction
							case 5: 
								x++;
								y++;
							//Southwestern Airlines
							case 6:
								x++;
								y--;
							//Northwest Direction
							case 7: 
								x--;
								y--;
							default:
								break;
						}
						//other than direction, program has to search for the words around the edges
						//If statement that searches if the word wraps around the bottom
						if (x >= searchGrid.getRows())
							//grid coordinates are reset to the top 
							x = 0;
						//If statement that searches if the word wraps around the top
						else if (x < 0)
							//grid coordinates are reset to the top
							x = searchGrid.getRows() - 1;
						//If statement that searches if the wrod wraps around the right of the grid
						if(y >= searchGrid.getColumns())
							//grid coordinates are reset to the left
							y = 0;
						//If statement that searches if the word wrps around the left of the grid
						else if (y < 0)
							//grid coordinates are reset to the left
							y = searchGrid.getColumns() - 1;						
					}
					//If statement that searches for the word
					if (compareSearch(words,compare))
						//If a string was found, then it will be added to findstrings
						foundStrings.list.push_back(compare);
				}
			}
		}
	}
	//Ofstream variable to output foundStrings
	std::ofstream fout;
	//Opens a new foundStrings.txt file
	fout.open("foundStrings.txt");
	//Prints the foundStrings
	fout << foundStrings;
	//Closes the foundStrings.txt file
	fout.close();	
}

//global function Search() that reads the name of the grid file and prints out all the words from the word list that can be found in the grid.
//function also prints out CPU time to sort words, find words, and total time.
void search(int sortingMethod){
	//Initializes grid object
	grid newGrid;
	//Initializes main wordList
	wordList newList;
	//Initializes time variables
	clock_t start, sort, find;
	
	
	//newly initialized heaps
	heap<std::string> list;
	//newly initialized hashtables
	hashTable<std::string> searchTable;
	
	
	//Member function readWords reads all the words in the textfile and words it in newList
	newList.readWords();
	//user input
	std::cout<<"What is the filename of the grid: ";
	std::string userGrid;
	std::cin >> userGrid;
	
	//Stores the text file into the grid object
	newGrid.readGrid(userGrid);
	//Initiazlies the clock
	start = clock();
	
	
	//newly added Heap and hash table methods for project 3b
	//These set of switch cases decides the sorting method by invoking the correct member function
	//each method tells user which sorting method is being used
	//additionally for each case, it ends the sort and find timer within the case statement. and invokves the findmatches function within
	switch (sortingMethod)
	{
		//Insertion Sort
		case 1:
			std::cout << "Searching via insertion sort" <<std::endl; 
			newList.insertionSort();
			sort = clock();
			findMatches(newList, newGrid);
			find = clock();
			break;
		//merge sort
		case 2:
			std::cout << "Searching via merge sort" <<std::endl;
			newList.mergeSort(0, newList.list.size() - 1);
			sort = clock();
			findMatches(newList, newGrid);
			find = clock();
			break;
		//quick sort
		case 3:
			std::cout << "Searching via quick sort" <<std::endl;
			newList.quickSort(0, newList.list.size() - 1);
			sort = clock();
			findMatches(newList, newGrid);
			find = clock();
			break;
		//heap sort
		case 4:
			std::cout << "Searching via heap sort" <<std::endl;
			newList.heapSort();
			sort = clock();
			findMatches(newList, newGrid);
			find = clock();
			break;
		//hash table
		case 5:
			std::cout << "Searching in hash table" <<std::endl;
			sort = start;
			searchTable.initializeHashTable(newList.list);
			findMatches(searchTable, newGrid);
			find = clock();
			break;
		default:
			break;
	}	
	

	//Displays the time it took for the CPU to sort the words, find the words, and total time.
	//Displays it per clocks per sec or in milliseconds.
	std::cout << "It took sorting time of "<< (sort-start) * 1000 / CLOCKS_PER_SEC <<"msecs" << std::endl;
	std::cout << "It took finding time of "<< (find-sort) * 1000 / CLOCKS_PER_SEC <<"msecs" << std::endl;
	std::cout << "It took total time of "<< (find-start) * 1000 / CLOCKS_PER_SEC <<"msecs" << std::endl;	
}



//newly added lines for project3b for hash table and heap sort
//main function
int main(){
	std::cout << "For this program, the search method is called 5 times, each for the different sort methods" << std::endl;
	std::cout << "Thus, please enter the name of the grid file for all 5 matches" << std::endl;
	//Search functions
	//Insertion sort
	search(1);
	//Merge sort
	search(2);
	//Quick sort
	search(3);
	//heap sort
	search(4);
	//hash table
	search(5);
	//Tells user to check the file
	std::cout << "Please check the sortList.txt file" << std::endl;
		
	system ("pause");
	return 0;
}
