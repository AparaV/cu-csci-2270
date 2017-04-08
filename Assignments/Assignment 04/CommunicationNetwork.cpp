/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 04
** Author: Aparajithan Venkateswaran
*/

#include <iostream>
#include "CommunicationNetwork.h"

using namespace std;

//Constructor
CommunicationNetwork::CommunicationNetwork() {
	head = NULL;
	tail = NULL;
}

//Destructor
CommunicationNetwork::~CommunicationNetwork() {
	head = NULL;
	tail = NULL;
}

//Add city
void CommunicationNetwork::addCity(string cityName, string previousCity) {
	//Create new city
	City* newCity = new City(cityName, NULL, "");
	City* current = head;

	//If linked list is empty
	if (head == NULL) {
		head = newCity;
		tail = newCity;
		return;
	}

	//If city is to be added to the head of list
	if (previousCity == "First") {
		newCity->next = head;
		head = newCity;
		return;
	}

	//Find the correct position
	while (current->next != NULL) {
		if (current->cityName == previousCity) {
			break;
		}
		current = current->next;
	}

	//If previous city is not found
	//add to the end of list
	if (current->next == NULL) {
		current->next = newCity;
		tail = newCity;
		return;
	}

	//Insert node
	newCity->next = current->next;
	current->next = newCity;
}

//Build Network
void CommunicationNetwork::buildNetwork() {
	//Creating new cities
	City* LA = new City("Los Angeles", NULL, "");
	City* Phoenix = new City("Phoenix", NULL, "");
	City* Denver = new City("Denver", NULL, "");
	City* Dallas = new City("Dallas", NULL, "");
	City* StLouis = new City("St. Louis", NULL, "");
	City* Chicago = new City("Chicago", NULL, "");
	City* Atlanta = new City("Atlanta", NULL, "");
	City* WDC = new City("Washington, D.C.", NULL, "");
	City* NY = new City("New York", NULL, "");
	City* Boston = new City("Boston", NULL, "");

	//Linking cities
	head = LA;
	LA->next = Phoenix;
	Phoenix->next = Denver;
	Denver->next = Dallas;
	Dallas->next = StLouis;
	StLouis->next = Chicago;
	Chicago->next = Atlanta;
	Atlanta->next = WDC;
	WDC->next = NY;
	NY->next = Boston;
	tail = Boston;

	//Print network
	printNetwork();
}

//Transmit Message
void CommunicationNetwork::transmitMsg(char* msg) {
	City* current = head;

	if (current == NULL) {
		cout << "Empty list" << endl;
		return;
	}

	//Traverse list
	current->message = msg;
	while (current->next != NULL) {
		cout << current->cityName << " received " << current->message << endl;
		current->message = "";
		current = current->next;
		current->message = msg;
	}
	cout << current->cityName << " received " << current->message << endl;
}

//Print network
void CommunicationNetwork::printNetwork() {
	cout << "===CURRENT PATH===" << endl;
	
	//Traverse List
	City* temp = head;
	while (temp != NULL) {
		cout << temp->cityName << " -> ";
		temp = temp->next;
	}

	cout << "NULL" << endl;
	cout << "==================" << endl;
}