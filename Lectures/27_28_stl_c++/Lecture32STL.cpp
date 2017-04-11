#include <iostream>
#include <queue> //this is where queue is defined
#include <set>

using namespace std;

struct node{
	int key;
};
int main(){

	//other STL data structures
	//queue
	queue<int> q;
	q.push(5);
	q.push(4);
	/* The STL is funny. The front() method returns the front element, and the pop() method
	actually removes it.*/
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();

	queue<char> q2;
	q2.push('a');
	q2.push('b');

	queue<node> q3;
	//nodes is a vector of type node. Each element is a node
	vector<node> nodes(10);
	q3.push(nodes[5]);
	q3.push(nodes[1]);
	node t = q3.front();
	cout<<t.key<<endl;
	cout<<q3.front().key<<endl;
	//we'll assume that the stack works similarly, except that it's a stack
	
	//set - each element in the set is unique. e.g. a list of 1,1,1,2,2,4,5,6 produces the set 1,2,4,5,6
	
	set<int> s;
	//add a bunch of stuff, numbers not sorted
	s.insert(5);
	s.insert(4);
	s.insert(14);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(41);
	s.insert(24);
	s.insert(40);
	
	cout<<"size: "<<s.size()<<endl;
	s.insert(5); //add a duplicate
	cout<<"size: "<<s.size()<<endl;
	set<int>::iterator iterS;
	for(iterS = s.begin(); iterS != s.end(); iterS++){
		cout<<*iterS<<endl;
	}
	//what if I told you that finding an element in the set was O(log n)? What would that say about 
	//the underlying data structure? Is it a list, vector, array, tree, balanced tree, none of the above?
	
	/*
	From: http://en.cppreference.com/w/cpp/container/set
	std::set is an associative container that contains a sorted set of unique objects of type Key. 
	Sorting is done using the key comparison function Compare. Search, removal, and insertion 
	operations have logarithmic complexity. Sets are usually implemented as red-black trees
	*/

	iterS = s.find(14);
	cout<<*iterS<<endl;
}