/*  Implement the Insertion Sort algorithm. Write a function called InsertionSort that takes an array
	and the length of the array and sorts the items out in increasing order.
	The function needs to print out the partially sorted array after each iteration of the for loop.

	void InsertionSort(int array[], int len);

	To print out the elements after each iteration of the for loop use the following format:
		for(int z = 0; z<len; z++)
			cout<<array[z]<< " ";
		cout<<"\n";
 */

void InsertionSort(int arr[], int len) {
	for (int i = 1; i < len; ++i) {
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = temp;
		//print array
		for (int k = 0; k < len; ++k) {
			cout << arr[k] << " ";
		}
		cout << "\n";
	}
	return;
}