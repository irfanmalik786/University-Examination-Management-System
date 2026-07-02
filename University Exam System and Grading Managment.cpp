#include <iostream>
#include <fstream>
using namespace std;

// Maximum number of students the system can store
const int maxStudents = 30;

// Maximum number of subjects allowed for each student
const int maxSubjects = 6;

// Stores the current number of registered students
int totalStudents = 0;

// Stores the current number of added subjects
int totalSubjects = 0;

//--------------------------- Student Information ---------------------------//

// Dynamically allocated array to store student names
char* studentFullNames[maxStudents];

// Stores unique roll numbers
char rollNumbers[maxStudents][30];

// Stores program names (e.g., BSCS, BSSE)
char programs[maxStudents][10];

// Stores semester numbers
int semesters[maxStudents];

// Stores student sections (A, B, C, etc.)
char sections[maxStudents];

//--------------------------- Subject & Result Information ---------------------------//

// Stores subject names
char subjects[maxSubjects][30];

// Stores marks of every student for every subject
int marks[maxStudents][maxSubjects];

// Stores calculated grades (A+, A, B, C, D, F)
char grades[maxStudents][3];

// Stores calculated percentages
float percentages[maxStudents];

//-----------------------------------------------------------------------------------------------------------------//

// Compare two character arrays.
// Returns true if both strings are exactly the same.
bool compare(char* a, char* b) {
    while (*a != '\0' || *b != '\0') {
        if (*a != *b)
            return false;

        a++;
        b++;
    }
    return true;
}

// Copy one character array into another.
// Works similarly to the built-in strcpy() function.
void copy(char* to, char* from) {
    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }

    // Add the null character to mark the end of the string
    *to = '\0';
}

//-----------------------------------------------------------------------------------------------------------------//
//---------------------------------------------Menu Base (Core Functions)------------------------------------------//

// Function to register new students
void addStudentDetails() {
    int n;

    // Ask the user how many students they want to register
    do {
        cout << "How many number of students do you want to register (max 30): ";
        cin >> n;

        // Validate the entered number
        if (n <= 0 || n > 30) {
            cout << "Maximum Student can be from(1-30)" << endl;
        }
    } while (n <= 0 || n > 30);

    // Register each student one by one
    for (int i = 0; i < n && totalStudents < maxStudents; i++) {
        char roll[30];
        bool duplicate;

        // Keep asking until a unique roll number is entered
        do {
            duplicate = false;

            cout << "Enter Roll No: ";
            cin >> roll;

            // Check whether the entered roll number already exists
            for (int j = 0; j < totalStudents; j++) {
                if (compare(roll, rollNumbers[j])) {
                    duplicate = true;
                    cout << " Duplicate Roll Number.(Add another Roll No) " << endl;
                    break;
                }
            }

        } while (duplicate);

        char name[50];
        cout << "Enter Name: ";
        cin.ignore();              // Clear input buffer before getline()
        cin.getline(name, 50);

        char program[10];
        cout << "Enter Program (like BSCS): ";
        cin.getline(program, 10);

        int semester;

        // Accept only semesters from 1 to 8
        do {
            cout << "Enter Semester (from 1-8): ";
            cin >> semester;

            if (semester <= 0 || semester > 8)
            {
                cout << "Please Enter the Correct Semsester(from 1-8)" << endl;
            }

        } while (semester <= 0 || semester > 8);

        char section;
        cout << "Enter Section: ";
        cin >> section;

        // Store all entered student information

        // Store roll number
        copy(rollNumbers[totalStudents], roll);

        // Calculate the length of the student's name
        int nameLen = 0;
        while (name[nameLen] != '\0') {
            nameLen++;
        }

        // Allocate only the required memory for the name
        studentFullNames[totalStudents] = new char[nameLen + 1];

        // Store student name
        copy(studentFullNames[totalStudents], name);

        // Store program name
        copy(programs[totalStudents], program);

        // Store semester
        semesters[totalStudents] = semester;

        // Store section
        sections[totalStudents] = section;

        // Increase the total number of registered students
        totalStudents++;

        cout << "Student added successfully." << endl;
    }

    // Display the remaining registration capacity
    cout << "Remaining slots: " << (maxStudents - totalStudents) << endl;
}


// Function to add subjects for the registered students
void addSubjects() {

    // Subjects can only be added after registering students
    if (totalStudents == 0) {
        cout << "Please register the students first then add subjects." << endl;
        return;
    }

    // Ask the user for the number of subjects
    do {
        cout << "Enter number of subjects (max 6): ";
        cin >> totalSubjects;

        // Validate subject limit
        if (totalSubjects <= 0 || totalSubjects > 6) {
            cout << "Maximum Subject can be from(1-6)" << endl;
            return;
        }

    } while (totalSubjects <= 0 || totalSubjects > 6);

    // Clear the input buffer before using getline()
    cin.ignore();

    // Read the name of each subject
    for (int i = 0; i < totalSubjects; i++) {
        cout << "Enter subject " << (i + 1) << ": ";
        cin.getline(subjects[i], 30);
    }
}


// Function to enter marks for all registered students
void enterMarks() {

    // Marks cannot be entered until subjects are added
    if (totalSubjects == 0) {
        cout << "Please add the subjects first then enter marks." << endl;
        return;
    }

    // Loop through every registered student
    for (int i = 0; i < totalStudents; i++) {
        cout << "Enter marks for " << studentFullNames[i] << " (" << rollNumbers[i] << "):" << endl;

        // Enter marks for each subject
        for (int j = 0; j < totalSubjects; j++) {
            int mark;

            // Keep asking until a valid mark (0-100) is entered
            do {
                cout << "  " << subjects[j] << ": ";
                cin >> mark;

                if (mark < 0 || mark > 100)
                    cout << "  Invalid. Enter between 0-100." << endl;

            } while (mark < 0 || mark > 100);

            // Store the validated marks
            marks[i][j] = mark;
        }
    }
}


// Function to calculate percentage and assign grades
void calculatePercentageAndGrade() {

    // Ensure that subjects and marks are available before calculation
    if (totalSubjects == 0) {
        cout << " No subjects or marks have been entered yet.(enter them first) " << endl;
        return;
    }

    // Calculate result for each registered student
    for (int i = 0; i < totalStudents; i++) {

        // Store the total obtained marks
        double total = 0;

        // Add marks of all subjects
        for (int j = 0; j < totalSubjects; j++) {
            total += marks[i][j];
        }

        // Calculate percentage
        percentages[i] = (total * 100) / (totalSubjects * 100);

        // Assign grade based on percentage
        if (percentages[i] >= 90)
            grades[i][0] = 'A', grades[i][1] = '+', grades[i][2] = '\0';
        else if (percentages[i] >= 80)
            grades[i][0] = 'A', grades[i][1] = '\0';
        else if (percentages[i] >= 70)
            grades[i][0] = 'B', grades[i][1] = '\0';
        else if (percentages[i] >= 60)
            grades[i][0] = 'C', grades[i][1] = '\0';
        else if (percentages[i] >= 50)
            grades[i][0] = 'D', grades[i][1] = '\0';
        else
            grades[i][0] = 'F', grades[i][1] = '\0';
    }

    cout << "Grades calculated." << endl;
}


// Function to display the result card of every registered student
void generateResultCard() {

    // Ensure that student and subject data is available
    if (totalStudents == 0 || totalSubjects == 0) {
        cout << "Cannot show statistics. No students or subjects data available." << endl;
        return;
    }

    // Check whether grades have been calculated
    if (grades[0][0] == '\0') {
        cout << "Grades not calculated yet. Please calculate grades first." << endl;
        return;
    }

    // Display result card for each student
    for (int i = 0; i < totalStudents; i++) {

        cout << "Result for " << studentFullNames[i] << " (" << rollNumbers[i] << "):" << endl;

        double total = 0;

        // Display marks of every subject and calculate total marks
        for (int j = 0; j < totalSubjects; j++) {
            cout << subjects[j] << ": " << marks[i][j] << endl;
            total += marks[i][j];
        }

        // Display final result
        cout << "Total: " << total << "/" << (totalSubjects * 100) << endl;
        cout << "Percentage: " << percentages[i] << "%" << endl;
        cout << "Grade: " << grades[i] << endl;
    }
}


// Function to save all student records into text files
void saveToFile() {

    // Open files for writing
    ofstream f1("students.txt");
    ofstream f2("marks.txt");
    ofstream f3("results.txt");

    // Ensure that data exists before saving
    if (totalStudents == 0 || totalSubjects == 0) {
        cout << "Cannot saved. No students or subjects data available." << endl;
        return;
    }

    // Grades must be calculated before saving
    if (grades[0][0] == '\0') {
        cout << "Grades not calculated yet. Please calculate grades first." << endl;
        return;
    }

    // Save all student records
    for (int i = 0; i < totalStudents; i++) {

        // Save student information
        f1 << rollNumbers[i] << " " << studentFullNames[i] << " " << programs[i] << " "
            << semesters[i] << " " << sections[i] << endl;

        // Save subject marks
        for (int j = 0; j < totalSubjects; j++) {
            f2 << marks[i][j] << " ";
            f2 << endl;
        }

        // Save percentage and grade
        f3 << rollNumbers[i] << " " << percentages[i] << " " << grades[i] << endl;
    }

    // Close all opened files
    f1.close();
    f2.close();
    f3.close();

    cout << "Data saved." << endl;
}


// Function to load previously saved student records
void loadFromFile() {

    // Open data files
    ifstream f1("students.txt");
    ifstream f2("marks.txt");
    ifstream f3("results.txt");
    ofstream subjectFile("subjects.txt");

    // Verify that all required files opened successfully
    if (!f1 || !f2 || !f3) {
        return;    // No saved data available yet
    }

    // Clear current student count before loading data
    totalStudents = 0;

    // Read records until end of file
    while (!f1.eof()) {

        char roll[30], name[50], program[10], ch;
        int semester;

        if (!(f1 >> roll))
            break;

        // Skip the space before reading the student's name
        f1.get();

        f1.getline(name, 50, ' ');
        f1 >> program >> semester >> ch;

        // Store loaded student information
        copy(rollNumbers[totalStudents], roll);

        int len = 0;
        while (name[len] != '\0') {
            len++;
        }

        // Allocate memory for the student's name
        studentFullNames[totalStudents] = new char[len + 1];
        copy(studentFullNames[totalStudents], name);

        copy(programs[totalStudents], program);
        semesters[totalStudents] = semester;
        sections[totalStudents] = ch;

        // Load subject marks
        for (int j = 0; j < totalSubjects; j++) {
            f2 >> marks[totalStudents][j];
        }

        // Load percentage and grade
        f3 >> roll >> percentages[totalStudents] >> grades[totalStudents];

        totalStudents++;
    }

    // Close all files
    f1.close();
    f2.close();
    f3.close();

    cout << "Data loaded." << endl;
}


// Function to search and display a student's result using Roll Number
void searchStudentResult() {

    char roll[30];

    // Read the roll number to search
    cout << "Enter roll number to search: ";
    cin >> roll;

    // Search through all registered students
    for (int i = 0; i < totalStudents; i++) {

        // Compare the entered roll number with stored roll numbers
        if (compare(roll, rollNumbers[i])) {

            cout << "Result for " << studentFullNames[i] << " (" << rollNumbers[i] << "):" << endl;

            double total = 0;

            // Display subject-wise marks and calculate total marks
            for (int j = 0; j < totalSubjects; j++) {
                cout << subjects[j] << ": " << marks[i][j] << endl;
                total += marks[i][j];
            }

            // Display final result
            cout << "Total: " << total << "/" << (totalSubjects * 100) << endl;
            cout << "Percentage: " << percentages[i] << "%" << endl;
            cout << "Grade: " << grades[i] << endl;

            return;
        }
    }

    // Display message if the roll number does not exist
    cout << "Student not found." << endl;
}


// Function to display overall class statistics
void showClassStatistics() {

    // Ensure student and subject data is available
    if (totalStudents == 0 || totalSubjects == 0) {
        cout << "Cannot show statistics. No students or subjects data available." << endl;
        return;
    }

    // Ensure grades have been calculated
    if (grades[0][0] == '\0') {
        cout << "Grades not calculated yet. Please calculate them first." << endl;
        return;
    }

    // Initialize values using the first student's data
    double highestPercentage = percentages[0];
    double totalPercentage = percentages[0];
    int highestIndex = 0;

    // Find the highest percentage and calculate class total percentage
    for (int i = 1; i < totalStudents; i++) {

        if (percentages[i] > highestPercentage) {
            highestPercentage = percentages[i];
            highestIndex = i;
        }

        totalPercentage += percentages[i];
    }

    // Calculate class average percentage
    double averagePercentage = totalPercentage / totalStudents;

    cout << "Class Statistics:" << endl;
    cout << "Total Students: " << totalStudents << endl;
    cout << "Average Percentage: " << averagePercentage << "%" << endl;

    // Display the top-performing student
    cout << "Top Student:" << endl;
    cout << "Name: " << studentFullNames[highestIndex] << endl;
    cout << "Roll No: " << rollNumbers[highestIndex] << endl;
    cout << "Percentage: " << percentages[highestIndex] << "%" << endl;
    cout << "Grade: " << grades[highestIndex] << endl;
}


// Function to delete a student using Roll Number
void deleteStudent() {

    char roll[30];

    // Read the roll number of the student to delete
    cout << "Enter roll number to delete: ";
    cin >> roll;

    // Search for the student
    for (int i = 0; i < totalStudents; i++) {

        if (compare(roll, rollNumbers[i])) {

            // Free dynamically allocated memory for the student's name
            delete[] studentFullNames[i];

            // Shift all remaining student records one position left
            for (int j = i; j < totalStudents - 1; j++) {

                studentFullNames[j] = studentFullNames[j + 1];

                for (int k = 0; k < 30; k++) {
                    rollNumbers[j][k] = rollNumbers[j + 1][k];
                }

                for (int k = 0; k < 10; k++) {
                    programs[j][k] = programs[j + 1][k];
                }

                semesters[j] = semesters[j + 1];
                sections[j] = sections[j + 1];

                // Shift marks and percentages
                for (int k = 0; k < maxSubjects; k++) {
                    marks[j][k] = marks[j + 1][k];
                    percentages[j] = percentages[j + 1];
                }

                // Shift grades
                for (int k = 0; k < 3; k++) {
                    grades[j][k] = grades[j + 1][k];
                }
            }

            // Update total registered students
            totalStudents--;

            cout << "Student deleted." << endl;
            return;
        }
    }

    // Student not found
    cout << "Student not found." << endl;
}


// Function to update marks of a student using Roll Number
void editMarks() {

    char roll[30];

    // Read the roll number of the student
    cout << "Enter roll number to edit marks: ";
    cin >> roll;

    // Search for the student
    for (int i = 0; i < totalStudents; i++) {

        // Compare entered roll number with stored roll numbers
        if (compare(roll, rollNumbers[i])) {

            cout << "Editing marks for " << studentFullNames[i] << ":" << endl;

            // Enter updated marks for each subject
            for (int j = 0; j < totalSubjects; j++) {
                cout << subjects[j] << ": ";
                cin >> marks[i][j];
            }

            cout << "Marks updated." << endl;
            return;
        }
    }

    // Display message if the roll number is not found
    cout << "Student not found." << endl;
}


// Function to display information of all registered students
void showRegisteredStudentDetails() {

    // Display the number of registered students
    cout << "Total Registered Students: " << totalStudents << " out of " << maxStudents << endl;

    // Check whether any student is registered
    if (totalStudents == 0) {
        cout << "No students registered yet." << endl;
        return;
    }

    // Display details of every registered student
    for (int i = 0; i < totalStudents; i++) {

        cout << "----------------------------------------" << endl;
        cout << "Name: " << studentFullNames[i] << endl;
        cout << "Roll No: " << rollNumbers[i] << endl;
        cout << "Program: " << programs[i] << endl;
        cout << "Semester: " << semesters[i] << endl;
        cout << "Section: " << sections[i] << endl;

        // Check whether subjects have been added
        if (totalSubjects == 0) {
            cout << "Subjects: Not added yet" << endl;
        }
        else {

            cout << "Subjects & Marks:" << endl;

            // Display marks of each subject
            for (int j = 0; j < totalSubjects; j++) {

                cout << "  " << subjects[j] << ": ";

                // Display marks only if they have been entered
                if (marks[i][j] >= 0 && marks[i][j] <= 100)
                    cout << marks[i][j];
                else
                    cout << "Subjects(marks): Not entered yet";

                cout << endl;
            }
        }

        // Check whether grades have been calculated
        if (grades[i][0] == '\0') {
            cout << "Grade:Not calculated yet" << endl;
        }
        else {
            cout << "Percentage: " << percentages[i] << "%" << endl;
            cout << "Grade: " << grades[i] << endl;
        }
    }
}


//-----------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------//

int main() {

    // Initialize all marks with -1.
    // This indicates that marks have not been entered yet.
    for (int i = 0; i < maxStudents; i++) {
        for (int j = 0; j < maxSubjects; j++) {
            marks[i][j] = -1;
        }
    }

    // Automatically load previously saved records (if available)
    loadFromFile();

    int choice;

    // Display the menu repeatedly until the user chooses Exit
    do {

        cout << "============ Welcome to University Examination Management Menu ============" << endl;
        cout << "1. Register Students" << endl;
        cout << "2. Add Subjects" << endl;
        cout << "3. Enter Marks" << endl;
        cout << "4. Calculate Grades" << endl;
        cout << "5. Generate Result Cards" << endl;
        cout << "6. Save to File" << endl;
        cout << "7. Load from File" << endl;
        cout << "8. Search Student Result" << endl;
        cout << "9. Delete Student" << endl;
        cout << "10. Edit Marks" << endl;
        cout << "11. Show Registered Students Detail" << endl;
        cout << "12. Show Class Statistics" << endl;
        cout << "0. Exit" << endl;

        // Read the user's menu choice
        cout << "Choose option: ";
        cin >> choice;

        // Execute the selected operation
        if (choice == 1) addStudentDetails();
        else if (choice == 2) addSubjects();
        else if (choice == 3) enterMarks();
        else if (choice == 4) calculatePercentageAndGrade();
        else if (choice == 5) generateResultCard();
        else if (choice == 6) saveToFile();
        else if (choice == 6) saveToFile();
        else if (choice == 7) loadFromFile();
        else if (choice == 8) searchStudentResult();
        else if (choice == 9) deleteStudent();
        else if (choice == 10) editMarks();
        else if (choice == 11) showRegisteredStudentDetails();
        else if (choice == 12) showClassStatistics();
        else if (choice == 0)
            cout << "Exiting..." << endl;
        else
            cout << "Invalid option." << endl;

    } while (choice != 0);   // Continue until the user selects Exit

    return 0;   // End the program successfully
}