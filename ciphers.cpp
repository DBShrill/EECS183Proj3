/*
 * ciphers.cpp
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
 * code that asks user for inputs and encrypts or decrypts messages based on input and type of cipher
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void ciphers() {
    string cipherChoice;
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherChoice);
    char cipherChoiceChar = toUpperCase(cipherChoice).at(0);

    //checks for invalid cipher selections (not caesar, vigenere, or polybius)
    if (cipherChoiceChar != 'C' && cipherChoiceChar != 'V' && cipherChoiceChar != 'P') {
        cout << "Invalid cipher!";
        return;
    }

    string encryptChoice;
    bool isEncrypt;
    cout << endl << "Encrypt or decrypt: ";
    getline(cin, encryptChoice);

    encryptChoice = toUpperCase(encryptChoice).at(0);

    //checks if user wants to encrypt or decrypt
    if (encryptChoice == "E") {
        isEncrypt = true;
    }

    else if (encryptChoice == "D") {
        isEncrypt = false;
    }

    //exit if user doesn't input encrypt or decrypt
    else {
        cout << "Invalid mode!";
        return;
    }

    string message;
    cout << endl << "Enter a message: ";
    getline(cin, message);

    //if polybius message is not alphanumeric or space, return error
    if (cipherChoiceChar == 'P') {
        message = toUpperCase(message);
        for (int i = 0; i < message.size(); i++) {
            if (!isdigit(message.at(i)) && !isalpha(message.at(i)) && message.at(i) != ' ') {
                cout << "Invalid message!";
                return;
            }
        }
    }

    string key;
    cout << endl << "What is your key: ";
    getline(cin, key);

    //returns error if vigenere key doesnt have at least one alphabetical character
    if (removeNonAlphas(key).length() < 1 && cipherChoiceChar == 'V') {
        cout << "Invalid key!";
        return;
    }

    //if polybius key has any nonalphanumeric characters, return error
    if (cipherChoiceChar == 'P') {
        key = removeDuplicate(toUpperCase(key));
        for (int i = 0; i < key.size(); i++) {
            if (!isdigit(key.at(i)) && !isalpha(key.at(i))) {
                cout << "Invalid key!";
                return;
            }
        }
    }

    //checks which cipher was chosen given encrypt
    if (isEncrypt) {
        string encryptedMessage;
        if (cipherChoiceChar == 'C') {
            encryptedMessage = caesarCipher(message, stoi(key), true);
        }

        else if (cipherChoiceChar == 'V') {
            encryptedMessage = vigenereCipher(message, key, true);
        }

        else if (cipherChoiceChar == 'P') {
            char grid[SIZE][SIZE];
            encryptedMessage = polybiusSquare(grid, key, toUpperCase(message), true);
        }

        cout << "The encrypted message is: " << encryptedMessage;
    }

    //checks which cipher was chosen given decrypt
    else if(!isEncrypt) {
        string decryptedMessage;

        if (cipherChoiceChar == 'C') {
            decryptedMessage = caesarCipher(message, stoi(key), false);
        }

        else if (cipherChoiceChar == 'V') {
            decryptedMessage = vigenereCipher(message, key, false);
        }

        else if (cipherChoiceChar == 'P') {
            char grid[SIZE][SIZE];
            decryptedMessage = polybiusSquare(grid, key, toUpperCase(message), false);
        }

        cout << "The decrypted message is: " << decryptedMessage;
    }
}