#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getWord();
string getFileName();
string shiftLeft(string word);
void Loop(ifstream &file, bool &match);
void AnagramCheck(ifstream &file, string word, bool &match);
bool PermutationCheck(string word, string dictionaryWord, bool &match);

#endif