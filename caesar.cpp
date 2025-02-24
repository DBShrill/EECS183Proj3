/*
 * caesar.cpp
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
 */

#include "caesar.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

char shiftAlphaCharacter(char c, int n) {
    const int ALPHABETSIZE = 26;
    //checks of char c is upper or lowercase and if n puts it out of range
    if (n > 0) {
        //modulo of n by NUMALPHABET because alphabet loops every 26 characters
        //if letter goes above 'z' or 'Z' after shift, loops back to beginning and adds remainder
        if (c + (n % ALPHABETSIZE) > 'z' && c <= 'z' || c + (n % ALPHABETSIZE) > 'Z' && c <= 'Z') {
            c -= ALPHABETSIZE;
        }
        return c + (n % ALPHABETSIZE);
    }
    else if (n < 0) {
        //same as above but in the other direction
        if (c - (-n % ALPHABETSIZE) < 'a' && c <= 'z'  && c >= 'a'|| c - (-n % ALPHABETSIZE) < 'A' && c <= 'Z' && c >= 'A') {
            return c - (-n % ALPHABETSIZE) + ALPHABETSIZE;
        }
        return c - (-n % ALPHABETSIZE);
    }

    else {
        return c;
    }
}

string caesarCipher(string original, int key, bool encrypt) {
    if (encrypt) {
        for (int i = 0; i < original.size(); i++) {
            //checks if value is a letter and not a number
            if (isalpha(original.at(i)) && !isdigit(original.at(i))) {
                //shifts character by key
                original.at(i) = shiftAlphaCharacter(original.at(i), key);
            }
        }
    }

    else {
        for (int i = 0; i < original.size(); i++) {
            if (isalpha(original.at(i)) && !isdigit(original.at(i))) {
                original.at(i) = shiftAlphaCharacter(original.at(i), -key);
            }
        }
    }

    return original;
}
