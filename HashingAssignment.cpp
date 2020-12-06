// HashingAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include "hashTable.h"
#include "TimeInterval.h"
using namespace std;

int main()
{
    hashTable callObj; //objects to call non static functions
    TimeInterval timer;

    timer.start();
    //Parse Dictionary.txt
    ifstream textfile;
    textfile.open("Dictionary.txt");            
    list<string> words;
    string word;
    if (!textfile.is_open()) {
         cout << "Cannot access the file, check location.";
    }
    else {
        while (getline(textfile, word, '\n'))
        {
            //Feed all of the words from a file into a list
            words.push_back(word);
            //Also put those words into the hash tableau        
            callObj.insertKey(word);
        }
    }
    textfile.close();
    bool continuity = true;
 //Prompt user for search key
    while (continuity) {
        cout << "Enter word to check if included in current dictionary:\t\n";
        string k;
        cin >> k;
        if (!callObj.searchDict(k)) {
            char ans;
            cout << "False\n";
            cout << "Would you like to add this word? (Y or N)\t";
            cin >> ans;
            if (ans == 'Y' || ans == 'y') {
                callObj.insertKey(k);
                cout << "Word Added\n";

            }
            else {
                cout << "Well then...\n";
                timer.stop();
                float count = timer.GetInterval();
                cout << count << "ms";
                continuity = false;
            }
        }
        else {
            cout << "True\n";
            callObj.suggestWords(k);
            timer.stop();
            float count = timer.GetInterval();
            cout << count << "ms";
            continuity = false;
        }
    }
    
    return 0;
    }
   
 


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
