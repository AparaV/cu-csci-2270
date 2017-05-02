#include <iostream>
#include <fstream>
#include <sstream>
#include "hashtable.h"
#include "player.h"

using namespace std;

void initialize(string fileName, HashTable* hashCH, HashTable* hashOA);
void menu();

int main(int argc, char** argv) {

	int hashSize = 5147;
	if (argc == 2) {
		hashSize = stoi(argv[1]);
	}

	string fileName = "playerData";
	HashTable hashCH(hashSize, true);
	HashTable hashOA(hashSize, false);
	initialize(fileName, &hashCH, &hashOA);
	cout << "Hash table size: " << hashSize << endl;
	cout << "Collisions using open addressing: " << hashOA.collisions << endl;
	cout << "Search operations using open addressing: " << hashOA.operations << endl;
	cout << "Collisions using chaining: " << hashCH.collisions << endl;
	cout << "Search operations using chaining: " << hashCH.operations << endl;

	bool running = true;
	while (running) {
		menu();
		char input;
		cin >> input;
		if (input == '1') {
			string firstN, lastN, key;
			cout << "Enter first name:" << endl;
			getchar();
			cin >> firstN;
			cout << "Enter last name:" << endl;
			getchar();
			cin >> lastN;
			key = firstN + lastN;
			int searchOperationsOA = hashOA.search(key);
			int searchOperationsCH = hashCH.search(key);
			cout << "Search operations using open addressing: " << searchOperationsOA << endl;
			cout << "Search operations using chaining: " << searchOperationsCH << endl;
		}
		else if (input == '2') {
			running = false;
		}
	}
	
	return 0;
}

void initialize(string fileName, HashTable* hashCH, HashTable* hashOA) {
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		cout << "Could not open file\n";
		return;
	}

	string line;
	bool first = true;
	while (getline(file, line, '\n')) {
		if (first) {
			first = false;
			continue;
		}
		else {
			stringstream components;
			components << line;
			int count = 1, year, salary, birth, weight, height;
			bool batsR, throwsR;
			string team, league, firstN, lastN, country;
			while (getline(components, line, ',')) {
				switch (count) {
				case 1:
					year = stoi(line);
					count++;
					break;
				case 2:
					team = line;
					count++;
					break;
				case 3:
					league = line;
					count++;
					break;
				case 5:
					salary = stoi(line);
					count++;
					break;
				case 6:
					firstN = line;
					count++;
					break;
				case 7:
					lastN = line;
					count++;
					break;
				case 8:
					birth = stoi(line);
					count++;
					break;
				case 9:
					country = line;
					count++;
					break;
				case 10:
					weight = stoi(line);
					count++;
					break;
				case 11:
					height = stoi(line);
					count++;
					break;
				case 12:
					if (line == "R") {
						batsR = true;
					}
					else {
						batsR = false;
					}
					count++;
					break;
				case 13:
					if (line == "R") {
						throwsR = true;
					}
					else {
						throwsR = false;
					}
					count++;
					break;
				default:
					count++;
					break;
				}
			}
			Player* newP = new Player(firstN, lastN, country, birth, weight, height, batsR, throwsR);
			Team* newT = new Team(year, team, league, salary);
			newP->teams.push_back(*newT);
			hashCH->insert(newP);
			hashOA->insert(newP);
		}
	}

	//close file
	file.close();
}

void menu() {
	cout << "1. Query hash table" << endl;
	cout << "2. Quit program" << endl;
}