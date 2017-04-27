/*
    Implement a C++ function to build a new hash table from an existing hash table using a new hash function called hashSum2.
    In the new hash table, insert the movies at the front of the linked list when the movies hash to the same index.

    Note: In the background, we handle building/inserting into the hash table by the hash function from your book.
    We also write the hashSum2 and you only will need to call it. You will need to use the newHashTable variable.

    void HashTable::createNewHashTable(); // You need to implement this function
    int hashSum2(std::string x, int s); // already defined. You will need to call this function in createNewHashTable()

    struct Movie{
    	std::string title;
    	Movie *next;
    	Movie(){};
    	Movie(std::string in_title){
    		title = in_title;
    		next = NULL;
    	}
    };

    class HashTable
    {
    	public:
    		HashTable();
    		~HashTable();
                    void createNewHashTable();
    	private:
    		int hashSum(std::string x, int tablesize);
    	      int hashSum2(std::string x, int s);
    		int tableSize;
    		Movie * hashTable[10];
    	      Movie * newHashTable[10];
    };

    // Returns hashSum2 of input string x by summing every other letter in string
    int HashTable::hashSum2(string inputString, int hashLen)
    {
        int sum = 0;
        for (int i = 0; i < inputString.length(); i++){
    	if(i%2==0)
    	    sum = sum + inputString[i];
        }
        sum = sum % hashLen;
        return sum;
    }
*/

void HashTable::createNewHashTable() {
    // set the pointers to NULL
    for(int i = 0; i < 10; ++i){
        newHashTable[i] = NULL;
    }

    for(int i = 0; i < 10; ++i){
        // if an element exists at that position
        if (hashTable[i] != NULL){
            Movie* temp = hashTable[i];
            // run through the entire linked list
            while (temp != NULL){
                Movie* newM = new Movie(temp->title);
                int key = hashSum2(newM->title, 10);
                // if key is empty, then next will be set to NULL
                // otherwise, we are adding to the beginning of the linked list
                newM->next = newHashTable[key];
                newHashTable[key] = newM;
                temp = temp->next;
            }
        }
    }
}
