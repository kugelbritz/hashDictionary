#include <stdio.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include "hashTable.h"
using namespace std;

hashTable::hashTable()
{
	//Create the hash boxes
	for (int t = 0; t < BOXES;t++) {
		hash[t] = new entry;
		hash[t]->word = "n/a";
		hash[t]->nxt = NULL;
	}
}

int hashTable::hashFunction(string s)
{
	s[0] = (tolower(s[0])); //lowercase that first letter
	int i = (int)s[0] % BOXES; //convert first character to hash integer
	return i; //return hash number
}



void  hashTable::insertKey(string s)
{
	int pos = hashFunction(s);

	//if it's a new index in dictionary
	if ((*hash[pos]).word == "n/a") {
		(*hash[pos]).word = s;
		//cout << "New Entry Added.";
	}
	else {
		entryPtr e = hash[pos];
		entryPtr inHand = new entry;
		(*inHand).word = s;
		(*inHand).nxt = NULL;
		while ((*e).nxt != NULL) {
			e = (*e).nxt; //pass along the pointer to get to the last slot
		}		
		(*e).nxt = inHand;	
	}
}

int hashTable::searchDict(string w)
{
	for (int i = 0; i < BOXES; i++) {
		entryPtr e = hash[i];
		while (e != NULL) {
			if ((*e).word == w) {
				return 1;
				break;
			}
			else {
				e = (*e).nxt;
				continue;
			}
		}
	}
	return 0;
}

void hashTable::suggestWords(string t)
{	
	for (int i = 0; i < BOXES; i++) {
		entryPtr e = hash[i];
		while (e != NULL) {
			if ( ((*e).word[0] == t[0]) && ((*e).word[1] == t[1]) && ((*e).word != t) ) {
				cout << (*e).word << "\n";
				e = (*e).nxt;
			}
			else {
				e = (*e).nxt;
			}
		}
	}
}
