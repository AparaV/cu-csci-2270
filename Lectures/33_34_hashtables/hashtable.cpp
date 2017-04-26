/*
  Hash Tables
  ===========
    Uses paramter of data, called a key, to map to an array.

    Two components:
      1. Array where data is stored
      2. Hash function that generates the mapping

    Example:
      Movie:
        Title
        Ranking
        Year
    Title as the key. Convert the title to an int that will be array index.
    Use hash function

    Hash function:
      Sum values in string key and mod by array size

      // assumes tableSize is already set (size of array)
      // key is string
      hashSum(key, tableSize){
        sum = 0
        for x = 0 to key.end
          sum = sum + key[x]
        sum = sum % tableSum
        return sum
      }

    Example:
      title = "Whiplash"
      year = 2014
      ranking = 38

      convert "Whiplash" using sum of ascii values => sum = 832
      Mod sum by arraySize to generate valid array index
      sum % arraySize = 32
      Put whiplash at movies[32]

    Retrieve from hash table:
    1. Calculate hash code from the key
      search("Whiplash")
        index = hashSum("Whiplash", 50)
        return movies[index]

    Collisions:
      Two strings: "Go Cat go"
                   "Go Dog, go"
        sum of both strings = 754
      This creates a collision

      Challenge with hashtables:
        * Write a good hash function to minimize collisions
        * Have a good collision resolution algorithm

    Collision occurs when h(k1) = h(k2) where k1 != k2; k1, k2 are keys

    The perfect hash function:
        Assign all records to a unique location in the hash table
        And there is no wasted space
        Example: 100 phone numbers b/w 3034841000 to 3034841099
        Take last 3 digits and mod by 100 -> unique hash value

    Imperfect hash function:
        Multiple keys assigned to the same index
        Example: Same 100 numbers.
            Hash function = number mod 10 -> Get only the last digit

    To design to a proper/efficient hash function, we need some awareness of the data

    Just increasing table size won't necessarily help
    Example: Key is 10 UPPERCASE letters
        Range of data: 10 A's - lowest ASCII sum; 10 Z'a - highest ASCII sum ~ 650 to 900
        Range of data = 250
            Table size 1000:
                650 mod 1000 = 650
                900 mod 1000 = 900
            Table size 100:
                650 mod 100 = 50
                900 mod 100 = 0
        Table size matters
        If we have table size = 100, use more of table than table size of 1000, but won't use it equally

    Handling Collisions
    ===================
        1. Chaining
        2. Open Addressing

    1. Chaining
        Hash table is array of pointers. Init to NULL.
        When we add an element to the table, the pointer is updated to point to head of the linked list
        Additional elements are added to linked list
        Example: Movie titles are the key, add
            The Gofather = 1237 mod 7 = 5
            The Usual Suspects = 1733 mod 7 = 4
            Casablanca = 985 mod 7 = 5
            Whiplash = 832 mod 7 = 6
        Table size = 7. Use hash sum function. Linked list should be sorted
         #   Title
        00
        01
        02
        03
        04   Usual Suspects
        05   Casablanca -> Godfather
        06   Whiplash

        Algorithm
        ---------
        1. Create empty hash table, size 7
            Movie* m[7]
            // init to NULL
                m[i] = NULL
        2. Calculate hash for each movies
            int x = hashSum("The Godfather", 7)
        3. Check if key already in table
            search(value, x)
                if m[x] != NULL
                    Movie* temp = m[x]
                    while (temp != NULL)
                        if (temp->key == value)
                            return temp
                        else
                            temp = temp->next
                return NULL
            If something exists at that index, search entire LL for key.
            If !found, return NULL, otherwise return pointer to that node
        4. If search returns NULL, add it to table.
            If nothing is there at that index, add as the head of the linked list.
            If there is something, find correct (sorted) position in that linked list
            insert(value)
                x = hashSum(value, tableSize)
                //create node
                Movie* newM = new Movie
                newM->key = value
                newM->next = NULL
                if m[x] == NULL // nothing is stored
                    newM->previous = NULL
                    m[x] = newM
                else // something is already present
                    //find place in linked list
                    Movie* temp = m[x]
                    while (temp != NULL && newM->key > temp->key)
                        temp = temp->next
                    newM->next = temp
                    newM->previous = temp->previous
                    if (temp != NULL)
                        temp->next->previous = newM
                        temp->previous->next = newM
*/
