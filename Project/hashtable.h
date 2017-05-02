/** CSCI 2270 Project: Hash Table Performance Evalutation
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Author: Aparajithan Venkateswaran
 **
 ** hashtable.h
 ** Contains declaration of hash table
 ** Defined and implemented in "hashtable.cpp"
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

class HashTable {
public:
	HashTable(int size, bool chains); // chooses whether to chain or open address collisions
	~HashTable();
	void insert(Player* player); // calls appropriate collision algorithm
	int search(std::string key, std::string team); // returns number of linear traversals
	int collisions;
	int operations;
	int uniqueValues;
private:
	void insertOA(int index, Player* player); // open addressing
	void insertCH(int index, Player* player); // chaining
	int searchOA(std::string key, std::string team); // open addressing
	int searchCH(std::string key, std::string team); // chaining
	int hash(std::string key); // hash sum function
	bool playedFor(Player* player, std::string team); // check whether the player played for this team
	Player** players;
	int tableSize;
	bool chaining;
};

#endif // !HASHTABLE_H

