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
#ifndef CLINIC_H
#define CLINIC_H


//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACRO'S !!!
#define FMT_FORM 1
#define FMT_TABLE 2

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10


//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
// This struct represents a phone record, containing the description (e.g., "CELL", "HOME", "WORK", "TBD") and the phone number itself.
struct Phone 
{
    char description[PHONE_DESC_LEN+1];
    char number[PHONE_LEN+1];    
};


// Data type: Patient 
// This struct represents a patient record, containing the patient's unique number, name, and associated phone information.
struct Patient 
{
    int patientNumber;
    char name[NAME_LEN];
    struct Phone phone;
};


// ClinicData type: Provided to student
// This struct represents a clinic's data, containing a pointer to an array of Patient structs and an integer representing the maximum number of patients that can be stored.
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
};


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt);


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData* data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient);


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! ALL the below functions need defining       !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!! DO NOT MODIFY THE BELOW PROTOTYPES !!!

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// Parameters: array of Patient structs, maximum number of elements in the array, integer value representing the desired format of display (FMT_FORM or FMT_TABLE). 
// Returns: nothing.
void displayAllPatients(const struct Patient patient[], int max, int fmt);


// Search for a patient record based on patient number or phone number
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void searchPatientData(const struct Patient patient[], int max);


// Adds a new Patient struct to the patient array if there is space available. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void addPatient(struct Patient patient[], int max);


// Allows the user to edit an existing patient record. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void editPatient(struct Patient patient[], int max);


// Allows the user to remove an existing patient record. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void removePatient(struct Patient patient[], int max);


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Searches the patient array for a record with a specific patient number and displays it in FMT_FORM format. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void searchPatientByPatientNumber(const struct Patient patient[], int max);


// Searches the patient array for records with a specific phone number and displays them in FMT_TABLE format. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: nothing.
void searchPatientByPhoneNumber(const struct Patient patient[], int max);


// Determines the next available unique patient number based on the existing patient numbers in the array. 
// Parameters: array of Patient structs, maximum number of elements in the array. 
// Returns: integer value representing the next highest patient number.
int nextPatientNumber(const struct Patient patient[], int max);


// Find the patient array index by patient number (// Searches the patient array for a record with a specific patient number and returns its index if found. 
// Parameters: integer value representing the patient number to search for, array of Patient structs, maximum number of elements in the array. 
// Returns: integer value representing the index of the found patient record, or -1 if not found. -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Prompts the user to enter information for a new patient record and stores it. 
// Parameters: pointer to a Patient type that will already have the next patient number assigned. 
// Returns: nothing.
void inputPatient(struct Patient* patient);


// Prompts the user to enter information for a new phone record and stores it. 
// Parameters: pointer to a Phone type. 
// Returns: nothing.
void inputPhoneData(struct Phone* phone);


#endif // !CLINIC_H
