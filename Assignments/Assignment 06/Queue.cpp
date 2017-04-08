/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 06
** Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include "Queue.h"

using namespace std;

//Constructor
Queue::Queue(int qs) {
	queueSize = qs;
	arrayQueue = new string[queueSize];
	queueHead = 0;
	queueTail = 0;
	queueCount = 0;
}

//Destructor
Queue::~Queue() {
	queueTail = 0;
	queueHead = 0;
	queueCount = 0;
	queueSize = 0;
	delete[] arrayQueue;
}

//Enqueue
void Queue::enqueue(string value) {
	if (queueIsFull()) {
		cout << "Queue is full." << endl;
		return;
	}
	arrayQueue[queueTail] = value;
	queueCount++;
	queueTail++;
	if (queueTail >= queueSize) {
		queueTail = 0;
	}
	cout << "E: " << value << endl;
	cout << "H: " << queueHead << endl;
	cout << "T: " << queueTail << endl;
	return;
}

//Dequeue
string Queue::dequeue() {
	if (queueIsEmpty()) {
		cout << "Queue is empty." << endl;
		return "";
	}
	string value = arrayQueue[queueHead];
	queueHead++;
	queueCount--;
	if (queueHead >= queueSize) {
		queueHead = 0;
	}
	cout << "H: " << queueHead << endl;
	cout << "T: " << queueTail << endl;
	cout << "word: " << value << endl;
	return value;
}

//Print queue
void Queue::printQueue() {
	if (queueIsEmpty()) {
		cout << "Empty" << endl;
		return;
	}
	int index =	queueHead;
	for (int i = 0; i < queueCount; ++i) {
		cout << index << ": " << arrayQueue[index] << endl;
		index++;
		if (index >= queueSize) {
			index = 0;
		}
	}
	return;
}

//Is full
bool Queue::queueIsFull() {
	return queueCount >= queueSize;
}

//Is empty
bool Queue::queueIsEmpty() {
	return queueCount == 0;
}