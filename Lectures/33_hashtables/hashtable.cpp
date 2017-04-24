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
      Two strings: "Go cat go"
                   "Go dog go"
        sum of both strings = 754
      This creates a collision

      Challenge with hashtables:
        * Write a good hash function to minimize colllisions
        * Have a good collision resolution algorithm
*/
