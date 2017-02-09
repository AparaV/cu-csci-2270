/*
 *	Write a C++ function to add a node to the end of a linked list.
 *	The function takes two arguments - the head of the linked list
 *	and the value to be added. It should return the head of the linked list.
 *
 *	node *AddNode(node *head, int key);
 *
 *	The linked list structure:
 *		struct node {
 *			int key;
 *			node *next;
 *		};
 *
 *	You can assume that the head being passed is initialized as follow:
 *		node *head = NULL;
 */

struct node {
	*int key;
	*node *next;
	*
};

node* AddNode(node* head, int k) {
	node* temp = new node;
	temp->key = k;
	temp->next = NULL;

	//If list is emtpy
	if (head == NULL) {
		return temp;
	}

	//If list in not empty
	node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = temp;

	return head;
}