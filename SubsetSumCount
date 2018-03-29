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


// Recursively look through every child for sets
int recur(int index, int targetVal) {
	int newTargetVal = targetVal - intSet[index];

	if (newTargetVal == 0)
		return 1;
	else if (newTargetVal < 0)
		return 0;

	int matchCount = 0;
	for (int i = index + 1; i<SET_SIZE; i++) {
		matchCount += recur(i, newTargetVal);
	}

	return matchCount;
}

// Using each index as a root node, look through whole list
int matchingSets(int targetVal) {
	int count = 0;
	for (int i = 0; i<SET_SIZE; i++) {
		count += recur(i, targetVal);
	}
	return count;
}



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



int main()
{
	srand(time(NULL));
	randomize();
	printList();

	int count = matchingSets(16);
	cout << "Matching count: " << count << endl;

	system("pause");

	return 0;
}
