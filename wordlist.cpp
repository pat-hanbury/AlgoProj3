//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//wordList.cpp

#include "wordList.h"
#include "grid.h"
#include <cmath>

//Function that reads the words from the wordlist file
void wordList::readWords(){ 
	//Ifstream variable to read files
	std::ifstream fin;
	//String variable to store the string from the read file
	std::string store; 
	//Open the the text file
	fin.open("wordlist.txt");
	//If statement that checks if the file is there or not
	//Outputs a message if file is not there

    if (!fin){
		std::cout << "No file";
		system("pause");
		exit(0);
	}

	
	//While statement that reads the wordlist.txt file.
	while (fin){
		//Stores the string from wordlist.txt file into the string variable
		fin >> store; 
		//Stores the current word in the string variable
		list.push_back(store); 
	}
	//closes the wordlist.txt file
	fin.close(); 
}

//bool function binarySearch to handle word lookups
bool wordList::binarySearch(std::string &key){
	return binarySearchAux(key, 0, list.size()-1);
}

//bool helper function binarySearchAux
//passes a string and two variables to represent the right and left side of the search
bool wordList::binarySearchAux(std::string &key, int left, int right) {
	//if statement that checks if the right side is less than left side
	//if entire list was searched, then program ends
	if (right<left) 
		return 0; 
	
	//Initializes a variable at the middle and calculates the middle of the list
	int mid = floor((left+right) / 2); 
	//if statement that checks if the middle is search
	//returns true, if it was middle
	if (key == list.at(mid)) 
		return true; 
	//If statement that checks if the search is less than the midpoint
	else if (key < list.at(mid)) 
	//Calls the helper function on the left side of the list
		return binarySearchAux(key, left, mid -1); 
	//Else statement that checks if the search is more than the midpoint
	else
	//Calls the helper function on the right side of the left. 
		return binarySearchAux(key, mid+1, right); 
}

//Function that implements InsertionSort
void wordList::insertionSort(){
	
	//for loop that iterates over the outside
	for (int i=1; i <list.size(); i++){
		//Insert the element at sorted position

        std::cout<< "list size is: " << list.size() << std::endl;

        std::string key = list[i];
		//Initializes the length 
		int j = i-1; 
		
		//While loop to check the inserted element against the other elements
		while (j >= 0 && list.at(j) > key)
		{
            std::cout<<"loop i = " << i;
            std::cout<<"             j = " << j << std::endl;

                     //Moves the sorted elements
			list.at(j+1) = list.at(j); 
			j--; 
		}
		//Inserts the key
		list.at(j+1) = key; 
	}
}

//Function that implements mergeSort
void wordList::mergeSort(int p, int r){
	//initializes variables
	int q=p;
	//if statement that checks if one element is less than the other 
	if (p<r) { 
		//divides the list by 2
		q = floor((p + r) / 2);
		//calls the function to repeat left side
		mergeSort(p, q);  
		//calls the function to repeat right side
		mergeSort((q + 1), r); 
	}
	//Merges the elements together
	merge(p, q, r); 
}

//Function that implements quickSort
void wordList::quickSort(int p, int r){
	//If statement that compares the two sides
	if (p<r){ 
		//calls partition function
		int q = partition(p, r); 
		//calls the function to work left side
		quickSort(p, q);
		//calls the function to work right side
		quickSort((q+ 1), r); 
	}
}

//Function to work with mergeSort
void wordList::merge(int p, int q, int r){
	//Initializes variables for the left and right side
	int left = q - p + 1; 
	int right = r - q; 
	//Stores the new divided elements
	std::vector<std::string> A, B; 
	
	//for loop to iterate the left list
	//stores the elements in the A list
	for (int i = 0; i < left; i++) 
		A.push_back(list.at(p + i));
		
	//for loop to iterate the right list
	//stores the elements in the B list
	for (int i = 0; i < right; i++) 
		B.push_back(list.at(q + i + 1));
	
	//initalizes the variables used from the left and right sides
	int i = 0; 
	int j = 0; 
	//Sets the last element of the A/B lists to infinity 
	A.push_back("zzzzzzzzzzzzzzz");
	B.push_back("zzzzzzzzzzzzzzz");
	
	//for statement that iterates from the left to the right 
	for (int k = p; k <= r; k++){ 
		//if statement that compares the current left element to the current right element
		if (A.at(i) <= B.at(j)){ 
			//if less than or equal to, then insert the left element into the list
			list.at(k) = A.at(i); 
			//increases the left side elements
			i++; 
		}
		//else statement that compares the left element to the right element
		else {
			//if the right is less than or equal to, then insert the right element into the list 
			list.at(k) = B.at(j); 
			//increases the right side elements
			j++; 
		}
	}
}

//partition function
int wordList::partition(int p, int r){
	//screates the pivot of the list	
	std::string x = list.at(r); 
	//initiazlies the size of the list
	int i = p - 1; 
	//for statement that iterates from the left to the right side
	for (int j = p; j < r; j++){ 
		//if statement that compares the current element to the pivot
		if (list.at(j) <= x){ 
			//increases the size of the list 
			i++; 
			//stores the current element
			std::string swap = list.at(i);
			//sets the current element to the first position of the greater than list 
			list.at(i) = list.at(j); 
			//sets the element in the less than list to the current element.
			list.at(j) = swap; 
		}
	}
	//stores the first element in the greater than list
	std::string swap = list.at(i + 1); 
	//sets the first element in the greater than list to the pivot
	list.at(i + 1) = list.at(r); 
	list.at(r) = swap; 
	return i; 
}
