/*
 *	Write a function that enqueues a node in a circular queue.
 *
 *	void cQueue::enqueue(int value);
 *	If the queue is full print out "Queue Full" and return;
 *
 *	The function is a member of a class called Queue.
 *	Write the function definition only for enqueue.
 *	Given below is the class definition:
 *
 *		class cQueue
 *		{
 *			public:
 *				cQueue(int max);
 *				virtual ~cQueue();
 *				void enqueue(int value);
 *				int getTail();
 *				void displayQueue();
 *			protected:
 *			private:
 *				int *c_array;
 *				int head;
 *				int tail;
 *				int size;
 *		};
 *
 *	Head and Tail are initialized as follow:
 *		head  = -1;
 *		tail = -1;
 *
 */

void cQueue::enqueue(int value) {
	//Check whether queue is full
	if (tail - head == size - 1 || head - tail == size - 1) {
		cout << "Queue Full" << endl;
	}
	else {
		//initialize head during the first enqueue
		if (head == tail && head == -1) {
			head = 0;
		}
		//wrap around array
		if (tail == size - 1) {
			tail = -1;
		}
		tail++;
		c_array[tail] = value;
	}
	return;
}