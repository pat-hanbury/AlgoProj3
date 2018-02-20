//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3b
//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <math.h>

//heap declaration
template <typename T> class heap{
	
//private members
private: 
	//heap vector to store the heap
	std::vector<T> heapArray;
	//heap string to store the type of the heap
	std::string heapType;
	//heap variable to store the number of elements
	int heapSize;

//public members	
public:
	//overloaded print operator to print the heap
	friend std::ofstream& operator << (std::ofstream &out, heap<std::string> &list); 

	//Initialization of the integer parent of the heap.
	//Parent of heap
	int parent(int i){ 
		return floor(i / 2);
	}
	
	//Initialization of the integer left of the heap.
	//Left child of heap
	int left(int i){ 
		return 2 * (i + 1) -1;
	}

	//Initialization of the integer right of the heap.
	//Right child of heap
	int right(int i){ 
		return 2 * (i + 1);
	}

	//Initialization of getItem function that returns the nth item in the heap. 
	//Returns an object that is part of the stored heap vector, heapArray.
	T getItem(int n) { 
		return heapArray.at(n);
	}

	//Void function that initializes MaxHeap
	void initializeMaxHeap(std::vector<T> arr){ 
		//Initializes variable heapSize to 0
		heapSize = 0;
		//for loop that iterates over the size of the array
		//Push back function to put i at back of the array
		//Increments the size of the heap
		for (int i = 0; i < arr.size(); i++){ 
			heapArray.push_back(arr.at(i)); 
			heapSize++; 
		}
		//Names heapType of Max
		heapType = "Max Heap"; 
		//Calls member function to buildMaxHeap
		buildMaxHeap(); 
	}
	
	//Void function that heapifies a maxHeap, takes in integer i.
	void maxHeapify(int i){ 
		//Initialization of integers largest to store index of largest element. 
		//Initialization of integer left to store left child
		//Initialization of integer right to right child.
		int largest; 
		int Left = left(i); 
		int Right = right(i); 
		
		//If statement that compares left child to the current element. 
		if (Left < heapSize && heapArray.at(Left) > heapArray.at(i)) 
			//Index of the largest element is the left child
			largest = Left; 
		//Else statement that will store index of current element in largest
		else largest = i; 
		
		//if statement that compares right child to the current element, and greater than largest
		if (Right < heapSize && heapArray.at(Right) > heapArray.at(largest)) 
			//Index of the largest element is the right child
			largest = Right; 
			
		//if statement that checks if largest is not the current element.
		if (largest != i) { 
			//temp variable that checks for heap array.
			//Swaps largest element with current element
			T temp = heapArray.at(i); 
			heapArray.at(i) = heapArray.at(largest);
			heapArray.at(largest) = temp;
			//Calls maxHeapify function with the largest element as the current element,
			maxHeapify(largest);
		}
	}

	//void function buildMaxHeap that creates the max heap
	void buildMaxHeap(){ 
		//for statement that decrements the size of the heap by one.
		for (int i = floor((heapSize - 1) / 2); i >= 0; i--){ 
			//Calls max heapify for i.
			maxHeapify(i); 
		}
	}

	//void function initialization that operates similarly to initializationMaxHeap.
	void initializeMinHeap(std::vector<T> arr){
		//Initializes variable heapSize to 0
		heapSize = 0; 
		//for loop that iterates over the size of the array
		//Push back function to put i at back of the array
		//Increments the size of the heap
		for (int i = 0; i < arr.size(); i++){ 
			heapArray.push_back(arr.at(i)); 
			heapSize++;
		}
		//Names heapType of Min
		heapType = "Min Heap"; 
		//Calls member function to buildMinHeap
		buildMinHeap(); 
	}

	//void function that heapifies a minHeap, takes in integer i.
	void minHeapify(int i){ 
		//Initialization of integers smallest to store index of smallest element. 
		//Initialization of integer left to store left child
		//Initialization of integer right to right child.
		int smallest; 
		int Left = left(i); 
		int Right = right(i); 
		
		//If statement that compares left child to the current element. 
		if (Left < heapSize && heapArray.at(Left) < heapArray.at(i)) 
			//Index of the smallest element is the left child
			smallest = Left; 
		//Else statement that will store index of current element in smallest
		else smallest = i; 
		
		//if statement that compares right child to the current element, and less than lsmallest
		if (Right < heapSize && heapArray.at(Right) < heapArray.at(smallest))
			//Index of the smallest element is the right child
			smallest = Right; 
		
		//if statement that checks if smallest is not the current element.
		if (smallest != i){
			//variable that checks for heap array.
			//Swaps smallest element with current element
			T temp = heapArray.at(i); 
			heapArray.at(i) = heapArray.at(smallest);
			heapArray.at(smallest) = temp;
			//Calls mainHeapify function with the smallest element as the current element,
			minHeapify(smallest); 
		}
	}

	////void function buildMinHeap that creates the min heap
	void buildMinHeap() { 
		//for statement that decrements the size of the heap by one.
		for (int i = floor((heapSize - 1) / 2); i > 0; i--){ 
			//Calls min heapify for i.
			minHeapify(i); 
		}
	}

	//void function that heapSorts a maxheap
	void heapSort(){ 
		//Stores current size of heap
		int heapSizeStore = heapSize; 
		//for statement that iterates over the entire heap 
		for (int i = heapSize - 1; i > 0; i--){ 
			//variable that checks for heap array.
			//Swaps first element with current element
			T temp = heapArray.at(i); 
			heapArray.at(i) = heapArray.at(0);
			heapArray.at(0) = temp;
			//Decements heapsize.
			heapSize--; 
			//Calls maxHeapify because we want the heap to be smaller than what it was before
			maxHeapify(0); 
		}
		//Resets the heapSize to the previously stored size, 
		heapSize = heapSizeStore; 
	}
};

#endif
