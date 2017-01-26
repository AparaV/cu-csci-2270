#include<iostream>
using namespace std;

//code for findItem pseudocode 
/*The function needs to have a return type. Here, it's an integer. The
 * function arguments also need a type, we're using an integer array,
 * and two integers. We added a third parameter to the function call to
 * be the length of the array. We didn't need this in our pseudo code, 
 * but in the implementation in C++, we need it.
 */ 
int findItem(int A[], int v, int length){ //A is the array, and v is the value to find
  int index = -1;
  /*Indexing in the for loop starts at 0, instead of 1 in the pseudocode*/
  //The {} offset what's in the function, for loop, or conditional
  for(int i = 0; i < length; i++){
    if(A[i] == v){
      index = i;
	}
  }
  //The value the function produces is signified with the word return
  return index;
}
/* This lecture is about calculating cost of an algorithm, and we want
 * to know how many times we go into a loop, or how many times a conditional
 * is true. We can do this by adding code to our code to count when 
 * something is true. This might seem a little strange because we're 
 * adding code to count code, but then not counting our counter code.
 * Ultimately, what we'll get to in this class is determining what 
 * matters most with a cost, and we'll see that these single code lines
 * matter much less than times through a for loop, or times through
 * multiple for loops. We'll view these counter lines as constants and
 * not worry about them.
 * 
 * There are extra counts in this code to match the cost we calculate
 * in the pseudocode. For next week's assignment, you'll want to simplify
 * these counts, and we'll talk more about that in the next lecture.
 */
int findItemWCounter(int A[], int v, int length){ //A is the array, and v is the value to find
  int counter = 0; //we don't count this line
  int index = -1;
  counter++; //don't count this line
  for(int i = 0; i < length; i++){
	counter+=2; //this counts the for and the if
    if(A[i] == v){
      index = i;
      counter++; //don't count this line
	}
  }
  counter++; //we're just counting the return
  cout<<"op count: "<<counter<<endl;
  return index;
}
/*Code to remove an item and shift everything to fill the gap. This 
 * isn't the most efficient way to do this. This algorithm also doesn't
 * work for all inputs. When the input has multiple instances of the 
 * value we're searching for right next to each other, the algorithm
 * breaks. For example, an input of <34, 34, 45, 46> and a search of 34,
 * would produce <34, 45, 46, 0>. 
 */ 
void removeItem(int A[], int v, int length){
	for(int i = 0; i < length; i++){
		if(A[i] == v){
			for(int j = i; j < length - 1; j++){
				A[j] = A[j+1];
			}
			A[length-1] = 0;
		}
	}
}

int main(){

	int A[4] = {45, 34, 32, 34};
	int i = findItem(A, 34, 4); 
	cout<<"index: "<<i<<endl;
	i = findItem(A,25,4);
	cout<<"index: "<<i<<endl;
	int A2[7] = {45, 34, 32, 34, 56, 23, 12};
	i = findItem(A2, 34, 7); // = 1+7+7+2+1=18
	cout<<"index: "<<i<<endl;
	
	i = findItemWCounter(A, 34, 4); //= 1+4+4+2+1=12, item found in the array
	cout<<"index: "<<i<<endl;
	i = findItemWCounter(A, 25, 4); //1+4+4+0+1=10, item not found in the array
	cout<<"index: "<<i<<endl;
	i = findItemWCounter(A2, 25, 7); //1+7+7+0+1=16, item not found in the array
	cout<<"index: "<<i<<endl;
	i = findItemWCounter(A2, 34, 7); //1+7+7+2+1=18, item found in the array
	cout<<"index: "<<i<<endl;
	int A3[] = {45, 45, 45, 45, 45, 45, 45};
	i = findItemWCounter(A3, 45, 7);//1+7+7+7+1=23
	cout<<"index: "<<i<<endl;
	
	int A4[4] = {34, 36, 34, 34};
	removeItem(A4, 34, 4);
	for(int i = 0; i < 4; i++)
		cout<<A4[i]<<endl;

}
