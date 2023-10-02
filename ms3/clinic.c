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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
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
    } while (choice != 0);
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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Parameters: pointer to struct ClinicData
// Returns: nothing
void viewAllAppointments(struct ClinicData* data)
{
    int i, j;

    sortAppointmentsByDate(data);

    displayScheduleTableHeader(NULL, 1);

    // Loop through all appointments and display their data
    for (i = 0; i < data->maxAppointments; i++) 
    {
        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) 
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    putchar('\n');
}


// View appointment schedule for the user input date
// Parameters: pointer to struct ClinicData
// Returns: nothing
void viewAppointmentSchedule(struct ClinicData* data)
{    
    int i;
    int j;
    struct Date date = { 0 };

    inputDate(&date);
    putchar('\n');

    displayScheduleTableHeader(&date, 0);

    // sort appointments by time for the given date
    sortByTime(data, date);

    // display appointments for the given date in ascending order of time
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.year == date.year &&
            data->appointments[i].date.month == date.month &&
            data->appointments[i].date.day == date.day)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }

    putchar('\n');
}


// Add an appointment record to the appointment array
// Parameters: array of Appointment structs, maximum number of elements in the array, array of Patient structs, maximum number of elements in the patient array
// Returns: nothing
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient patients[], int maxPatient)
{
    int i = 0;    
    int ptNum;

    // flags for loops
    int reiterate = 1; // main loop flag. If flag != 0, main loop will end
    int available; // 2nd main loop flag. Also, checks if there are slots to make an appointment.
    int ptIndex = -1; // Keeps validating to enter valid ptNum until != -1
    int dateTimeAvailable = 0; // flag checks if valid date/time for appointment is available. 0 = No, 1 = Stores date/time/ptInfo to structs 
    int added = 0;
   

    // structs to store inputDate and inputTime values
    struct Date date = { 0 };
    struct Time time = { 0 };

    // Check if there is space to add a new appointment
    available = checkAppointmentAvailability(appointments, maxAppointments);

    if (available == 0)
    {
        printf("\nAppointment list is full. Try again later.");
    }

    printf("Patient Number: ");

    do // loops until a valid patient number is found
    {
        ptNum = inputIntPositive();
        ptIndex = findPatientIndexByPatientNum(ptNum, patients, maxPatient); // validates ptNum & finds index

    } while (available == 1 && ptIndex == -1);

    do // main loop for date/time selection and appointment creation
    {
        if (available == 1) // main loop
        {
            inputDate(&date);
            inputTime(&time);

            // Check if the appointment date/time is available
            dateTimeAvailable = checkDateTimeAvailability(appointments, maxAppointments, date, time);

            if (dateTimeAvailable == 0)
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else // Add appointment to array
            {
                while (i < maxAppointments && added == 0)
                {
                    if (appointments[i].patientNumber == 0)
                    {
                        appointments[i].patientNumber = ptNum;
                        appointments[i].date = date;
                        appointments[i].time = time;
                        printf("\n*** Appointment scheduled! ***\n\n");
                        added++;
                        reiterate = 0; // ends main loop, effectively ending function.
                    }
                    i++;
                }
            }
        }
    } while (reiterate == 1);
}

// Remove an appointment record from the appointment array
// Parameters: array of Appointment structs, maximum number of elements in the array, array of Patient structs, maximum number of elements in the patient array
// Returns: nothing
void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatient)
{
    // flags
    int i = 0;
    int j;
    int removed = 0; // entry flag to loop that removes pt appointment from arrays
    int exists = 0; // flag that indicates patient exists
    
    // ptNum variables
    int ptNum;
    int ptIndex = 0;

    // struct to store date input
    struct Date date = { 0 } ;

    // used to validate to remove Appointment
    char ch = '0';
    char string[] = "yn"; // string to send to validate y & n input to remove array

    printf("Patient Number: ");

    ptNum = inputIntPositive();
    ptIndex = findPatientIndexByPatientNum(ptNum, patients, maxPatient); // validates ptNum & finds index

    if (ptIndex == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }

    if (ptIndex != -1)
    {
        inputDate(&date);

        // find appointment record for given patient numberand date
        while (i < maxAppointments && !(appointments[i].patientNumber == ptNum &&
            appointments[i].date.year == date.year &&
            appointments[i].date.month == date.month &&
            appointments[i].date.day == date.day))
        {
            i++;
        }

        if (i < maxAppointments)
        {
            putchar('\n');
            displayPatientData(&patients[ptIndex], FMT_FORM);
            exists = 1;
        }

        if (exists == 1)
        {
            printf("Are you sure you want to remove this appointment (y,n): ");
            ch = inputCharOption(string);

            // if user confirms, remove appointment record by setting it to empty values
            if (ch == 'y' || ch == 'Y')
            {
                for (j = 0; j < maxAppointments && removed == 0; j++)
                {
                    if (appointments[j].patientNumber == ptNum &&
                        appointments[j].date.year == date.year &&
                        appointments[j].date.month == date.month &&
                        appointments[j].date.day == date.day)
                    {
                        appointments[j].patientNumber = 0;
                        appointments[j].date.year = 0;
                        appointments[j].date.month = 0;
                        appointments[j].date.day = 0;
                        appointments[j].time.hour = 0;
                        appointments[j].time.min = 0;
                        printf("\nAppointment record has been removed!\n\n");
                        removed = 1;
                    }
                }
            }
            else
            {
                printf("\nAppointment removal cancelled.\n\n");
            }
        }
        else
        {
            printf("No appointment found for the given patient number and date.\n");
        }
    }    
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Check if a given date and time are available for an appointment
// Parameters: array of Appointment structs, maximum number of elements in the array, Date struct, Time struct.
// Returns: integer value representing the availability of the date and time (1 for available, 0 for not available).
int checkDateTimeAvailability(struct Appointment appointments[], int maxAppointments, struct Date date, struct Time time)
{
    int i = 0;
    int isAvailable = 1; // Flag to indicate if the appointment time is available

    while (i < maxAppointments && isAvailable == 1) 
    {
        if (appointments[i].patientNumber >= 1 &&
            appointments[i].date.year == date.year &&
            appointments[i].date.month == date.month &&
            appointments[i].date.day == date.day &&
            appointments[i].time.hour == time.hour &&
            appointments[i].time.min == time.min) {
            isAvailable = 0; // Appointment time already booked
        }
        i++;
    }

    return isAvailable;
}


// Check if there is any availability for an appointment in the appointment array
// Parameters: array of Appointment structs, maximum number of elements in the array.
// Returns: integer value representing the availability of an appointment (1 for available, 0 for not available).
int checkAppointmentAvailability(struct Appointment appointments[], int maxAppointments)
{
    int i = 0;
    int available = 0;

    // Find the first empty appointment slot
    while (i < maxAppointments && appointments[i].patientNumber >= 1)
    {
        i++;
    }

    if (i < maxAppointments)
    {
        available = 1; // 1 = appointment slots are available
    }
    else
    {
        available = 0; // 0 = appointment list full
    }

    return available;
}


// Sort the appointments for a given date by time
// Parameters: ClinicData struct, Date struct.
// Returns: nothing.
void sortByTime(struct ClinicData* data, struct Date date)
{
    int i, j;
    struct Appointment temp = { 0 };

    // Bubble sort algorithm to sort only by time
    for (i = data->maxAppointments - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (data->appointments[j].date.year == date.year &&
                data->appointments[j].date.month == date.month &&
                data->appointments[j].date.day == date.day &&
                data->appointments[j].time.hour > data->appointments[j + 1].time.hour)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
            else if (data->appointments[j].date.year == date.year &&
                data->appointments[j].date.month == date.month &&
                data->appointments[j].date.day == date.day &&
                data->appointments[j].time.hour == data->appointments[j + 1].time.hour &&
                data->appointments[j].time.min > data->appointments[j + 1].time.min)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
        }
    }
}


// Sort the appointments array by date and time
// Parameters: ClinicData struct.
// Returns: nothing.
void sortAppointmentsByDate(struct ClinicData* data)
{
    int i, j;
    struct Appointment temp = { 0 };

    // Bubble sort algorithm
    for (i = data->maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            // sorts by year
            if (data->appointments[j].date.year > data->appointments[j + 1].date.year)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
            // sorts by month
            else if (data->appointments[j].date.year == data->appointments[j + 1].date.year &&
                data->appointments[j].date.month > data->appointments[j + 1].date.month)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
            // sorts by day
            else if (data->appointments[j].date.year == data->appointments[j + 1].date.year &&
                data->appointments[j].date.month == data->appointments[j + 1].date.month &&
                data->appointments[j].date.day > data->appointments[j + 1].date.day)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
            // sort by hour
            else if (data->appointments[j].date.year == data->appointments[j + 1].date.year &&
                data->appointments[j].date.month == data->appointments[j + 1].date.month &&
                data->appointments[j].date.day == data->appointments[j + 1].date.day &&
                data->appointments[j].time.hour > data->appointments[j + 1].time.hour)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
            // sorts by minute
            else if (data->appointments[j].date.year == data->appointments[j + 1].date.year &&
                data->appointments[j].date.month == data->appointments[j + 1].date.month &&
                data->appointments[j].date.day == data->appointments[j + 1].date.day &&
                data->appointments[j].time.hour == data->appointments[j + 1].time.hour &&
                data->appointments[j].time.min > data->appointments[j + 1].time.min)
            {
                temp = data->appointments[j];
                data->appointments[j] = data->appointments[j + 1];
                data->appointments[j + 1] = temp;
            }
        }
    }
}

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
    char phoneNum[PHONE_LEN + 1];
    printf("Search by phone number: ");
    inputCString(phoneNum, 10, 10);

    putchar('\n');

    displayPatientTableHeader();

    // Loop through all the patient records and display the ones that match the input phone number
    for (i = 0; i < max; i++)
    {
        if (strcmp(phoneNum, patient[i].phone.number) == 0)
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

// Get a time input from the user
// Parameters: Time struct pointer.
// Returns: nothing.
void inputTime(struct Time* time)
{
    int validTime = 0;

    // loop keeps validating until proper time has been entered
    do {
        printf("Hour (0-23)  : ");
        time->hour = inputIntRange(0, 23);

        printf("Minute (0-59): ");
        time->min = inputIntRange(0, 59);

        if (time->hour < START_HOUR || time->hour > END_HOUR || (time->hour == END_HOUR && time->min > 0) || (time->min % APPOINTMENT_INTERVAL != 0 && time->min != 0))
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
        }
        else
        {
            validTime = 1;
        }
    } while (validTime == 0);

}


// Get a date input from the user
// Parameters: Date struct pointer.
// Returns: nothing.
void inputDate(struct Date* date)
{
    printf("Year        : ");
    date->year = inputIntPositive();

    printf("Month (1-12): ");
    date->month = inputIntRange(1, 12);

    // Check if the entered month is February
    if (date->month == 2)
    {
        // Check if the year is a leap year
        if (date->year % 4 == 0)
        {
            printf("Day (1-29)  : ");
            date->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            date->day = inputIntRange(1, 28);
        }
    }
    // Check if the entered month has 30 days
    else if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11)
    {
        printf("Day (1-30)  : ");
        date->day = inputIntRange(1, 30);
    }
    // For all other months with 31 days
    else
    {
        printf("Day (1-31)  : ");
        date->day = inputIntRange(1, 31);
    }
}


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


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
// Parameters: datafile - a string representing the file path of the patient data file, patients - an array of Patient structs, max - the maximum number of Patient structs the array can hold.
// Returns: an integer representing the number of records read from the file.
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;

    FILE* fp = fopen(datafile, "r");

    // Check if file opened successfully
    if (fp != NULL) 
    {
        // Read data from file and store in patient array
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description,
            patients[i].phone.number) != EOF && i < max)
        {
            i++;
        }

        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("ERROR: Unable to open file for reading.");
    }

    // Return number of records read from file
    return i;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// Parameters: datafile - a string representing the file path of the appointment data file, appoints - an array of Appointment structs, max - the maximum number of Appointment structs the array can hold.
// Returns: an integer representing the number of records read from the file.
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i = 0;

    FILE* fp = fopen(datafile, "r");

    if (fp != NULL) // check if the file was successfully opened
    {
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF && i < max)
        {
            i++; // increment i and read the next record from the file while there are records left and the array isn't full
        }

        fclose(fp);
        fp = NULL; // set the file pointer to NULL to avoid errors
    }
    else
    {
        printf("ERROR: Unable to open file for reading.");
    }

    return i; // return the number of records read
}
