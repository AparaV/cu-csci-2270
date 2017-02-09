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
	Single and doubly linked list
	Double linked list - goes in both directions

*/

/*
	Defining Linked List:

		private:
			head									//pointer to first node in list
			tail									//pointer to last node in list
		public:
			LinkedList()							//constructor
			insertNode(previousValue, value)		//insert a new node
			search(value)							//search for a value
			traverse()								//print out the list
			deleteNode(value)						//delete an existing node
			deleteList()							//delete entire list (contents)

*/

/*
	Searching

		node* search(value)
			node* current = head;
			while (current != NULL)
				if (current->key == value)
					return current
				current = current->next
			return NULL

		Assumes
		 - head initialized to NULL
		 - head != NULL when nodes are added

*/

/*
	Inserting a node (singly linked list)

		Possibilities
			1. New head node
			2. Middle
			3. New tail node

		void insertNode(previousValue, value)
			node* left = search(previousValue)
			node* n = new node(value, NULL)
			if (left == NULL)					//add to head
				n->next = head
				head = n
			else if (left->next == NULL)		//add to tail
				left->next = n
				tail = n
			else								//add to middle
				n->next = left->next
				left->next = n

*/

#include <iostream>

using namespace std;

//Single linked list
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
struct Node {
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