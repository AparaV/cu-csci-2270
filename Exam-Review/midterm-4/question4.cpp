/*
Implement a C++ function to build a hash table using a new hash function.
In the hash table, insert movies at the end of the linked list for movies that hash to the same index.
The buildHashTable function takes two arguments: an array of strings and the length of the array. newHashSum takes two parameters :  a string and the tablesize.
newHashSum should add ASCII values of characters at even indices in the string and then return the remainder when divided by tablesize.
Hint: To find if an index is even, check if the remainder when divided by 2 is 0.(index%2)

For example:
If the string is "ABCD", it should add ASCII values of A and C and then return the remainder when divided by tableSize(10).

You need to implement two functions for this question:

void HashTable::buildHashTable(string movies[], int length);
int HashTable::newHashSum(string inputString, int hashLen);
*/

struct Movie{
	std::string title;
	Movie *next;
	Movie(){};
	Movie(std::string in_title)
	{
		title = in_title;
		next = NULL;
	}

};

class HashTable
{
	public:
		HashTable();
		~HashTable();
                void buildHashTable(string movies[], int length);
	private:
		int newHashSum(std::string x, int s);
		int tableSize;
		Movie * hashTable[10];
};

/* Solution */
int HashTable::newHashSum(string inputString, int hashLen){
    int sum = 0;
    for(unsigned int i = 0; i < inputString.size(); i += 2){
        sum += inputString[i];
    }
    return sum % hashLen;
}

void HashTable::buildHashTable(string movies[], int length){
    for(int i = 0; i < tableSize; ++i){
        hashTable[i] = NULL;
    }
    for(int i = 0; i < length; ++i){
        Movie* newM = new Movie(movies[i]);
        int index = newHashSum(newM->title, tableSize);
        if (hashTable[index] == NULL){
            hashTable[index] = newM;
        }
        else{
            Movie* curr = hashTable[index];
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = newM;
        }
    }
}
