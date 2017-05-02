#include <iostream>
#include "hashtable.h"

using namespace std;

// constructor
HashTable::HashTable(int size, bool chains) {
	tableSize = size;
	chaining = chains;
	collisions = 0;
	operations = 0;
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
int HashTable::search(string key) {
	// chaining
	if (chaining) {
		return searchCH(key);
	}
	// open addressing
	else {
		return searchOA(key);
	}
}

// open addressing
void HashTable::insertOA(int index, Player* player) {
	//check if index is empty
	if (players[index] == NULL) {
		players[index] = player;
	}
	//check if spot is taken by same player
	else if (players[index]->firstName == player->firstName && players[index]->lastName == player->lastName && players[index]->yearBorn == player->yearBorn) {
		players[index]->teams.push_back(player->teams[0]);
	}
	//loop through to find next empty spot
	else {
		collisions++;
		int i = index;
		bool found = false;
		index++;
		//check until NULL is encountered and wrap around
		while (players[index] != NULL && index != i) {
			operations++;
			//if already present
			if (players[index]->firstName == player->firstName && players[index]->lastName == player->lastName && players[index]->yearBorn == player->yearBorn) {
				players[index]->teams.push_back(player->teams[0]);
				found = true;
			}
			index++;
			if (index == tableSize) {
				index = 0;
			}
		}
		if (!found) {
			players[index] = player;
		}
	}

}

// chaining
void HashTable::insertCH(int index, Player* player) {
	//if spot is empty
	if (players[index] == NULL) {
		players[index] = player;
	}
	else {
		Player* temp = players[index];
		// if the first item is same player, just add the team
		if (player->firstName == temp->firstName && player->lastName == temp->lastName && player->yearBorn == temp->yearBorn) {
			temp->teams.push_back(player->teams[0]);
		}
		else {
			collisions++;
			// loop and find right spot
			while (temp->next != NULL && player->key > temp->key) {
				temp = temp->next;
				operations++;
			}
			// if player already exists at the same spot
			if (player->firstName == temp->firstName && player->lastName == temp->lastName && player->yearBorn == temp->yearBorn) {
				temp->teams.push_back(player->teams[0]);
			}
			// if player is to be inserted before temp
			else if (player->key <= temp->key) {
				player->next = temp;
				player->prev = temp->prev;
				if (temp->prev != NULL) { //if a previous element exists
					temp->prev->next = player;
				}
				else { //otherwise set the players[index] to new player
					players[index] = player;
				}
				temp->prev = player;
			}
			// otherwise
			else {
				player->next = temp->next;
				temp->next = player;
				player->prev = temp;
			}
		}
	}
}

// open addressing search
int HashTable::searchOA(string key) {
	int index = hash(key);
	//check if index is empty
	if (players[index] == NULL) {
		cout << "Player not found" << endl;
		return 0;
	}
	//check if index contains same player
	if (players[index]->key == key) {
		return 0;
	}
	//loop until NULL is enocuntered, if NULL is encountered, player doesn't exist
	else {
		int count = 0;
		int i = index;
		index++;
		while (players[index] != NULL && index != i) {
			count++;
			if (players[index]->key == key) {
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
int HashTable::searchCH(string key) {
	int index = hash(key); //get hash
	// check if spot is used
	if (players[index] == NULL) {
		cout << "Player not found" << endl;
		return 0;
	}
	// check if the spot is being taken by same player
	else if (players[index]->key == key) {
		return 0;
	}
	// otherwise loop through the linked list
	else {
		int count = 1;
		Player* temp = players[index];
		while (temp != NULL && temp->key < key) { //we're sorting in alphabetical order
			temp = temp->next;
			count++;
		}
		if (temp == NULL || temp->key != key) {
			cout << "Player not found" << endl;
		}
		else {
		}
		return count;
	}
}

// hash sum function
int HashTable::hash(string key) {
	int sum = 0;
	for (int i = 0; i < key.size(); ++i) {
		sum += key[i];
	}
	return sum % tableSize;
}
