#pragma once
#define BOXES 26
#include <list>
#include <iostream>
#include <string>
using namespace std;


class hashTable {
private:
	typedef struct entry {
		string word; //word
		entry *nxt = NULL;
	} *entryPtr; 

	entryPtr hash[BOXES];
public:
	int hashFunction(string s);
	hashTable();
	void insertKey(string s);
	int searchDict(string w);
	void suggestWords(string t);
};
