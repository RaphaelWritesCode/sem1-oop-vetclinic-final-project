/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Raphael Antioquia
Student ID#: 031379126
Email      : rtantioquia@myseneca.ca
Section    : NKK
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Comment guidelines //
// ------------------ //
// what the function does(not how)
// what the function needs(in terms of values for its parameters)
// what the function returns(if anything).


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////


// Clear the standard input buffer
void clearInputBuffer(void);


// Wait for user to input the "enter" key to continue
void suspend(void);


// displays an array of 10-char digits as a formatted phone number
// validates it's 10 chars long, contains digits 0-9 only, 
// needs a pointer represeting a string
// doesn't return a value
void displayFormattedPhone(const char* phoneNum);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////


// gets int value from keyboard, displays error message if invalid value entered
// 
// returns int value
int inputInt(void);


// validates value entered is greater than 0, displays error message if 0 or less
// 
// returns int value
int inputIntPositive(void);


// chceks permitted range, displays error message, continues to prompt for proper value
// receives lower range and upper range  
// returns int value within range
int inputIntRange(int lowerRange, int upperRange);


// gets a single char value from keyboard, validates it, continues to prompt until valid input
// needs an unmodified C string array representing a list of valid characters
// returns single character value within the list of valid characters
char inputCharOption(const char string[]);


// validates num of characters entered, displays error message if not, prompts until valid input entered
// needs char pointer representing string, int value representing min & max num chars entered
// returns C string via 1st argument
void inputCString(char* string, int minChar, int maxChar);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
