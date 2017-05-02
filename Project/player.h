/** CSCI 2270 Project: Hash Table Performance Evalutation
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Author: Aparajithan Venkateswaran
 **
 ** player.h
 ** Definition of Player and Team structs
 */

#ifndef PLAYER_H
#define PLAYER_H

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

#endif // !PLAYER_H
