/*
    Question 01
    
    Write a C++ function that removes all products in the array of structs with price that matches with given argument 'target'.
    Each time an element is removed, the array should be shifted to fill the gap.
    The function should return the size of the array after removing the matches. 

    struct Product {
        string pname;
        int price;
    };

    Use the following function header:

    int ShiftArray(Product arr[],int size,int target)
*/

int ShiftArray(Product arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].price == target) {
            size--;
            for (int j = i; j < size; ++j) {
                arr[j].pname = arr[j + 1].pname;
                arr[j].price = arr[j + 1].price;
            }
        }
    }
    return size;
}

/*
    Question 02

    Write a C++ function that returns the most common repeating element in an array of structs.
    The function takes two arguments - the input array of structs and the size of the array, and returns the most common product name.

    struct Product {
        string pname;
        int price;
    };

    Use the following function header:

    string commonRepeatingElement(Product arr[],int length)
*/

string commonRepeatingElement(Product arr[], int length) {
    Product* dict = new Product[length];
    int csize = 0;
    for (int i = 0; i < length; ++i) {
        bool found = false;
        for (int j = 0; j < csize; ++j) {
            if (dict[j].pname == arr[i].pname) {
                dict[j].price++;
                found = true;
                break;
            }
        }
        if (!found) {
            dict[csize].pname = arr[i].pname;
            dict[csize].price = 1;
            csize++;
        }
    }
    
    int max = 0;
    string answer;
    for (int i = 0; i < csize; ++i) {
        if (dict[i].price > max) {
            max = dict[i].price;
            answer = dict[i].pname;
        }
    }
    
    return answer;
}

/*
    Question 03

    Write a C++ function to copy all elements of an array to a new array, except for a specified value, and return the new array. 

    Use the following function header:

    int *CopyArray(int array[], int length, int value)
*/

int* CopyArray(int array[], int length, int value) {
    int* newArray = new int[length];
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] == value) {
            continue;
        }
        newArray[index] = array[i];
        index++;
    }
    return newArray;
}

/*
    Question 04

    Write a C++ function to find the second largest element in an array.
    The function takes two arguments - the input array and the size of the array, and returns the second largest element. 

    Use the following function header:

    int secondLargest(int arr[],int size);
*/

int secondLargest(int arr[], int size) {
    int max2 = 0;
    for (int i = 0; i < 2; ++i) {
        int cmax = arr[0];
        int index = 0;
        for(int j = 1; j < size - i; ++j) {
            if (arr[j] > cmax) {
                cmax = arr[j];
                index = j;
            }
        }
        if (i == 1) {
            max2 = cmax;
            break;
        }
        int temp = arr[size - i - 1];
        arr[size - i - 1] = arr[index];
        arr[index] = temp;
    }
    return max2;
}