//    Complexity
//        Upper bound on the runtime of algorithm

/*
    Sorting algorithm
        Trade-offs: Memory, runtime requirements

    Bubble sort

        for i = 0 to A.end - 1
            for j = 0 to A.end - i - 1
                if (A[j] > A[j+1])
                    swap A[j] and A[j+1]
*/

#include <iostream>

using namespace std;

void bubbleSort(int*, int);

int main(){

    int A[4] = {45, 44, 32, 23};
    int length = 4;

    bubbleSort(A, length);

    for (int i = 0; i < 4; ++i){
        cout << A[i] << " ";
    }

    //Pointer - variable that points to an address / reference to an address

    int a = 5;
    int* b = &a; //b points to a; address of a is stored in b

    return 0;
}

//Bubble sort
void bubbleSort(int A[], int length){

    for(int i = 0; i < length - 1; ++i){
        for(int j = 0; j < length - i - 1; ++j){
            if (A[j] > A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    return;
}
