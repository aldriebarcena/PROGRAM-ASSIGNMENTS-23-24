#include "WordEntry.h"
#include "WordEntry.h"

// constructor that creates a word entry
WordEntry::WordEntry(const string &text, int score)
 : word(text), numAppearances(1), totalScore(score) {
	 
}

// adds onto total score and increments it's numAppearances
void WordEntry::addNewAppearance(int s) {
	totalScore += s;
	++numAppearances;
}

// returns word
const string & WordEntry::getWord() const {
    return word;
}

// returns avg
double WordEntry::getAverage() const {
	return static_cast<double>(totalScore) / numAppearances;
}
