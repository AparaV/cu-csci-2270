/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 06
** Author: Aparajithan Venkateswaran
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue
{
    public:
        Queue(int);
        ~Queue();
        //circular queue methods
        void enqueue(std::string);
        std::string dequeue(); //should send through network, call transmit msg
        void printQueue();
        bool queueIsFull(); //send when full
        bool queueIsEmpty(); //send when empty

    protected:
    private:
        int queueSize;
        int queueHead;
        int queueTail;
        int queueCount;
        std::string *arrayQueue;
};

#endif // QUEUE_H
