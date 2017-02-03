#include <string>

using namespace std;

struct word {
	int count;
	std::string w;
};

class WordAnalysis{
	private:
		int timesDoubled;
		word *words;
		int wordCount;
		int index;
		void doubleArrayAndAdd(std::string);
		bool checkIfCommonWord(std::string);
		void sortData();
	public:
		bool readDataFile(char*); //returns an error if file not opened
		int getWordCount();
		int getUniqueWordCount();
		int getArrayDoubling();
		void printCommonWords(int);
		WordAnalysis(int);
		~WordAnalysis();
};
