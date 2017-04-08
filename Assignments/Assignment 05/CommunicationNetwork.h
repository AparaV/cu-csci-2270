/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 05
** Author: Aparajithan Venkateswaran
*/

#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
struct City{
    std::string cityName;
    std::string message;
    City *next;
    City *previous;

    City(){}; // default constructor

    City(std::string initName, City *initNext, City *initPrevious, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addCity(std::string, std::string);
        void buildNetwork();
        void transmitMsg(std::string);
		void transmitFile(char*);		//this is like a string
        void printNetwork();
        void deleteCity(std::string);
        void deleteNetwork();
    protected:
    private:
        City *head;
        City *tail;
};

#endif // COMMUNICATIONNETWORK_H
