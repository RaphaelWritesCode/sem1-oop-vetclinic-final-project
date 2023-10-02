/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Raphael Antioquia
Student ID#: 031379126
Email      : rtantioquia@myseneca.ca
Section    : NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}


// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//


// gets int value from keyboard, displays error message if invalid value entered
// 
// returns int value
int inputInt(void)
{
    int value = 0;
    char newLine = ' ';

    do
    {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (newLine != '\n');

    return value;
}


// validates value entered is greater than 0, displays error message if 0 or less
// 
// returns int value
int inputIntPositive(void)
{
    int value = 0;

    do
    {
        value = inputInt();

        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }

    } while (value <= 0);

    return value;
}


// chceks permitted range, displays error message, continues to prompt for proper value
// receives lower range and upper range  
// returns int value within range
int inputIntRange(int lowerRange, int upperRange)
{
    int value;

    do
    {
        value = inputInt();

        if (value < lowerRange || value > upperRange)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerRange, upperRange);
        }

    } while (value < lowerRange || value > upperRange);

    return value;
}


// gets a single char value from keyboard, validates it, continues to prompt until valid input
// needs an unmodified C string array representing a list of valid characters
// returns single character value within the list of valid characters
char inputCharOption(const char string[])
{
    int i;
    int flag = 0;
    char letter[10]; // Allocate space for the input string

    do
    {
        scanf(" %s", letter); // Read the input string

        if (strlen(letter) > 1) // Check if the input string has more than one character
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
        else
        {
            flag = 0; // Reset flag to 0 for each iteration
            i = 0;

            while (string[i] != '\0' && flag == 0) // Loop checks if the letter inputted is a valid character
            {
                if (letter[0] == string[i]) // Compare the first character of the input string
                {
                    flag = 1;
                }
                else
                {
                    i++;
                }
            }

            if (flag == 0)
            {
                printf("ERROR: Character must be one of [%s]: ", string);
            }
        }
    } while (flag == 0);

    clearInputBuffer();

    return letter[0]; // Return the first character of the input string
}


// validates num of characters entered, displays error message if not, prompts until valid input entered
// needs char pointer representing string, int value representing min & max num chars entered
// returns C string via 1st argument
void inputCString(char* string, int minChar, int maxChar)
{
    int flag = 0;
    char numChar[50];
    int length; // stores string length

    do
    {
        scanf(" %49[^\n]", numChar);

        length = strlen(numChar);


        if (length >= minChar && length <= maxChar) // runs if length is within range given in parameters
        {
            clearInputBuffer();
            strcpy(string, numChar);
            flag = 1;
        }
        else // logics to print out required error statements
        {
            if (minChar == maxChar)
            {
                printf("Invalid %d-digit number! Number: ", minChar);
            }
            else if (length > maxChar)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
            }
        }

    } while (flag == 0);
}


// displays an array of 10-char digits as a formatted phone number
// validates it's 10 chars long, contains digits 0-9 only, 
// needs a pointer represeting a string
// doesn't return a value
void displayFormattedPhone(const char* phoneNum)
{
    int i, validLength = 0;    // validLength stores phone length
    int continue_search = 1;

    // Iterate over the string, checking for digits
    for (i = 0; phoneNum != NULL && phoneNum[i] != '\0' && continue_search; i++)
    {
        if (phoneNum[i] >= '0' && phoneNum[i] <= '9') // checks for valid digits then adds 1 to valid length
        {
            validLength++;
        }
    }

    if (validLength == 10) // prints a valid phone number
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c", phoneNum[0], phoneNum[1], phoneNum[2], phoneNum[3], phoneNum[4], phoneNum[5], phoneNum[6], phoneNum[7], phoneNum[8], phoneNum[9]);
    }
    else
    {
        printf("(___)___-____");
    }
}
