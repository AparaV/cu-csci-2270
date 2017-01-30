/*
	Dynamic memory: Allocate memory while program is running

	int* p = new int;
	delete p; //prevent memory leaks
	
	Array Doubling
	==============

	Read data until array fills
	Create new array that 2x size
	Copy values into new array
	Free the old array

	Objects
	=======

	Struct, Class

*/

#include <iostream>

using namespace std;

struct Item {
	int p;
	string s;
	//constructor
	Item() {}; //default
	Item(int inP, string inS) {
		p = inP;
		s = inS;
	}
};

int main() {
	
	int size = 2;

	int* p = new int[size];
	for (int i = 0; i < size; ++i) {
		p[i] = i;
	}

	for (int i = 0; i < size; ++i) {
		cout << p[i] << endl;
	}

	cout << "Array full\nDoubling array" << endl;

	//Array doubling
	size *= 2;
	int* p2 = new int[size];
	//copy old values
	for (int i = 0; i < size / 2; ++i) {
		p2[i] = p[i];
	}
	delete[] p; //deallocate memory
	p = p2;
	cout << "New array" << endl;
	for (int i = 0; i < size; ++i) {
		cout << p[i] << endl;
	}

	cout << "\n***\n" << endl;

	Item myItem(5, "nothing");
	Item newItem;//calls default c'tor

	Item* ptrItem = new Item(5, "something"); //need to dereference to get item values
	ptrItem->p = 0;
	ptrItem->s = "nothing";
	(*ptrItem).p = 5;
	(*ptrItem).s = "something";

	return 0;
}