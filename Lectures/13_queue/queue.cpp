/*
	Stacks and Queues
	=================

	Restrict which elements are accessed
	Store elements in array / linked list

	Stack
	-----
	 - Last In First Out (LIFO)
	 - Add and remove from top

	Queue
	-----
	 - First In First Out (FIFO)
	 - Remove from head and add at tail

	 - Enqueue (Add an element)
	 - Dequeue (Remove an element)

*/

/*
	Queue
	=====

	class Queue {
	private:
		head				//indices if array
		tail				//pointers if linked list
		data				//array or linked list
		currSize			//integer
		maxSize				//integer
		isEmpty()			//true when currSize == 0
		isFull()			//true when currSize == maxSize

	public:
		Queue()				//constructor
		enqueue(value)		//adding to queue
		dequeue()			//return value at head
	};

	Array implementation
		- Either shift entire array upon dequeue
		- Or just shift the head - trickier to implement; but much more efficient
		- Circular queue

	dequeue()
		if (!isEmpty())
			value = data[head]
			currSize--
			if (head == maxSize - 1)
				head = 0				//wrapping around - circular queue
			else
				head++
		else
			cout << "Queue Empty" << endl
		return value

	enqueue(value)
		if (!isFull())
			data[tail] = value
			currSize++
			if (tail == maxSize - 1)
				tail = 0				//wrapping around - circular queue
			else
				tail++
		else
			cout << "Queue Full" << endl


*/