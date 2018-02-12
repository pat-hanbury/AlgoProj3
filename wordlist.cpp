//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project3a
//wordlist.cpp



#include "wordlist.h"
#include "grid.h"


void wordlist::readWords() { 
	std::ifstream fin; 
	std::string store; 
	fin.open("wordlist.txt"); 
	if (!fin) { 
		std::cout << "No file";
		system("pause");
		exit(0);
	}
	while (fin) { 
		fin >> store; 
		list.push_back(store); 
	}
	fin.close(); 
}
//


bool wordlist::binarySearch(std::string &key){
	return binarySearchAux(key, 0, list.size()-1);
}

bool wordlist::binarySearchAux(std::string &key, int left, int right) {
	if (right < left) 
		return 0; 
	int mid = floor((left + right) / 2); 
	if (key == list.at(mid)) 
		return true; 
	else if (key < list.at(mid)) 
		return binarySearchAux(key, left, mid - 1); 
	else
		return binarySearchAux(key, mid + 1, right); 
}

void wordlist::mergeSort(int p, int r) {
	int q = p; 
	if (p < r) { 
		q = floor((p + r) / 2); 
		mergeSort(p, q);  
		mergeSort((q + 1), r); 
	}
	merge(p, q, r); 
}

void wordlist::insertionSort() {
	for (int j = 1; j < list.size(); j++) {
		std::string key = list.at(j); 
		int i = j - 1; 
		while (i >= 0 && list.at(i) > key) 
		{
			list.at(i + 1) = list.at(i); //
			i--; 
		}
		list.at(i + 1) = key; 
	}
}
//


void wordlist::quickSort(int p, int r) {
	if (p < r) { 
		int q = partition(p, r); 
		quickSort(p, q);
		quickSort((q + 1), r); 
	}
}





void wordlist::merge(int p, int q, int r) {
	int n1 = q - p + 1; 
	int n2 = r - q; 
	std::vector<std::string> A, B; 
	for (int i = 0; i < n1; i++) 
		A.push_back(list.at(p + i));
	for (int i = 0; i < n2; i++) 
		B.push_back(list.at(q + i + 1));
	int i = 0; 
	int j = 0; 
	A.push_back("zzzzzzzzzzzzzzz"); //infinity 
	B.push_back("zzzzzzzzzzzzzzz"); //infinity
	for (int k = p; k <= r; k++) { 
		if (A.at(i) <= B.at(j)) { 
			list.at(k) = A.at(i); 
			i++; 
		}
		else { 
			list.at(k) = B.at(j); 
			j++; 
		}
	}
}

int wordlist::partition(int p, int r) {
	std::string x = list.at(r); //stores last element of the list as pivot
	int i = p - 1; 
	for (int j = p; j < r; j++) { 
		if (list.at(j) <= x) { 
			i++; 
			std::string swap = list.at(i); 
			list.at(i) = list.at(j); 
			list.at(j) = swap; 
		}
	}
	std::string swap = list.at(i + 1); 
	list.at(i + 1) = list.at(r); 
	list.at(r) = swap; 
	return i; 
}
