/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 05
** Author: Aparajithan Venkateswaran
*/


#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//Constructor
CommunicationNetwork::CommunicationNetwork() {
	head = NULL;
	tail = NULL;
}

//Destructor
CommunicationNetwork::~CommunicationNetwork() {
	deleteNetwork();
	head = NULL;
	tail = NULL;
}

//Add city
void CommunicationNetwork::addCity(string prevCity, string cityName){
	City* temp = new City(cityName, NULL, NULL, "");

	//Empty list
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else if (prevCity == "First") {
		temp->next = head;
		head = temp;
		temp->next->previous = temp;
	}
	else {
		City* current = head;
		while (current->next != NULL) {
			//Middle
			if (current->cityName == prevCity) {
				temp->next = current->next;
				current->next = temp;
				temp->previous = current;
				temp->next->previous = temp;
				break;
			}
			current = current->next;
		}
		//Tail or previous city not found
		if (current->next == NULL) {
			current->next = temp;
			temp->previous = current;
			tail = temp;
		}
	}

}

//Build network
void CommunicationNetwork::buildNetwork(){
	City* LA = new City("Los Angeles", NULL, NULL, "");
	City* phoenix = new City("Phoenix", NULL, LA, "");
	City* denver = new City("Denver", NULL, phoenix, "");
	City* dallas = new City("Dallas", NULL, denver, "");
	City* stLouis = new City("St. Louis", NULL, dallas, "");
	City* chicago = new City("Chicago", NULL, stLouis, "");
	City* atlanta = new City("Atlanta", NULL, chicago, "");
	City* washington = new City("Washington, D.C.", NULL, atlanta, "");
	City* newYork = new City("New York", NULL, washington, "");
	City* boston = new City("Boston", NULL, newYork, "");

	head = LA;
	LA->next = phoenix;
	phoenix->next = denver;
	denver->next = dallas;
	dallas->next = stLouis;
	stLouis->next = chicago;
	chicago->next = atlanta;
	atlanta->next = washington;
	washington->next = newYork;
	newYork->next = boston;
	tail = boston;

	printNetwork();
}

//Transmit message
void CommunicationNetwork::transmitMsg(string msg){
	if (head == NULL) {
		cout << "Empty list" << endl;
		return;
	}
	
	City* current = head;
	current->message = msg;
	//Forward
	while (current->next != NULL) {
		cout << current->cityName << " received " << current->message << endl;
		current->next->message = current->message;
		current->message = "";
		current = current->next;
	}
	//Backward
	while (current->previous != NULL) {
		cout << current->cityName << " received " << current->message << endl;
		current->previous->message = current->message;
		current->message = "";
		current = current->previous;
	}
	cout << current->cityName << " received " << current->message << endl;
	current->message = "";
}

//Transmit File
void CommunicationNetwork::transmitFile(char* fileName) {
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		cout << "ERROR" << endl;
		return;
	}

	string msg;
	while (getline(file, msg, ' ')) {
		msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());	//Strip newline character
		transmitMsg(msg);
	}
	file.close();
}

//Print network
void CommunicationNetwork::printNetwork(){
	cout << "===CURRENT PATH===" << endl;

	if (head == NULL || tail == NULL) {
		cout << "NULL" << endl;
	}
	else {
		City* temp = head;
		cout << "NULL <- ";
		while (temp->next != NULL) {
			cout << temp->cityName << " <-> ";
			temp = temp->next;
		}
		cout << temp->cityName << " -> NULL" << endl;
	}

	cout << "==================" << endl;
}

//Delete city
void CommunicationNetwork::deleteCity(string cityName){
	if (head == NULL) {
		cout << cityName << " not found" << endl;
		return;
	}

	//Search for city
	City* city = head;
	while (city->next != NULL) {
		if (city->cityName == cityName) {
			break;
		}
		city = city->next;
	}
	if (city->next == NULL && city->cityName != cityName) {
		cout << cityName << " not found" << endl;
		return;
	}

	if (city == head) {
		head = head->next;
		head->previous = NULL;
		delete city;
	}
	else if (city == tail) {
		tail = city->previous;
		tail->next = NULL;
		delete city;
	}
	else {
		city->previous->next = city->next;
		city->next->previous = city->previous;
		delete city;
	}
}

//Delete network
void CommunicationNetwork::deleteNetwork(){
	if (head == NULL) {
		return;
	}

	City* current = head->next;
	while (current != NULL) {
		cout << "deleting " << head->cityName << endl;
		delete head;
		head = current;
		current = current->next;
	}
	cout << "deleting " << head->cityName << endl;
	delete head;
	head = NULL;
	tail = NULL;
}