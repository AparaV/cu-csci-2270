/*
	Computer Memory
		Two types

	1. Stack:
		* Managed by the OS as program runs.
		* Local variables are stored here
		* 	void f(){
				int x;
			}
		* Scope of x is f - memory assigned to x is freed after f completes
		
		Stack space is limited

	2. Heap:
		* Large pool of free memory ( >>> stack)
		* Varaible created dynamically during runtime
		* Need pointers to access heap variables
		* Memory management done by developer
		* Allocated memory needs to be explicitly deallocated
			new = allocate
			delete = deallocate
		Use heap for large arrays and objects


	Stack:
		int x;
		int* p = &x;

	Heap:
		int* x = new int; 
		int* y = new int[10];

		delete x;
		delete []y;

	Allocate array memory:
		int* x = new int[2];
		x[0] = 0;
		x[1] = 1;
		x = new int[3]; //creates memory leak

		int* x = new int[2];
		x[0] = 0;
		x[1] = 1;
		delete x;
		x = new int[3];

*/