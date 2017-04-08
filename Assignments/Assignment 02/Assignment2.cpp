/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 02
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Struct words
struct Words {
	string word;
	unsigned int count = 0;
};

//Prototypes
Words* doubleArray(Words*, int*);			//array doubling
bool isCommon(string);						//presence of element
void addWord(Words*, string, int*, int*);	//adding word or incrementing counter
void sort(Words*, int);						//sort all words
unsigned int sumWords(Words*, int);			//find total number of words

//Main function begins
int main(int argc, char** argv) {

	int n = stoi(argv[2]);

	char* filename = argv[1];
	ifstream file;
	file.open(filename);
	if (file.fail()) {
		cout << "Error opening file!" << endl;
		return 1;
	}

	string word;
	int length = 100;
	Words* book = new Words[length];
	int currsize = 0;

	int arrayDoubled = 0;

	while (getline(file, word, ' ')) {
		//resizing array
		if (currsize >= length) {
			book = doubleArray(book, &length);
			arrayDoubled++;
		}
		word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());
		if (isCommon(word) || word == "") {
			continue;
		}
		addWord(book, word, &currsize, &length);
	}

	sort(book, currsize);
	int totalWords = sumWords(book, currsize);

	/*Printing output*/
	//Most frequent terms
	for (int i = 0; i < n; ++i) {
		cout << book[i].count << " - " << book[i].word << endl;
	}
	cout << "#" << endl;
	//Array doubling
	cout << "Array doubled: " << arrayDoubled << endl;
	cout << "#" << endl;
	//Unique non-common words
	cout << "Unique non-common words: " << currsize << endl;
	cout << "#" << endl;
	//Total non-common words
	cout << "Total non-common words: " << totalWords << endl;



	return 0;
}
//Main function ends

//Array doubling
Words* doubleArray(Words* a, int* length) {
	Words* temp = new Words[2 * (*length)];
	
	for (int i = 0; i < *length; ++i) {
		temp[i].word = a[i].word;
		temp[i].count = a[i].count;
	}
	(*length) *= 2;
	delete[] a;

	return temp;
}

//Presence of element
bool isCommon(string value) {
	string commonwords[50] = { "the", "be", "to", "of", "and", "a", "in", "that", "have", "i",
		"it", "for", "not", "on", "with", "he", "as", "you", "do", "at",
		"this", "but", "his", "by", "from", "they", "we", "say", "her", "she",
		"or", "an", "will", "my", "one", "all", "would", "there", "their", "what",
		"so", "up", "out", "if", "about", "who", "get", "which", "go", "me" };
	for (int i = 0; i < 50; ++i) {
		if (commonwords[i] == value) {
			return true;
		}
	}
	return false;
}

//Adding word or incrementing counter
void addWord(Words* book, string word, int* currsize, int* length) {
	for (int i = 0; i < *currsize; ++i) {
		if (book[i].word == word) {
			book[i].count++;
			return;
		}
	}
	//if word is not already in the book
	book[*currsize].word = word;
	book[*currsize].count = 1;
	(*currsize)++;
	return;
}

//Sort all words
void sort(Words* book, int size) {

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (book[j].count < book[j + 1].count) {
				int count = book[j].count;
				string word = book[j].word;
				book[j].count = book[j + 1].count;
				book[j].word = book[j + 1].word;
				book[j + 1].count = count;
				book[j + 1].word = word;
			}
		}
	}

	return;
}

unsigned int sumWords(Words* book, int size) {
	unsigned int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += book[i].count;
	}
	return sum;
}