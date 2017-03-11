#include <iostream>
#include "LinkedList.cpp"

using namespace std;
void printList(Node *head)
{
	Node *tr=head;
	cout<<"Traverse Forward\n==============\n";
 while(tr->next!=NULL)
 {
	 cout<<tr->key << " ";
	 tr=tr->next;
 }	
 cout<<tr->key;
cout<<"\n";
//Traverse Backwards
cout<<"Traverse Backward\n==============\n";
while(tr->previous!=NULL)  
{
	cout<<tr->key <<" ";
	tr=tr->previous;
}
cout<<tr->key;   
}



/*Exam question:
Add a method to the LinkedList.cpp file to add a node to a linked list.
The function definition is provided, you need to fill in where it says
"Students need to write this method". 

 The function takes two arguments - the value of the
previous node and the value of the new node to add. For example, if you
call addNode(5, 6), it means add a node to the linked list with a value
of 6 after the node with a value of 5. If the previous value does not exist
in the list, add the new node to the head of the list. You are working with a 
doubly linked list.

Test cases:
Add node to empty list - will be head of list
Value not found - add to head of list
Value found - add after that node
Value found - add after as new end of the list
*/



int main(){
	LinkedList ll;
	Node *head;
	ll.addNode(1, 5);  // 5->
	ll.addNode(5, 10); // 5->10
	ll.addNode(5,6); //5->6->10
	
	
	
	cout<<"Test Case 1\n==========\n"; //Expected Output is 5 6 10 and 10 6 5
	head=ll.getHead();
	
	printList(head);
	
	//Expected Output is 5 6 10 and 10 6 5
	
	
	
	cout<<"\n\nTest Case 2 \n==========\n"; //Expected Output 12 5 6 7 10 11
	ll.addNode(6,7); //5->6->7->10
	ll.addNode(10, 11); //5->6->7->10->11
	ll.addNode(100, 12); //12->5->6->7->10->11 (As there is no 100 insert 100 in the head position)
	head=ll.getHead();
    printList(head);
	cout << endl;
	
//Expected Output 12 5 6 7 10 11 and 11 10 7 6 5 12 

 }