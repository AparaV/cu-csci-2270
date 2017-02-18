/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 04
** Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "CommunicationNetwork.h"

using namespace std;

void displayMenu();										//Display main menu

int main() {
	
	bool running = true;
	char userInput;
	char* temp;
	string fname = "messageIn.txt";
	ifstream file;
	string word;
	string cityNew;
	string cityPrevious;
	CommunicationNetwork america;

	while (running) {
		displayMenu();
		cin >> userInput;

		switch (userInput) {
		//Building network
		case '1':
			america.buildNetwork();
			break;
		//Printing network
		case '2':
			america.printNetwork();
			break;
		//Transmitting message
		case '3':
			file.open(fname.c_str());
			if (file.fail()) {
				cout << "Error" << endl;
				break;
			}
			while (getline(file, word, ' ')) {
				word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());	//Strip newline character
				//Copy to char*
				temp = new char[word.size() + 1];
				strcpy(temp, word.c_str());
				america.transmitMsg(temp);
				delete[] temp;
			}
			file.close();
			break;
		//Adding new city
		case '4':
			cout << "Enter a city name: " << endl;
			getchar();	//Ignore newline character
			getline(cin, cityNew);
			cout << "Enter a previous city name: " << endl;
			getline(cin, cityPrevious);
			america.addCity(cityNew, cityPrevious);
			break;
		//Quit loop
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

//Display main menu
void displayMenu() {
	cout << "======Main Menu======" << endl;
	cout << "1. Build Network" << endl;
	cout << "2. Print Network Path" << endl;
	cout << "3. Transmit Message Coast-To-Coast" << endl;
	cout << "4. Add City" << endl;
	cout << "5. Quit" << endl;
}