/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 05
** Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include "CommunicationNetwork.h"

using namespace std;

void displayMenu();					//Print main menu

int main(int argc, char* argv[]) {


	CommunicationNetwork america;
	bool running = true;
	char choice;
	char* fileName = argv[1];

	while (running) {
		string cityNew;
		string cityPrevious;

		displayMenu();
		cin >> choice;
		switch (choice) {
		//Building network
		case '1':
			america.buildNetwork();
			break;
		//Printing network path
		case '2':
			america.printNetwork();
			break;
		//Transmitting message
		case '3':
			america.transmitFile(fileName);
			break;
		//Adding city
		case '4':
			cout << "Enter a city name: " << endl;
			getchar();	//Ignore newline character
			getline(cin, cityNew);
			cout << "Enter a previous city name: " << endl;
			getline(cin, cityPrevious);
			america.addCity(cityPrevious, cityNew);
			break;
		//Deleting city
		case '5':
			cout << "Enter a city name: " << endl;
			getchar();
			getline(cin, cityNew);
			america.deleteCity(cityNew);
			break;
		//Clearing network
		case '6':
			america.deleteNetwork();
			break;
		//Quitting
		case '7':
			cout << "Goodbye!" << endl;
			running = false;
			break;
		default:
			break;
		}
	}

	return 0;
}

//Print main menu
void displayMenu() {
	cout << "======Main Menu======" << endl;
	cout << "1. Build Network" << endl;
	cout << "2. Print Network Path" << endl;
	cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
	cout << "4. Add City" << endl;
	cout << "5. Delete City" << endl;
	cout << "6. Clear Network" << endl;
	cout << "7. Quit" << endl;
}