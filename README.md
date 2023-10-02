# Veterinary Clinic Management System

This project represents a comprehensive Veterinary Clinic Management System, developed as a part of the Software Design and Data Science course at Seneca Polytechnic, Winter 2023. The system integrates patient and appointment management functionality and performs various tasks, including data importation from text files, with a focus on structured design principles.

## Project Overview

### Milestone 1:
- **Objective:** To set up the fundamental building blocks for the system.
- **Tasks:**
  - Core Module/Library Functions: Develop multiple functions to handle user interface, user input, and utility functionalities.
  - Clinic Module/Library Functions: Implementation of display functions, menu & item selection, user input, and file operation functionalities.

### Milestone 2:
- **Objective:** Integrate patient management functionality.
- **Tasks:**
  - Patient Management Menu Options: Addition of menu options to perform specific tasks in the management of patient data.
  - Patient Data Importation: Importing patient information from `patientData.txt`.

### Milestone 3:
- **Objective:** Complete the system by adding appointment management functionality.
- **Tasks:**
  - Appointment Management Menu Options: Implementation of menu options to perform specific tasks in the management of appointment data.
  - Appointment Data Importation: Importing appointment information from `appointmentData.txt`.
  - New Data Types: Create/define new data types: Time, Date, and Appointment.

## Data Files
- **patientData.txt:** Contains patient data separated by a pipe (|) character.
- **appointmentData.txt:** Contains appointment data separated by a comma (,) character.

## Key Features and Functionalities
- **Data Importation:** Read and store patient and appointment data from text files to their respective struct arrays.
- **Appointment Management:**
  - View All Appointments: Display all the appointments.
  - View Appointment Schedule: Display appointments scheduled for a specific date.
  - Add Appointment: Check available elements in the appointments array and add a new appointment with validations.
  - Remove Appointment: Removed by patient number and a specific date, ensuring past appointment data remain intact.

## Development Guidelines
- Develop in a modular and organized manner, adhering to structured design principles.
- Create function prototypes and empty function definitions (stubs) for all the functions to be developed.
- Use macros for values that are subject to change, ensuring that modifications don't affect the code logic.
- Validate entered values for correctness and adherence to business rules, including no overlapping appointments.
- Develop new components in the sequence of defining new data types, coding import functions, and creating function prototypes and definitions.

## Setup and Running
1. **Copy Code from Previous Milestones:** Start by copying the work from the previous milestones into the provided files for the current milestone.
2. **Compile the Code:** Make sure that all the new components and functions are tested with actual data.
3. **Run the Application:** After compiling, run the application and test all the features.

## References
- Sample output text file: `a1ms1_output.txt`, `a1ms2_output.txt`, `a1ms3_output.txt`

## License
This project is licensed under the MIT License.

