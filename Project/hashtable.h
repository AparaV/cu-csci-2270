#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

class HashTable {
public:
	HashTable(int size, bool chains);
	~HashTable();
	void insert(Player* player); // calls appropriate collision algorithm
	int search(std::string key); // returns number of linear traversals
	int collisions;
	int operations;
private:
	void insertOA(int index, Player* player); // open addressing
	void insertCH(int index, Player* player); // chaining
	int searchOA(std::string key);
	int searchCH(std::string key);
	int hash(std::string key); // hash sum function
	Player** players;
	int tableSize;
	bool chaining;
};

#endif // !HASHTABLE_H

