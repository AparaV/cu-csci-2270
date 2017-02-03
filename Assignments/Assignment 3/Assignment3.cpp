#include <iostream>
#include "WordAnalysis.h"
using namespace std;

// main expects 1 argument, filename
int main(int argc, char* argv[])
{
    char* filename = argv[1];
    int n = atoi(argv[2]);
	
    WordAnalysis wa(100);
    
    if(wa.readDataFile(filename)) {
        //print common words
        wa.printCommonWords(n);
        
        cout << "#" << endl;
        //timesDoubled returned from WordAnalysis
        cout << "Array doubled: "<< wa.getArrayDoubling() << endl;
        
        // display the output
        cout << "#" << endl;
        //nonCommonWords returned from WordAnalysis
        cout<<"Unique non-common words: "<< wa.getUniqueWordCount() <<endl;
        
        cout<<"#"<<endl;
        //totalWords returned from WordAnalysis
        cout<<"Total non-common words: "<< wa.getWordCount() <<endl;
        // free the final array

    }
    
    return 0;
}

