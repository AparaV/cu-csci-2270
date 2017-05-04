/** CSCI 2270 Project: Hash Table Performance Evalutation
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Author: Aparajithan Venkateswaran
 **
 ** hashtable.h
 ** Contains declaration of hash table and associated Player and Team structs
 ** Defined and implemented in "hashtable.cpp"
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

// Team
struct Team {
	int year;
	int salary;
	std::string teamID;
	std::string leagueID;

	Team(int y = -1, std::string t = "", std::string l = "", int s = -1) {
		year = y;
		teamID = t;
		leagueID = l;
		salary = s;
	}
};

// Player
struct Player {
	std::string firstName;
	std::string lastName;
	std::string country;
	std::string key;
	std::string id;
	int yearBorn;
	int weight;
	int height;
	bool batsRight;
	bool throwsRight;
	std::vector<Team> teams;
	Player* next;

	Player(std::string fn, std::string ln, std::string c, std::string pid, int birth, int wt, int ht, bool bR, bool tR) {
		firstName = fn;
		lastName = ln;
		key = firstName + lastName;
		country = c;
		id = pid;
		yearBorn = birth;
		weight = wt;
		height = ht;
		batsRight = bR;
		throwsRight = tR;
		next = NULL;
	}
};

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
	int hash(std::string key); // hashing function
	bool playedFor(Player* player, std::string team); // check whether the player played for this team
	void displayPlayer(Player* player);
	Player** players;
	int tableSize;
	bool chaining;
};

#endif // !HASHTABLE_H
