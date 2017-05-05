/** CSCI 2270 Project: Hash Table Performance Evalutation
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Author: Aparajithan Venkateswaran
 **
 ** hashtable.cpp
 ** Contains implementation of class declared in "hashtable.h"
 */

#include <iostream>
#include "hashtable.h"

using namespace std;

// constructor
HashTable::HashTable(int size, bool chains) {
	tableSize = size;
	chaining = chains;
	collisions = 0;
	operations = 0;
	uniqueValues = 0;
	// allocate memory and initialize
	players = new Player*[tableSize];
	for (int i = 0; i < tableSize; ++i) {
		players[i] = NULL;
	}
}

// destructor
HashTable::~HashTable() {
	delete[] players;
}

// insert
void HashTable::insert(Player* player) {
	int index = hash(player->key);
	// chaining
	if (chaining) {
		insertCH(index, player);
	}
	// open addressing
	else {
		insertOA(index, player);
	}
}

// search
int HashTable::search(string key, string team) {
	// chaining
	if (chaining) {
		return searchCH(key, team);
	}
	// open addressing
	else {
		return searchOA(key, team);
	}
}

// open addressing
void HashTable::insertOA(int index, Player* player) {
	//check if index is empty
	if (players[index] == NULL) {
		players[index] = player;
		uniqueValues++;
	}
	//check if spot is taken by same player
	else if (players[index]->id == player->id) {
		players[index]->teams.push_back(player->teams[0]);
	}
	//loop through to find next empty spot
	else {
		int i = index;
		bool found = false;
		index++;
		if (index == tableSize) {
			index = 0;
		}
		//check until NULL is encountered and wrap around
		while (players[index] != NULL && index != i) {
			operations++;
			//if already present
			if (players[index]->id == player->id) {
				players[index]->teams.push_back(player->teams[0]);
				found = true;
				break;
			}
			index++;
			if (index == tableSize) {
				index = 0;
			}
		}
		if (!found) {
			players[index] = player;
			uniqueValues++;
			collisions++;
		}
	}
}

// chaining
void HashTable::insertCH(int index, Player* player) {
	//if spot is empty
	if (players[index] == NULL) {
		players[index] = player;
		uniqueValues++;
	}
	else {
		Player* temp = players[index];
		// if the first item is same player, just add the team
		if (player->id == temp->id) {
			temp->teams.push_back(player->teams[0]);

		}
		else {
			bool found = false;
			// loop and find if player already exists
			while (temp->next != NULL) {
				// player already exists
				if (player->id == temp->id) {
					temp->teams.push_back(player->teams[0]);
					found = true;
					break;
				}
				temp = temp->next;
				operations++;
			}
			// player already exists
			if (player->id == temp->id) {
				temp->teams.push_back(player->teams[0]);
				found = true;
			}
			// player doesn't exist - add to end of linked list
			else {
				temp->next = player;
				uniqueValues++;
				collisions++;
			}
		}
	}
}

// open addressing search
int HashTable::searchOA(string key, string team) {
	int index = hash(key);
	//check if index is empty
	if (players[index] == NULL) {
		cout << "Player not found" << endl;
		return 0;
	}
	//check if index contains same player
	if (players[index]->key == key && playedFor(players[index], team)) {
		displayPlayer(players[index]);
		return 0;
	}
	//loop until NULL is enocuntered, if NULL is encountered, player doesn't exist
	else {
		int count = 0;
		int i = index;
		index++;
		while (players[index] != NULL && index != i) {
			count++;
			if (players[index]->key == key && playedFor(players[index], team)) {
				displayPlayer(players[index]);
				return count;
			}
			index++;
			if (index == tableSize) {
				index = 0;
			}
		}
		cout << "Player not found" << endl;
		return count;
	}
}

// chaining search
int HashTable::searchCH(string key, string team) {
	int index = hash(key); //get hash
	// check if spot is used
	if (players[index] == NULL) {
		cout << "Player not found" << endl;
		return 0;
	}
	// check if the spot is being taken by same player
	else if (players[index]->key == key && playedFor(players[index], team)) {
		displayPlayer(players[index]);
		return 0;
	}
	// otherwise loop through the linked list
	else {
		int count = 1;
		Player* temp = players[index];
		bool found = false;
		while (temp != NULL) {
			if (temp->key == key && playedFor(temp, team)) {
				displayPlayer(temp);
				found = true;
				break;
			}
			temp = temp->next;
			count++;
		}
		if (!found) {
			cout << "Player not found." << endl;
		}
		return count;
	}
}

// hash function
// adapted from http://stackoverflow.com/a/107657/5055644
int HashTable::hash(string key) {
	unsigned int hash = 0, seed = 101;
	for (int i = 0; i < key.length(); i++) {
		hash = (hash * seed) + key[i];
	}
	return hash % tableSize;
}

// check whether the player played for the team
bool HashTable::playedFor(Player* player, string team) {
	for (int i = 0; i < player->teams.size(); ++i) {
		if (player->teams[i].teamID == team) {
			return true;
		}
	}
	return false;
}

// print player information
void HashTable::displayPlayer(Player* player) {
	cout << "***" << endl;
	cout << "Name: " << player->firstName << " " << player->lastName << endl;
	cout << "Born: " << player->yearBorn << endl;
	cout << "Country: " << player->country << endl;
	cout << "Height: " << player->height << "    Weight: " << player->weight << endl;
	if (player->batsRight) {
		cout << "Bats: R";
	}
	else {
		cout << "Bats: L";
	}
	if (player->throwsRight) {
		cout << "    Throws: R" << endl;
	}
	else {
		cout << "    Throws: L" << endl;
	}
	cout << "Played for: " << endl;
	for (int i = 0; i < player->teams.size(); ++i) {
		cout << "\tTeam: " << player->teams[i].teamID << " League: " << player->teams[i].leagueID << endl;
		cout << "\tYear: " << player->teams[i].year << " Salary: $ " << player->teams[i].salary << endl;
	}
	cout << "***" << endl;
}
