#include "utilities.h"

string getWord() {
	string word;
	cout << "Please enter a string for an anagram (!exit to quit): ";
	cin >> word;
	return word;
}
string getFileName() {
	string file_name;
	cout << "Enter in a file name to use as your dictionary (for default one, type \'default\'): ";
	cin >> file_name;
	if (file_name == "default")
		file_name = "dictionary.txt";
	return file_name;
}
string shiftLeft(string word) {
	if (word.size() > 0)
		return word.substr(1, word.size()) + word[0]; //substr(1) gives everything after the first character, +word[0] adds the first char to the end
	else return word;
}
void Loop(ifstream &file, bool &match) {
	string word = getWord();
	if (word == "!exit")
		return;
	AnagramCheck(file, word, match);
	if (match == false)
		cout << "No matches found." << endl;
	match = false;
	file.clear();
	file.seekg(0, file.beg);
	Loop(file, match);
}
void AnagramCheck(ifstream &file, string word, bool &match) {
	string dictionaryWord;
	if (!(file >> dictionaryWord))
		return;
	if (word.length() == dictionaryWord.length() && PermutationCheck(word, dictionaryWord, match)) {
		match = true;
		cout << "match found: " << dictionaryWord << endl;
	}
	AnagramCheck(file, word, match);
}
bool PermutationCheck(string word, string dictionaryWord, bool &match) {
	static int counter;
	if (counter > word.size()) {
		counter = 0;
		return false;
	}
	if (word.size() == 0) {
		counter = 0;
		return true;
	}
	if (word[0] == dictionaryWord[0]) {
		dictionaryWord = dictionaryWord.substr(1, dictionaryWord.size() - 1); //remove first letter of dictionaryWord		
		word = word.substr(1, word.size() - 1); //remove first letter of word
		PermutationCheck(word, dictionaryWord, match);
	}
	else {
		dictionaryWord = shiftLeft(dictionaryWord); //rotate dictionaryWordle string right once
		counter++;
	}
	return PermutationCheck(word, dictionaryWord, match);
}
