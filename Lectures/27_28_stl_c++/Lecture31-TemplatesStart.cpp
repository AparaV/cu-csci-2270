#include <iostream>

using namespace std;

/*
Templates examples. Code without templates and same code with templates.
Examples for function templates and class templates.

Why: we don't want to write the same function for different data types. For example,
a function that swaps two elements in an array should work regardless of whether the
elements are ints, doubles, floats, or chars.

We can write the algorithm to work with any data type using Templates.
*/

/*
class definition with and without templates.
This is a simple class, that has two private members, both integers.
The class has 2 constructors, a default constructor and a constructor
with two arguments.
*/

class PairWO{
private:
	int first;
	int second;
public: 
	PairWO();
	PairWO(int first_val, int second_val);
	void setElement(int position, int value);
	void printElements();
	int getElement(int position);
};

PairWO::PairWO(){}

PairWO::PairWO(int f, int s){
	first = f;
	second = s;
}

void PairWO::setElement(int position, int val){
	if (position == 1) {
		first = val;
	}
	else if (position == 2) {
		second = val;
	}
	else {
		std::cout << "entry invalid" << std::endl;
	}
}

int PairWO::getElement(int position){
	int returnVal = -1;
	if (position == 1) {
		returnVal = first;
	}
	else if (position == 2) {
		returnVal = second;
	}
	else {
		std::cout << "entry invalid" << std::endl;
	}
	return returnVal;
}

void PairWO::printElements(){
	std::cout << "first: " << first << std::endl;
	std::cout << "second: " << second << std::endl;
}

// with templates

template<class T>
class PairWT {
private:
	T first;
	T second;
public:
	PairWT();
	PairWT(T first_val, T second_val);
	void setElement(int position, T value);
	void printElements();
	T getElement(int position);
};

template<class T>
PairWT<T>::PairWT() {}

template<class T>
PairWT<T>::PairWT(T f, T s) {
	first = f;
	second = s;
}

template<class T>
void PairWT<T>::setElement(int position, T val) {
	if (position == 1) {
		first = val;
	}
	else if (position == 2) {
		second = val;
	}
	else {
		std::cout << "entry invalid" << std::endl;
	}
}

template<class T>
T PairWT<T>::getElement(int position) {
	T returnVal;
	if (position == 1) {
		returnVal = first;
	}
	else if (position == 2) {
		returnVal = second;
	}
	else {
		std::cout << "entry invalid" << std::endl;
	}
	return returnVal;
}

template<class T>
void PairWT<T>::printElements() {
	std::cout << "first: " << first << std::endl;
	std::cout << "second: " << second << std::endl;
}

/*Swap two numbers function, without templates. Notice that the inputs
to the function are both integers. To write the same function to work
with doubles, we would need a different function.
*/

void swapTwoNumbers(int a[], int index1, int index2){
	int temp;
	temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
}

//to make it work for any data type
template<class T>
void swapTwoNumbersGeneric(T a[], int index1, int index2) {
	T temp;
	temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
}

/*
Bubble sort
Sorting algorithms should work for any type. It's repetitive to write the
same algorithm for any number of types. Use a template.

Without templates - sorts integers only. Error for other types.
Yes, it's bubble sort.
*/

void sort(int a[], int length){
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length-1; j++) {
			if (a[j] > a[j+1]) {
				swapTwoNumbers(a, j, j+1);
			}
		}
	}
}

int main(){
	/*int a[5] = {1, 2, 3, 4, 5};
	swapTwoNumbers(a, 0, 4);
	for (int i = 0; i < 5; i++) {
		std::cout << a[i] << std::endl;
	}
	swapTwoNumbersGeneric(a, 0, 4);
	for (int i = 0; i < 5; i++) {
		std::cout << a[i] << std::endl;
	}

	double b[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	swapTwoNumbersGeneric(b, 0, 4);
	for (int i = 0; i < 5; i++) {
		std::cout << b[i] << std::endl;
	}*/

/*	int a2[5] = {11, 2, 13, 4, 5};
	int length = 5;
	sort(a2, length);
	for (int i = 0; i < length; i++) {
		std::cout << a2[i] << std::endl;
	}*/
	

	/*No type given because the type is defined for the variables in the class.*/
	/*PairWO scoreWO;
	scoreWO.setElement(1,3);
	scoreWO.setElement(2,4);
	scoreWO.printElements();
	std::cout << scoreWO.getElement(2) << std::endl;*/

	PairWT<char> test('1', 'a');
	test.printElements();
	cout << test.getElement(3) << endl;

}