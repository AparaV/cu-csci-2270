#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *next;
	Node *previous;
	Node(int k, Node *n, Node *p){
		key = k;
		next = n;
		previous = p;
	}
};

class LinkedList{
	private:
		Node *head;

		Node *search(int value){
			Node* curr = head;
			if (head == NULL) {
				return NULL;
			}
			if (head->key == value) {
				return head;
			}
			while (curr->next != NULL) {
				if (curr->key == value) {
					return curr;
				}
				curr = curr->next;
			}
			if (curr->key == value) {
				return curr;
			}
			return NULL;
		}

	public:

		LinkedList(){head = NULL;};
		
		void getName()
		   {
			cout << "Aparajithan Venkateswaran";
		   }

		void addNode(int value, int newVal){
			Node* x = new Node(newVal, NULL, NULL);
			Node* prev = search(value);
			//empty list
			if (head == NULL) {
				head = x;
				//tail = x;
				return;
			}
			//no node
			else if (prev == NULL) {
				x->next = head;
				head->previous = x;
				head = x;
				return;
			}
			//if tail
			else if (prev->next == NULL) {
				prev->next = x;
				x->previous = prev;
				return;
			}
			//otherwise
			else {
				prev->next->previous = x;
				x->next = prev->next;
				prev->next = x;
				x->previous = prev;
				return;
			}
		}
	
		
		
		
   Node *getHead()
      {
		return head;
      }


		void printList(){
			Node *x = head;
			while(x != NULL){
				cout<<x->key<<endl;
				x = x->next;
			}
		}
};