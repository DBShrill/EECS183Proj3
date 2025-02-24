//
// Created by Daniel Bao on 2/12/25.
//

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testShiftAlphaCharacter();
void testtoUpperCase();
void testremoveNonAlphas();
void testcharToInt();
void testremoveDuplicate();
void testshiftAlphaCharacter();
void testcaesarCipher();
void testvigenereCipher();
void testmixKey();
void testpolybiusSquare();
void testfillGrid();

void startTests() {
    testShiftAlphaCharacter();
    testtoUpperCase();
    testremoveNonAlphas();
    testcharToInt();
    testremoveDuplicate();
    testshiftAlphaCharacter();
    testcaesarCipher();
    testvigenereCipher();
    testmixKey();
    testpolybiusSquare();
    //testfillGrid();
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    return;
}

void testtoUpperCase(){
    cout << "Now testing function toUpperCase()" << endl;
    cout << "Expecting: 'SQUIRREL', Actual: " << toUpperCase("Squirrel") << endl;
    cout << "Expecting: 'WENIS', Actual: " << toUpperCase("wenis") << endl;
    return;
}

void testremoveNonAlphas(){
    cout << "Now testing function removeNonAlphas()" << endl;
    cout << "Expecting: 'EECS', Actual: " << removeNonAlphas("EECS 183") << endl;
    cout << "Expecting: 'squirrel', Actual: " << removeNonAlphas("squirrel!") << endl;
    cout << "Expecting: 'Diagpm', Actual: " << removeNonAlphas("Diag @ 11 p.m.") << endl;
    cout << "Expecting: '', Actual: " << removeNonAlphas("183") << endl;

    return;
}

void testcharToInt(){
    cout << "Now testing function charToInt()" << endl;
    cout << "Expecting: 5, Actual: " << charToInt('5') << endl;
    return;
}

void testremoveDuplicate(){
    cout << "Now testing function removeDuplicate()" << endl;
    cout << "Expecting: 'ABC', Actual: " << removeDuplicate("AABBCC") << endl;
    cout << "Expecting: '69', Actual: " << removeDuplicate("696969") << endl;
    return;
}

void testshiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter" << endl;
    cout << shiftAlphaCharacter('a', 0) << endl;
    cout << shiftAlphaCharacter('b', 2) << endl;
    cout << shiftAlphaCharacter('X', 5) << endl;
    cout << shiftAlphaCharacter('X', 50) << endl;
    cout << shiftAlphaCharacter('X', -5) << endl;
    cout << shiftAlphaCharacter('X', 0) << endl;
    cout << shiftAlphaCharacter('A', 9000) << endl;
    cout << shiftAlphaCharacter('A', -9000) << endl;
    cout << shiftAlphaCharacter('A', 5.5) << endl;
    return;
}

void testcaesarCipher() {
    cout << "Now testing function caesarCipher" << endl;
    cout << "Expecting: 'Cuuj cu qj jxu Tyqw qj 11 f.c.' Actual: ";
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "Expecting: 'Meet me at the Diag at 11 p.m.' Actual: ";
    cout << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    return;
}

void testvigenereCipher(){
    cout << "Now testing function vigenereCipher" << endl;
    cout << "Expecting : 'Euyb dv ee lxy Lzrk ll 11 f.g.' Actual: ";
    cout << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << endl;
    cout << "Expecting: 'Meet me at the Diag at 11 p.m.' Actual: ";
    cout << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << endl;
}

void testmixKey() {
    cout << "Now testing function mixKey" << endl;
    cout << "Expecting: 'POLYBIUSACDEFGHJKMNQRTVWXZ0123456789' Actual: ";
    cout << mixKey("POLYBIUS") << endl;
}

void testfillGrid() {
    cout << "Testing fillGrid" << endl;
    cout << "Expecting 'ECS138', Actual: ";
    char grid[SIZE][SIZE];
    fillGrid(grid, "EECS138");
    printGrid(grid);
    fillGrid(grid,"POLYBIUS");
    printGrid(grid);
}

void testpolybiusSquare() {
    cout << "Now testing function polybiusSquare" << endl;
    char grid[6][6];
    cout << "Expecting: '11110533 000102 1533 341411 04113334' Actual: ";
    cout << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << "Expecting: 'EECS 183 IS THE BEST' Actual: ";
    cout << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false) << endl;
    cout << "Expecting: '15151311 435445 0511 332215 04151133', Actual: ";
    cout << polybiusSquare(grid, "POLYBIUS", "EECS 183 IS THE BEST", true) << endl;
    cout << polybiusSquare(grid,"POLYBIUS", "15151311 435445 0511 332215 04151133", false) << endl;
}





