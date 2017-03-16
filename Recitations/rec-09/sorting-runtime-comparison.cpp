/*
	According to my findings, quick sort is the fastest algorithm.
	This was followed by insertion sort, selection sort and bubble sort.
	I used three tests to determine the fastest algorithm:
		1. Number of swaps
		2. Number of iterations
		3. The runtime
	The number of swaps and iterations did not really give a conclusive result.
	So I timed each algorithm for two different array sizes: 7 and 100000
	
	Runtime Chart (averaged over three different random arrays)
	===========================================================

	Algorithm        |    Array size 7    |    Array size 100000
	---------------------------------------------------------------
	Quick Sort       |         0 ms       |              0 ms
	Insertion Sort   |         0 ms       |          14000 ms
	Selection Sort   |         0 ms       |          15000 ms
	Bubble Sort      |         0 ms       |          44000 ms

	Clearly Quick Sort outperforms the other 3 algorithms by a large amount
	Insertion and Selection sort are of comparable run times with insertion sort
	having an edge over selection sort
	Bubble sort is the most naive and slow algorithm out of the 4.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 100000;

void quickSort(int arr[], int left, int right, int64_t* swaps, int64_t* loops) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
		(*loops)++;
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
    };
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j, swaps, loops);
    if (i < right)
        quickSort(arr, i, right, swaps, loops);
}

void selectSort(int arr[], int n, int64_t* swaps, int64_t* loops) {

  int index_min_value;
  int temp;
  for (int i=0; i<n-1; i++) {
  // outer loop tracks the sorted portion of the list
    index_min_value = i; //set index_min_value to the current index of array
    for (int j=i+1; j < n; j++) // inner loop finds the next smallest value
    {
      if (arr[j] < arr[index_min_value])
        index_min_value = j;

    }
    if (index_min_value != i) {
      temp = arr[i];
      arr[i] = arr[index_min_value];
      arr[index_min_value] = temp;
	  (*swaps)++;
    }
	(*loops)++;
  }
}

void insertionSort (int arr[], int length, int64_t* swaps, int64_t* loops) {
  int j, temp;
  for (int i = 0; i < length; i++)  {
      j = i;
      while (j > 0 && arr[j] < arr[j-1]) {
      // move elements over until find the position for next element
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
		(*swaps)++;
		(*loops)++;
      }
	  (*loops)++;
  }
}

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void bubbleSort(int arr[], int n, int64_t* swaps, int64_t* loops) {
	
	int i, j;
	for (i = 0; i < n-1; i++) {// Last i elements are already in place
		(*loops)++;
		for (j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				(*swaps)++;
			}
			(*loops)++;
		}
	}
}


void printList(int arr[], int length){
  for (int i = 0; i<length; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//generate random array
int* randArray(int size) {
	srand(time(0));
	int* a = new int[size];
	for (int i = 0; i < size; ++i) {
		a[i] = rand();
	}
	return a;
}

//copy array
int* copyArray(int* a, int size) {
	int* b = new int[size];
	for (int i = 0; i < size; ++i) {
		b[i] = a[i];
	}
	return b;
}

int main(){
  //HINT: You should place a counter into each algorithm to see how many time each of them run. Then you can compare them easier. 
  //You should use the given print statements for better organization. 

  int myArray1[] = {12, 13, 5, 4, 7, 18, 9 };
  int myArray2[] = {12, 13, 5, 4, 7, 18, 9 };
  int myArray3[] = {12, 13, 5, 4, 7, 18, 9 };
  int myArray4[] = {12, 13, 5, 4, 7, 18, 9 };
  int* largeArray1 = randArray(SIZE);
  int* largeArray2 = copyArray(largeArray1, SIZE);
  int* largeArray3 = copyArray(largeArray1, SIZE);
  int* largeArray4 = copyArray(largeArray1, SIZE);
  int64_t swaps, loops;
  double time;
  clock_t start, end;

  //selectSort
  swaps = 0;
  loops = 0;
  cout << "Selection sort" << endl << "===========" << endl;
  start = clock();
  selectSort(myArray1, 7, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << 7 << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  swaps = 0;
  loops = 0;
  start = clock();
  selectSort(largeArray1, SIZE, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << SIZE << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  cout << endl;

  //insertionSort
  swaps = 0;
  loops = 0;
  cout << "Insertion sort" << endl << "===========" << endl;
  start = clock();
  insertionSort(myArray2, 7, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << 7 << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  swaps = 0;
  loops = 0;
  start = clock();
  insertionSort(largeArray2, SIZE, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << SIZE << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  cout << endl;

  //bubbleSort
  swaps = 0;
  loops = 0;
  cout << "Bubble sort" << endl << "===========" << endl;
  start = clock();
  bubbleSort(myArray3, 7, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << 7 << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  swaps = 0;
  loops = 0;
  start = clock();
  bubbleSort(largeArray3, SIZE, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << SIZE << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  cout << endl;

  //quickSort
  swaps = 0;
  loops = 0;
  cout << "Quick sort" << endl << "===========" << endl;
  start = clock();
  quickSort(myArray4, 0, 6, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << 7 << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  swaps = 0;
  loops = 0;
  start = clock();
  quickSort(largeArray4, 0, SIZE - 1, &swaps, &loops);
  end = clock();
  time = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000.0);
  cout << "Array size: " << SIZE << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Loops: " << loops << endl;
  cout << "Time: " << time << " ms" << endl;
  cout << endl;

  return 0;
}
