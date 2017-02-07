/*
	Linked List
	===========

	Arrays
	 - Fixed size
	 - Contiguous memory
	 - Doubling is expensive

	Allocate memory as needed
	Link elements with pointers

	Each element is a node - contains a pointer to the next node
	Singly and doubly linked list
	Doubly linked list - goes in both directions

*/

#include <iostream>

using namespace std;

struct node {
	int key;
	node* next;
	//Constructor
	node(int k, node* n = NULL) {
		key = k;
		next = n;
	}
};

//Double linked list
struct dnode {
	int key;
	node* next;
	node* previous;
	//Constructor
	dnode(int k, node* n = NULL, node* p = NULL) {
		key = k;
		next = n;
		previous = p;
	}
};

int main() {

	//Creating the list
	node* x = new node(5, NULL);
	node* x2 = new node(6, NULL);
	node* x3 = new node(7, NULL);
	x->next = x2;
	x2->next = x3;

	//Traversing the list
	node* current = x;
	while (current != NULL) {
		cout << current->key << endl;
		current = current->next;
	}

	//Deallocate
	delete x, x2, x3;

	return 0;
}