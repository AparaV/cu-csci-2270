#include <iostream>
#include <random>
#include <exception>
#include <stdexcept>

using namespace std;

const int MIN = 1;
const int MAX = 100000000;
const int SIZE[13] = { 10, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000 };

//Protypes
int* randArray(int size);
int* copyArray(int* a, int size);
void printArray(int* a, int size);
void insertionSort(int* arr, int length, int64_t* swaps, int64_t* loops);
void quickSort(int* arr, int left, int right, int64_t* swaps, int64_t* loops);
void countingSort(int* arr, int size, int range, int64_t* swaps, int64_t* loops);

int main() {

	int* array1;
	int* array2;
	int* array3;
	int64_t loops, swaps;
	double runTime;
	clock_t startTime, endTime;

	//generate random arrays and compare them
	for (int i = 0; i < 13; ++i) {
		//initialize arrays and counters
		array1 = randArray(SIZE[i]);
		array2 = copyArray(array1, SIZE[i]);
		array3 = copyArray(array1, SIZE[i]);

		cout << "=================" << endl;
		cout << "ARRAY SIZE: " << SIZE[i] << endl;
		cout << "=================" << endl;

		//insertion sort
		if (SIZE[i] <= 500000) {
			loops = 0;
			swaps = 0;
			cout << "Insertion Sort" << endl;
			startTime = clock();
			insertionSort(array1, SIZE[i], &swaps, &loops);
			endTime = clock();
			runTime = static_cast<double>((endTime - startTime) / CLOCKS_PER_SEC * 1000.0);
			cout << "\tSwaps: " << swaps << "\n\tLoops: " << loops << endl;
			cout << "\tRuntime: " << runTime << " ms\n" << endl;
		}
		delete[] array1;

		//Quick sort
		swaps = 0;
		loops = 0;
		cout << "Quick Sort" << endl;
		startTime = clock();
		quickSort(array2, 0, SIZE[i] - 1, &swaps, &loops);
		endTime = clock();
		runTime = static_cast<double>((endTime - startTime) / CLOCKS_PER_SEC * 1000.0);
		cout << "\tSwaps: " << swaps << "\n\tLoops: " << loops << endl;
		cout << "\tRuntime: " << runTime << " ms\n" << endl;
		delete[] array2;

		//counting sort
		swaps = 0;
		loops = 0;
		cout << "Counting Sort" << endl;
		startTime = clock();
		countingSort(array3, SIZE[i], MAX, &swaps, &loops);
		endTime = clock();
		runTime = static_cast<double>((endTime - startTime) / CLOCKS_PER_SEC * 1000.0);
		cout << "\tSwaps: " << swaps << "\n\tLoops: " << loops << endl;
		cout << "\tRuntime: " << runTime << " ms\n" << endl;
		delete[] array3;

	} // end comparison

	return 0;
}

//Generate random array
int* randArray(int size) {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> range(MIN, MAX);

	int* a = new int[size];
	for (int i = 0; i < size; ++i) {
		a[i] = range(generator);
	}
	return a;
} // end of generating random array

//Copy array
int* copyArray(int* a, int size) {
	int* b = new int[size];
	for (int i = 0; i < size; ++i) {
		b[i] = a[i];
	}
	return b;
} // end of copying array

//Print array
void printArray(int* a, int size) {
	for (int i = 0; i < size; ++i) {
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

//Insertion sort
//Code modified from Recitation 9
void insertionSort(int* arr, int length, int64_t* swaps, int64_t* loops) {
	int j, temp;
	for (int i = 0; i < length; i++) {
		j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			// move elements over until find the position for next element
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
			(*swaps)++;
			(*loops)++;
		}
		(*loops)++;
	}
} // end of insertion sort

//Quick sort
//Code modified from Recitation 9
void quickSort(int* arr, int left, int right, int64_t* swaps, int64_t* loops) {
	int i = left, j = right, tmp;
	int pivot = arr[(left + right) / 2];

	//Partition
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
			(*loops)++;
		}
		while (arr[j] > pivot) {
			j--;
			(*loops)++;
		}
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
			(*swaps)++;
		}
		(*loops)++;
	}; // end of partition

	//Recursion
	if (left < j) {
		quickSort(arr, left, j, swaps, loops);
	}
	if (i < right) {
		quickSort(arr, i, right, swaps, loops);
	} // end of recursion
} // end of quick sort

//Counting sort
//Code built based on following pseudo-code: http://www.albany.edu/~csi503/pdfs/handout_9.1.pdf
void countingSort(int* arr, int size, int range, int64_t* swaps, int64_t* loops) {
	int* counter = new int[range + 1];
	int* temp = new int[size];
	fill(counter, counter + range, 0);

	for (int j = 0; j < size; ++j) {
		counter[arr[j]]++;
		(*loops)++;
	}
	for (int i = 1; i <= range; ++i) {
		counter[i] += counter[i - 1];
		(*loops)++;
	}
	for (int j = 0; j < size; ++j) {
		if (counter[arr[j]] > 0) {
			temp[counter[arr[j]] - 1] = arr[j];
			counter[arr[j]]--;
		}
		(*loops)++;
	}
	for (int j = 0; j < size; ++j) {
		arr[j] = temp[j];
		(*loops)++;
		(*swaps)++;
	}
	
	delete[] counter;
	delete[] temp;
} // end of counting sort