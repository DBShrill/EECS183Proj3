/*
 * polybius.cpp
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
 * code for encrypted and decrypting polybius ciphers
 */


#include "polybius.h"
#include <string>
using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************
string mixKey(string key) {
    string alphanumeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    key = removeDuplicate(key);
    for (int i = 0; i < key.size(); i++) {
        int instance = alphanumeric.find(key.at(i));
        //if current character can be found in alphanumeric, erase
        if (instance != string::npos) {
            alphanumeric.erase(alphanumeric.begin() + instance);
        }
    }

    //returns the processed key with the remaining characters of alphanumeric
    return key + alphanumeric;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //fills grid with corresponding character at instance
            grid[i][j] = content.at(i * SIZE + j);
        }
    }
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string value;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //searches for character in grid and returns row and column indices
            if (grid[i][j] == c) {
                value += to_string(i) + to_string(j);
                return value;
            }
        }
    }
}

string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
   fillGrid(grid, mixKey(key));
   if (encrypt) {
       string encryptedMessage;
       for (int i = 0; i < original.size(); i++) {
           //if current character is not a space, find character in grid
           if (original.at(i) != ' ') {
               encryptedMessage += findInGrid(original.at(i), grid);
           }
           else {
               encryptedMessage += ' ';
           }
       }
       return encryptedMessage;
   }

   else {
       string unencrypted;
       //increments by two because letters consists of pairs of numbers
       for (int i = 0; i < original.size(); i += 2) {
           //if current character is space, skip it and add a space
           if (original.at(i) == ' ') {
               i++;
               unencrypted += ' ';
           }
           //column and row values of grid array assigned by first and second number in pair respectively
           int column = charToInt(original.at(i));
           int row = charToInt(original.at(i + 1));
           unencrypted += grid[column][row];
       }
       return unencrypted;
   }
}
