/*
* Given a set of integers:
* Recursively finds amount of subsets that add up to a given number
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>

using namespace std;

// Array
#define SET_SIZE 50
int intSet[SET_SIZE];



/*** PURE RECURSIVE VERSION WITHOUT LOOPS ***/
// Recursively look through entire list for matching sets without any loops
int recursiveSearch_pure(int depthIndex, int targetVal) {
	int newTargetVal = targetVal - intSet[depthIndex];
	int matchCount = 0;
	int thisCount = 0;

	if (newTargetVal == 0)
		thisCount = 1;
	else if (newTargetVal < 0)
		thisCount = 0;
	else if (depthIndex + 1 < SET_SIZE)
		matchCount += recursiveSearch_pure(depthIndex + 1, newTargetVal);		// go deep with this as parent node for children

	if (depthIndex + 1 < SET_SIZE)
		matchCount += recursiveSearch_pure(depthIndex + 1, targetVal);			// go wide by treating next as a root node

	return thisCount + matchCount;
}

// Call recursive set finder with starting values
int matchingSets_pure(int targetVal) {
	return recursiveSearch_pure(0, targetVal);
}
/***************************************/



/*** HYBRID RECURSIVE VERSION COMBINING LOOPS AND RECURSION ***/
// Recursively look through every child for sets
int recursiveSearch_hybrid(int index, int targetVal) {
	int newTargetVal = targetVal - intSet[index];

	if (newTargetVal == 0)
		return 1;
	else if (newTargetVal < 0)
		return 0;

	int matchCount = 0;
	for (int i = index + 1; i<SET_SIZE; i++) {
		matchCount += recursiveSearch_hybrid(i, newTargetVal);
	}

	return matchCount;
}

// Using each index as a root node, look through whole list
int matchingSets_hybrid(int targetVal) {
	int count = 0;
	for (int i = 0; i<SET_SIZE; i++) {
		count += recursiveSearch_hybrid(i, targetVal);
	}
	return count;
}
/***************************************/





/* SOME UTILITIES */
// Perform an action on every array entry
void listAction(void(*f)(int &iRef)) {
	for (int i = 0; i<SET_SIZE; i++) {
		f(intSet[i]);
	}
}

// Print list
void printList() {
	listAction([](int &iRef) {
		cout << iRef << ", ";
	});
	cout << endl;
}

// Randomize list 0-10 for now
void randomize() {
	listAction([](int &iRef) {
		iRef = rand() % 10;
	});
}
/******************/



int main()
{
	srand(time(NULL));
	randomize();
	printList();

	int count = matchingSets(16);
	cout << "Matching count: " << count << endl;

	count = matchingSetsPure(16);
	cout << "Matching count [Pure recursive]: " << count << endl;

	system("pause");

	return 0;
}
