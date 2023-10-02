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


// MS#3 Additional macro's:
#define START_HOUR 10 // clinic operation start hour
#define END_HOUR 14 // clinic operation end hour
#define APPOINTMENT_INTERVAL 30 // interval between appointments in minutes


//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
// This struct represents a phone record, containing the description (e.g., "CELL", "HOME", "WORK", "TBD") and the phone number itself.
struct Phone
{
    char description[PHONE_DESC_LEN + 1];
    char number[PHONE_LEN + 1];
};


// Data type: Patient 
// This struct represents a patient record, containing the patient's unique number, name, and associated phone information.
struct Patient
{
    int patientNumber;
    char name[NAME_LEN];
    struct Phone phone;
};

// ------------------- MS#3 -------------------

// Data type : Time
// This struct represents a time record, containing the hour and minute values.
struct Time
{
    int hour;
    int min;
};


// Data type: Date
// This struct represents a date record, containing the year, month, and day values.
struct Date
{
    int year;
    int month;
    int day;
};


// Data type : Appointment
// This struct represents an appointment record, containing the patient's unique number, associated time, and date information.
struct Appointment
{
    int patientNumber;
    struct Time time;
    struct Date date;
};


// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt);

// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords);

// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField);


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData *data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient);

// Menu: Appointment Management
void menuAppointment(struct ClinicData* data);

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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Parameters: pointer to struct ClinicData
// Returns: nothing
void viewAllAppointments(struct ClinicData* data);

// View appointment schedule for the user input date
// Parameters: pointer to struct ClinicData
// Returns: nothing
void viewAppointmentSchedule(struct ClinicData* data);

// Add an appointment record to the appointment array
// Parameters: array of Appointment structs, maximum number of elements in the array, array of Patient structs, maximum number of elements in the patient array
// Returns: nothing
void addAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatient);

// Remove an appointment record from the appointment array
// Parameters: array of Appointment structs, maximum number of elements in the array, array of Patient structs, maximum number of elements in the patient array
// Returns: nothing
void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatient);


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Check if a given date and time are available for an appointment
// Parameters: array of Appointment structs, maximum number of elements in the array, Date struct, Time struct.
// Returns: integer value representing the availability of the date and time (1 for available, 0 for not available).
int checkDateTimeAvailability(struct Appointment appointments[], int maxAppointments, struct Date date, struct Time time);

// Check if there is any availability for an appointment in the appointment array
// Parameters: array of Appointment structs, maximum number of elements in the array.
// Returns: integer value representing the availability of an appointment (1 for available, 0 for not available).
int checkAppointmentAvailability(struct Appointment appointments[], int maxAppointments);

// Sort the appointments for a given date by time
// Parameters: ClinicData struct, Date struct.
// Returns: nothing.
void sortByTime(struct ClinicData* data, struct Date date);

// Sort the appointments array by date and time
// Parameters: ClinicData struct.
// Returns: nothing.
void sortAppointmentsByDate(struct ClinicData* data);

// Search and display patient record by patient number using a form layout
// Parameters: array of Patient structs, maximum number of elements in the array.
// Returns: nothing.
void searchPatientByPatientNumber(const struct Patient patient[], int max);

// Search and display patient records by phone number using a tabular layout
// Parameters: array of Patient structs, maximum number of elements in the array.
// Returns: nothing.
void searchPatientByPhoneNumber(const struct Patient patient[], int max);

// Get the next available patient number
// Parameters: array of Patient structs, maximum number of elements in the array.
// Returns: integer value representing the next available patient number.
int nextPatientNumber(const struct Patient patient[], int max);

// Find the patient array index by patient number(returns - 1 if not found)
// Parameters: integer value representing patient number, array of Patient structs, maximum number of elements in the array.
// Returns: integer value representing the index of the patient with the given patient number.
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get a time input from the user
// Parameters: Time struct pointer.
// Returns: nothing.
void inputTime(struct Time* time);

// Get a date input from the user
// Parameters: Date struct pointer.
// Returns: nothing.
void inputDate(struct Date* date);

// Prompts the user to enter information for a new patient record and stores it. 
// Parameters: pointer to a Patient type that will already have the next patient number assigned. 
// Returns: nothing.
void inputPatient(struct Patient* patient);

// Prompts the user to enter information for a new phone record and stores it. 
// Parameters: pointer to a Phone type. 
// Returns: nothing.
void inputPhoneData(struct Phone* phone);


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
// Parameters: datafile - a string representing the file path of the patient data file, patients - an array of Patient structs, max - the maximum number of Patient structs the array can hold.
// Returns: an integer representing the number of records read from the file.
int importPatients(const char* datafile, struct Patient patients[], int max);

// Import appointment data from file into an Appointment array (returns # of records read)
// Parameters: datafile - a string representing the file path of the appointment data file, appoints - an array of Appointment structs, max - the maximum number of Appointment structs the array can hold.
// Returns: an integer representing the number of records read from the file.
int importAppointments(const char* datafile, struct Appointment appoints[], int max);


#endif // !CLINIC_H