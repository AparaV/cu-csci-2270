/** CSCI 2270 - Recitation 11
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <string>
//TODO: add appropriate includes
#include <vector>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------------------
class customVector{
	public:
		//TODO: add appropriate header information
		void printVector();
		void reverseVector();
		void removeAll();
		void removeElement(int n);
		vector<int> intVec;

};
// ----------------------------------------------------------------------
void customVector::printVector(){
	cout << "Elements of Integer Vector: " << endl;
	// TODO: check if the vector is empty otherwise print all elements in the vector
	if (intVec.empty()) {
		cout << "Empty" << endl;
		return;
	}
	vector<int>::iterator iter;
	for (iter = intVec.begin(); iter != intVec.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

}

void customVector::reverseVector(){
	//TODO: reverse the elements in the vector, using the STL algorithm
	reverse(intVec.begin(), intVec.end());
}

void customVector::removeAll(){
	cout << "Removing all elements from the vector: " << endl;
	//TODO: remove all elements from the vector
	while (!intVec.empty()) {
		cout << "Deleting " << intVec.back() << endl;
		intVec.pop_back();
	}

}

void customVector::removeElement(int n){
	//TODO: remove a specific element from the vector
	vector<int>::iterator iter;
	iter = find(intVec.begin(), intVec.end(), n);
	if (iter != intVec.end()) {
		intVec.erase(iter);
	}
	else {
		cout << n << " not found." << endl;
	}
}

// ----------------------------------------------------------------------
int main(){
  customVector vec1;
  auto numbers = {1,2,3,4,5,6,7,8};
  for (auto num : numbers){
    vec1.intVec.push_back(num);
  }

  vec1.printVector();

  vec1.reverseVector();
  vec1.printVector();

  vec1.removeElement(4);
  vec1.printVector();

  vec1.removeAll();
  vec1.printVector();

  return 0;
}