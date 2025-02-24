/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * <#Names#>
 * daniel bao
 * <#Uniqnames#>
 * danbao
 *
 * EECS 183: Project 3
 * Winter 2025
 *
 * <#description#>
 * helper functions used for all ciphers
 */

#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string toUpperCase(string original) {
    //difference in value between upper and lowercase letters on ascii chart
    const int LOWERCASEOFFSET = 32;
    for (int i = 0; i < original.size(); i++){
        //if lowercase, move 32 ascii values back to uppercase
        if (original.at(i) >= 'a' && original.at(i) <= 'z'){
              original.at(i) -= LOWERCASEOFFSET;
        }
    }
    return original;
}

string removeNonAlphas(string original) {
    string cleanedString;
    for (int i = 0; i < original.size(); i++){
        //if a letter, append to new string with only alpha characters
        if (isalpha(original.at(i))){
            cleanedString += original.at(i);
        }
    }
    return cleanedString;
}

int charToInt(char original) {
    //zero starts at 48
    const int ZEROASCII = 48;

    //subtracting by ZEROASCII gives integer value of ascii character ('0' is 48, so '0' - 48 is 0 the integer)
    int originalInt = static_cast<int>(original) - ZEROASCII;

    return originalInt;
}

string removeDuplicate(string original) {
    string seen;
    for (int i = 0; i < original.size(); i++){
        //if index is not in seen string, add to seen string
        if (seen.find(original.at(i)) == string::npos){
        seen += original.at(i);
      }
    }
    return seen;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
