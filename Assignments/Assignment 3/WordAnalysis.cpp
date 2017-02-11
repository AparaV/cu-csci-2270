/** CSCI 2270-110  Data Structures
** Instructor: Rhonda Hoenigman
** TA: Yang Li
** Assignment 03
** Author: Aparajithan Venkateswaran
*/

#include <fstream>
#include <iostream>
#include <algorithm>
#include "WordAnalysis.h"

//Constructor
WordAnalysis::WordAnalysis(int n) {
	words = new word[n];					//Initializing variables
	wordCount = n;
	index = 0;
	timesDoubled = 0;
}

//Destructor
WordAnalysis::~WordAnalysis() {
	delete[] words;							//Deallocate memory
}

//Adding word to array and doubling when neccessary
void WordAnalysis::doubleArrayAndAdd(string value) {
	
	for (int i = 0; i < index; ++i) {		//Check if word already exists
		if (words[i].w == value) {
			words[i].count++;
			return;
		}
	}
	
	if (index == wordCount) {				//Double array if neccessary
		wordCount *= 2;
		word* temp = new word[wordCount];

		for (int i = 0; i < wordCount / 2; ++i) {
			temp[i].w = words[i].w;
			temp[i].count = words[i].count;
		}
		delete[] words;
		words = temp;
		timesDoubled++;
	}
	
	words[index].w = value;					//Add new word
	words[index].count = 1;
	index++;

	return;
}

//Check if word is common
bool WordAnalysis::checkIfCommonWord(string value) {
	string commonwords[50] = { "the", "be", "to", "of", "and", "a", "in", "that", "have", "i",
		"it", "for", "not", "on", "with", "he", "as", "you", "do", "at", "this", "but", "his",
		"by", "from", "they", "we", "say", "her", "she", "or", "an", "will", "my", "one", "all",
		"would", "there", "their", "what", "so", "up", "out", "if", "about", "who", "get", "which", "go", "me" };
	for (int i = 0; i < 50; ++i) {
		if (commonwords[i] == value) {
			return true;
		}
	}
	return false;
}

//Sort data - bubble sort
void WordAnalysis::sortData() {
	for (int i = 0; i < index - 1; ++i) {
		for (int j = 0; j < index - i - 1; ++j) {
			if (words[j].count < words[j + 1].count) {
				int count = words[j].count;
				string w = words[j].w;
				words[j].count = words[j + 1].count;
				words[j].w = words[j + 1].w;
				words[j + 1].count = count;
				words[j + 1].w = w;
			}
		}
	}
	return;
}

//Read file
bool WordAnalysis::readDataFile(char* fname) {
	ifstream file;
	file.open(fname);
	if (file.fail()) {
		return false;
	}

	string currentWord;
	while (getline(file, currentWord, ' ')) {
		//Strip newline
		currentWord.erase(std::remove(currentWord.begin(), currentWord.end(), '\n'), currentWord.end());
		if (checkIfCommonWord(currentWord) || currentWord == "") {
			continue;
		}
		doubleArrayAndAdd(currentWord);
	}
	sortData();

	return true;
}

//Get total word count
int WordAnalysis::getWordCount() {
	int total = 0;
	for (int i = 0; i < index; ++i) {
		total += words[i].count;
	}
	return total;
}

//Get total unique words
int WordAnalysis::getUniqueWordCount() {
	return index;
}

//Get number of times array was doubled
int WordAnalysis::getArrayDoubling() {
	return timesDoubled;
}

//Print top common words
void WordAnalysis::printCommonWords(int k) {
	if (k > index) {
		k = index;
	}
	for (int i = 0; i < k; ++i) {
		std::cout << words[i].count << " - " << words[i].w << std::endl;
	}
	return;
}