/*
 *	Write a C++ function to delete nodes in a linked list.
 *	The function takes two arguments - the head of the linked list and the value to be deleted.
 *	It should delete all nodes which contain the value to be deleted.
 *	It should return the head of the linked list.
 *
 *	node* DeleteNode(node *head, int value);
 *
 *	The linked list structure :
 *		struct node
 *		{
 *			int value;
 *			node *next;
 *		};
 */

struct node{
	int value;
	node* next;
};

node* DeleteNode(node* head, int value) {

	node* current = head;
	//empty list
	if (current == NULL) {
		return current;
	}

	//first node is to be deleted
	while (current->next != NULL && current->value == value) {
		node* temp = current;
		current = temp->next;
		delete temp;
		head = current;
	}

	//middle node to be deleted
	while (current->next != NULL) {
		if (current->next->value == value) {
			node* temp = current->next;
			current->next = temp->next;
			delete temp;
		}
		else {
			current = current->next;
		}
	}

	return head;
}
