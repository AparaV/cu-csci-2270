/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 06
** Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <sstream>
#include "Queue.h"

using namespace std;

void displayMenu();				//Display menu

int main() {

	Queue q(10);
	bool running = true;

	while (running) {
		char choice;
		string word;
		string sentence;
		stringstream ss;
		displayMenu();
		cin >> choice;

		switch (choice) {
		//Enqueue
		case '1':
			cout << "word: ";
			getchar();
			getline(cin, word);
			q.enqueue(word);
			break;

		//Dequeue
		case '2':
			word = q.dequeue();
			break;

		//Print queue
		case '3':
			q.printQueue();
			break;

		//Enqueue sentence
		case '4':
			cout << "sentence: ";
			getchar();
			getline(cin, sentence);
			ss << sentence;
			while (getline(ss, word, ' ')) {
				q.enqueue(word);
			}
			break;

		//Exit
		case '5':
			cout << "Goodbye!" << endl;
			running = false;
			break;

		default:
			break;
		}
	}

	return 0;
}

//Display menu
void displayMenu() {
	cout << "======Main Menu=====" << endl;
	cout << "1. Enqueue word" << endl;
	cout << "2. Dequeue word" << endl;
	cout << "3. Print queue" << endl;
	cout << "4. Enqueue sentence" << endl;
	cout << "5. Quit" << endl;
}