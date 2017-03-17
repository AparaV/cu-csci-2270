/*
	Heap
	====
		Complete binary tree
		All levels are full except the bottom ~ every node has 2 children

		1. Min heap
			Value of node < values of children
		2. Max heap
			Value od node > values of children

	Building heap
	-------------
		Position in heap is set by position in array

		For each element in array:
			element at index 0 is the root of heap
			element at position x has:
				left child at position at 2x + 1
				right child at position at 2x + 1

		Example: Array (unsorted) to binary tree
			[10, 03, 02, 13, 14, 05, 06, 40, 34, 07]
			  0   1   2   3   4   5   6   7   8   9

			                   10
						 03           02
					 13      14   05      06
				   40  37  07
			Reorder the array into a heap-max heap

		buildHeap(A) {
			for (int x = A.length/2 - 1; x >= 0; --x) {
				maxHeapify(A, x);
			}
		}

		maxHeapify(A, x) {
			//moves individual element into correct position

			left = 2*x + 1; //indices
			right = 2*x + 2;
			largest = x;

			//finding the largest value amongst x, left and right
			if (left < A.length && A[left] > A[largest]) {
				largest = left;
			}
			if (right < A.length && A[right] > A[largest]) {
				largest = right;
			}

			//swap
			if (largest != x) {
				swap(A[x], A[largest]);
				maxHeapify(A, largest);
			}

		}

	Heap Sort
	---------
	
	heapSort(A) {
		buildHeap(A);
		heapSize = A.length - 1;
		while (heapSize > 0) {
			swap(A[heapSize], A[0]);
			heapSize--;
			maxHeapify(A, 0, heapSize);
		}
	}

*/