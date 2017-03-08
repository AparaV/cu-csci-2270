#include <iostream>

using namespace std;

void passByReference(int &b) {
	b *= 2;
}

void passByValue(int b) {
	b *= 2;
}

void passByAddress(int* b) {
	(*b) *= 2;
}

int main() {

	int b = 5;
	int* a; //a is not pointing to anything
	//Core dumped
	//cout << *a << endl;
	a = &b;
	cout << "a : " << a << "\nb : " << b << endl;
	passByAddress(&b);
	cout << "After passing by address, b : " << b << endl;
	passByValue(b);
	cout << "After passing by value, b : " << b << endl;
	passByReference(b);
	cout << "After passing by reference, b : " << b << endl;


	return 0;
}