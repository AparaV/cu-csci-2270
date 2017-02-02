/*

  Write a C++ function to double the size of an array an arbitrary number of times.
  The function takes three arguments - the initial 1D array, its size, and the number of times to double it.
  The function should dynamically create the new array to be 2x the size of the array argument,
  copy the contents into the new array, and for the second half of the array,
  create new values by doing 2*the values in the first half of the array, then delete the original array.
  Repeat this process for the specified number of times, then return the new array.

  int *ArrayDynamicAllocation(int array[], int size, int number)

  Helpful Hints:
    For an input array argument with a size of 2, you should
    // create the array and double it which gives an array of: NULL NULL NULL NULL
    // to double an array: int* newArray = new int [2*size];
    //using a loop: for( i = 0 to size-1)
    //copy the current array to the new array which give an array of: 0 1 NULL NULL
    //copy first half of new array to second half which gives an array of: 0 1 0 1
    //second half 2*old values which gives an array of: 0 1 0 2
    //and follow the remaining directions.

*/

int* ArrayDynamicAllocation(int array[], int size, int number){
    for (int i = 0; i < number; ++i) {
        size *= 2;
        int* temp = new int[size];
        for (int j = 0; j < size / 2; ++j) {
            temp[j] = array[j];
            temp[j + size / 2] = 2 * array[j];
        }
        delete[] array;
        array = temp;
    }
    return array;
}
