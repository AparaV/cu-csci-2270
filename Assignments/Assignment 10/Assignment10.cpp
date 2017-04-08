/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 10
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.h"

using namespace std;

void displayMenu(); //menu

int main(int argc, char** argv) {

	bool running = true;
	MovieTree netflix;
	string fileName = argv[1];

	//open file
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		cout << "Could not open file\n";
		return -1;
	}

	//initialize red black tree
	string movie;
	while (getline(file, movie, '\n')) {
		stringstream components;
		//cout << movie << endl;
		components << movie;
		int ranking, year, quantity, count = 1;
		string title;
		//split into components
		while (getline(components, movie, ',')) {
			if (count == 1) {
				ranking = stoi(movie);
			}
			else if (count == 2) {
				title = movie;
			}
			else if (count == 3) {
				year = stoi(movie);
			}
			else if (count == 4) {
				quantity = stoi(movie);
			}
			count++;
		} // end of splitting into components
		netflix.addMovieNode(ranking, title, year, quantity);
	} // end of initialization

	//close file
	file.close();

	/*bool valid = netflix.isValid();
	if (!valid) {
		return -1;
	}*/

	//start program
	while (running) {
		char choice;
		string movieTitle;
		displayMenu();
		cin >> choice;
		//switch
		switch (choice) {
		//find movie
		case '1':
			cout << "Enter title:" << endl;
			getchar();
			getline(cin, movieTitle);
			netflix.findMovie(movieTitle);
			break;
		//rent movie
		case '2':
			cout << "Enter title:" << endl;
			getchar();
			getline(cin, movieTitle);
			netflix.rentMovie(movieTitle);
			break;
		//print inventory
		case '3':
			netflix.printMovieInventory();
			break;
		//delete movie
		case '4':
			cout << "Enter title:" << endl;
			getchar();
			getline(cin, movieTitle);
			netflix.deleteMovieNode(movieTitle);
			break;
		//count movies
		case '5':
			cout << "Tree contains: " << netflix.countMovieNodes() << " movies." << endl;
			break;
		//count longest path
		case '6':
			cout << "Longest Path: " << netflix.countLongestPath() << endl;
			break;
		//quit
		case '7':
			cout << "Goodbye!" << endl;
			running = false;
			break;
		//otherwise
		default:
			break;
		} // end of switch
	} // end of program

	return 0;
} // end of main function

//Display menu
void displayMenu() {
	cout << "======Main Menu======" << endl;
	cout << "1. Find a movie" << endl;
	cout << "2. Rent a movie" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Delete a movie" << endl;
	cout << "5. Count the movies" << endl;
	cout << "6. Count the longest path" << endl;
	cout << "7. Quit" << endl;
} // end of menu