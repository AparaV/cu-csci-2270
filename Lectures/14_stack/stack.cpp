/*
	Stacks
	======

	Add and remove at top

	 - push(value)
	 - pop()
	
	Array

		if top == 0
			array empty
		if top == maxSize
			array full

	Linked List

		if top == NULL
			list empty

	Stack {
	private:
		top
		data
		maxSize
	public:
		Stack()
		~Stack()
		isFull()
		isEmpty()
		push(value)
		pop()
	}

*/

/*
	Array Implementation

	push(value)
		if (!isFull())
			data[top] = value
			top++
		else
			cout << "Stack Full" << endl

	pop()
		if (!isEmpty())
			top--
			return data[top]

*/