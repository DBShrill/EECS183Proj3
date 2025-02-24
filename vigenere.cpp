/*
 * vigenere.cpp
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
 * encrypts or decrypts messages using vigenere cipher
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    keyword = removeNonAlphas(keyword);
    keyword = toUpperCase(keyword);

    //Defines ascii value of 'A' (the first letter)
    const int FIRSTLETTERASCII = 65;


    if (encrypt) {
        int counter = 0;
        for (int i = 0; i < original.size(); i++) {
            if (isalpha(original.at(i))) {
                //modulo of size of keyword to cycle through keyword, preventing out of bounds error
                //counter tracks which instances of original are actually alphanumeric so to increment key correctly
                int key = static_cast<int>(keyword.at(counter % keyword.size())) - FIRSTLETTERASCII;

                //shifts character by key value
                original.at(i) = shiftAlphaCharacter(original.at(i), key);

                //only increments counter of index if original is a character
                counter++;
            }
        }
    }

    else {
        int counter = 0;
        for (int i = 0; i < original.size(); i++) {
            if (isalpha(original.at(i))) {
                int key = static_cast<int>(keyword.at(counter % keyword.size())) - FIRSTLETTERASCII;
                //shifts character by key
                original.at(i) = shiftAlphaCharacter(original.at(i), -key);
                counter++;
            }
        }
    }

    return original;
}
