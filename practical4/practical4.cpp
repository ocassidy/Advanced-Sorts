//================================================================================
// Name        : practical4.cpp
// Author      : a.mccaughey@ulster.ac.uk
// Version     : 1.0
// Description : practical 4 test program to utilise sort algorithms
//================================================================================

#include <string> // used to access string type
#include <cctype>
#include <ctime> // used to access clock_t and clock()
#include <map>
#include <tuple>
#include "Array.h"
#include "Sorter.h"

using namespace std;

// Test relative sort performances when sorting same random 
// number sequence of specified size. 
void testPerformance(int size) {
  // create a Sorter for each sort algorithm ensuring each
  // contain the same random numbers. Use of Sorter copy
  // constructor is one way to ensure this!!
  
  // For each Sorter start clock, call relevant sort algorithm, 
  // call clock again, print results

  // Note: Sorting very large data sets may cause quicksort to run out
  // of stack space and crash program as recursive overhead is too great.

	Sorter<int> intSort (size);
	//Array<int> arrayInt(20000);
	intSort.fillRandom(10000);

	Sorter<int> selectionCopy(intSort);
	Sorter<int> insertionCopy(intSort);
	Sorter<int> mergeCopy(intSort);
	Sorter<int> quickCopy(intSort);

	selectionCopy.selectionSort();
	cout << "Selection sort: " << selectionCopy << endl;
	
	insertionCopy.insertionSort();
	cout << "Insertion sort: " << insertionCopy << endl;

	mergeCopy.mergeSort();
	cout << "Merge sort: " << mergeCopy << endl;

	quickCopy.quickSort();
	cout << "Quick sort: " << quickCopy << endl;
}

// Determine the most frequent word in the supplied text file 'words.txt'
// print the word and its frequency
void wordFrequency() {
	int max = 0;
	std::map<string, int> count;

	Sorter<string> stringSort;
	stringSort.loadFile("words.txt");

	stringSort.mergeSort();
	cout << "Sorted text file: " << stringSort << endl;
	
	/*for (int i = 0; i < stringSort.getElements().length(); i++) {

	}*/

}

// Main method.
int main() {

	testPerformance(1000);
	wordFrequency();

	// ---------------------------------------------------
	return 0;
}