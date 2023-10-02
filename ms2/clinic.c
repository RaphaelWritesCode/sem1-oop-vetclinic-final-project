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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// Parameters: array of Patient structs, maximum number of elements in the array, integer value representing the desired format of display (FMT_FORM or FMT_TABLE). 
// Returns: nothing.
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int noRecords = 1;

    displayPatientTableHeader();

    // Loop through all the patient records and display the ones that are not empty
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);            
            noRecords = 0;
        }
    }

    putchar('\n');

    // If no records are found, display a message
    if (noRecords == 1)
    {
        printf("*** No records found ***\n");
    }
}


// Search for a patient record based on patient number or phone number
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void searchPatientData(const struct Patient patient[], int max) //****
{
    int choice;

    do {

        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");

        choice = inputIntRange(0, 2);

        putchar('\n');

        if (choice == 1)
        {
            searchPatientByPatientNumber(patient, max);                      
        }
        if (choice == 2)
        {
            searchPatientByPhoneNumber(patient, max);                     
        }       
    } while (choice !=  0);
}


// Adds a new Patient struct to the patient array if there is space available. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int index = 0;

    // Loop through the patient array to find the first empty slot
    for (i = 0; i < max && index == 0; i++)
    {
        if (patient[i].patientNumber == 0)
        {          
            index = i;
        }
    }   

    // If no empty slot is found, display an error message
    if (index == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        // Assign the next available patient number and input the patient data
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
    }
}


// Allows the user to edit an existing patient record. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void editPatient(struct Patient patient[], int max)
{
    int ptNum;
    int exists;
    printf("Enter the patient number: ");
    ptNum = inputInt();
    putchar('\n');

    // Check if the patient with the given number exists
    exists = findPatientIndexByPatientNum(ptNum, patient, max);

    // If the patient exists, display the edit menu, otherwise show an error message
    if (exists == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[exists]);
    }

}


// Allows the user to remove an existing patient record. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void removePatient(struct Patient patient[], int max)
{
    int ptNum;
    int exists = 0;
    char ch;

    printf("Enter the patient number: ");
    ptNum = inputInt();
    putchar('\n');

    // Check if the patient with the given number exists
    exists = (findPatientIndexByPatientNum(ptNum, patient, max));

    // If the patient exists, confirm the removal, otherwise show an error message
    if (exists == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    if (exists != -1)
    {
        displayPatientData(&patient[exists], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");

        ch = inputCharOption("yn");

        // Remove the patient record if the user confirms, otherwise abort the operation
        if (ch == 'y')
        {
            patient[exists].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        if (ch == 'n')
        {
            printf("Operation aborted.\n\n");
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Searches the patient array for a record with a specific patient number and displays it in FMT_FORM format. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int index;
    int ptNum;

    printf("Search by patient number: ");
    ptNum = inputInt();
    putchar('\n');

    // Call findPatientIndexByPatientNum to locate the index of the patient in the array
    index = findPatientIndexByPatientNum(ptNum, patient, max);

    // Check if the patient record is found
    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }

    putchar('\n');

    suspend();
}


// Searches the patient array for records with a specific phone number and displays them in FMT_TABLE format. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int noRecords = 1;
    char phoneNum[PHONE_LEN+1];
    printf("Search by phone number: ");
    inputCString(phoneNum, 10, 10);

    putchar('\n');

    displayPatientTableHeader();

    // Loop through all the patient records and display the ones that match the input phone number
    for (i = 0; i < max; i++)
    {
        if (strcmp(phoneNum,patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            noRecords = 0;
        }
    }

    // If no records are found, display a message
    if (noRecords == 1)
    {
        printf("\n*** No records found ***\n");
    }

    putchar('\n');

    suspend();
}


// Determines the next available unique patient number based on the existing patient numbers in the array. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: integer value representing the next highest patient number.
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, maxNum = 0;

    // Iterate through the patient array
    for (i = 0; i < max; i++) 
    {
        // Check if the current patient's number is greater than the current maximum number
        if (patient[i].patientNumber > maxNum) 
        {
            // Update the maximum number
            maxNum = patient[i].patientNumber;
        }
    }

    return maxNum + 1;
}


// Searches the patient array for a record with a specific patient number and returns its index if found. 
// Parameters: integer value representing the patient number to search for, array of Patient structs, maximum number of elements in the array. 
// Returns: integer value representing the index of the found patient record, or -1 if not found.
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    int index = -1;

    // Loop through all the patient records and find the index of the one that matches the input patient number
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            index = i;
        }
    }

    return index;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Prompts the user to enter information for a new patient record and stores it. 
// Parameters: pointer to a Patient type that will already have the next patient number assigned. 
// Returns: nothing.
void inputPatient(struct Patient* patient)
{    
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n"
        "Name  : ", patient->patientNumber);
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n\n");
}


// Prompts the user to enter information for a new phone record and stores it. 
// Parameters: pointer to a Phone type. 
// Returns: nothing.
void inputPhoneData(struct Phone* phone)
{
    int choice;

    // Display the contact method options to the user
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");

    choice = inputIntRange(1, 4);
    putchar('\n');

    // Assign the chosen description and prompt for the phone number if necessary
    if (choice == 4)
    {
        strcpy(phone->description, "TBD");
        phone->number[0] = 0;
    }
    else
    {
        if (choice == 1)
        {
            strcpy(phone->description, "CELL");
        }            
        if (choice == 2)
        {
            strcpy(phone->description, "HOME");
        }
        if (choice == 3)
        {
            strcpy(phone->description, "WORK");
        }
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
    }
}


