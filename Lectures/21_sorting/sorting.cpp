/*
	Algorithmic approach
	====================

	Divide and Conquer
		Divide problem into smaller problems
		solve smaller problems
		fewer iterations over the entire data set

	Quicksort
	=========
		Recursive
		Divide array into smaller arrays using a partition value called pivot.
		Values <= pivot move left of pivot
		Values > pivot move right of pivot

		Conquer - recursively divide and sort partitions until smaller sorted arrays build larger sorted array

	quicksort(A, left, right) {			//A is array, left and right are indices
		i = left;
		j = right;
		pivot = A[(left + right) / 2];
		while (i <= j) {
			//find value greater than pivot
			while (A[i] < pivot) {
				i++;
			}
			//find first value lesser than pivot
			while (A[j] > pivot) {
				j--;
			}
			if (i <= j) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i++;
				j--;
			}
		}
		if (left < j) {
			quicksort(A, left, j);
		}
		if (i < right) {
			quicksort(A, i, right);
		}
	}

*/