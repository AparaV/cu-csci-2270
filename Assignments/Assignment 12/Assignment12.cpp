/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 12
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Graph.h"

using namespace std;

void displayMenu(); // print menu options
Graph<string> createGraph(string filename); // get graph from file

int main(int argc, char** argv) {

	string filename = argv[1];
	Graph<string> zombieLand = createGraph(filename);
	bool running = true;

	while (running) {
		char choice;
		string city1;
		string city2;
		displayMenu();
		cin >> choice;

		switch (choice) {
			// print graph
		case '1':
			zombieLand.displayEdges();
			break;
			// connect graph
		case '2':
			zombieLand.connectGraph();
			break;
			// shortest path
		case '3':
			cout << "Enter a starting city:" << endl;
			getchar();
			getline(cin, city1);
			cout << "Enter an ending city:" << endl;
			getline(cin, city2);
			zombieLand.findShortestPath(city1, city2);
			break;
			// quit
		case '4':
			running = false;
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}

void displayMenu() {
	cout << "======Main Menu======" << endl;
	cout << "1. Print vertices" << endl;
	cout << "2. Find districts" << endl;
	cout << "3. Find shortest path" << endl;
	cout << "4. Quit" << endl;
}

Graph<string> createGraph(string filename) {
	ifstream file;
	Graph<string> map;

	file.open(filename);
	if (file.fail()) {
		cout << "Error while opening file" << endl;
		return map;
	}

	string line;
	vector<string> cities;
	bool firstRun = true;
	while (getline(file, line, '\n')) {

		stringstream components;
		components << line;

		if (firstRun) {
			while (getline(components, line, ',')) {
				if (line != "cities") {
					\
						cities.push_back(line);
					map.addVertex(line);
				}
			}
			firstRun = false;
		}
		else {
			string cityName;
			int count = -1;
			int weight;
			while (getline(components, line, ',')) {
				if (count == -1) {
					cityName = line;
				}
				else {
					weight = stoi(line);
					if (weight != -1) {
						map.addEdge(cityName, cities[count], weight);
					}
				}
				count++;
			}
		}
	}
	file.close();

	return map;
}
