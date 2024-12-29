#include <stdio.h>
#define MAX_STUDENTS 100
#include "datatype.h"

struct Student students[MAX_STUDENTS];
int studentCount = 0;


void menu() {
    printf("***Student Management System Using C***\n");
    printf("\n");
    printf("               MENU                     \n");
    printf("      =======================\n");
    printf("      [1] Add A New Student.\n");
    printf("      [2] Show All Students.\n");
    printf("      [3] Search A Student By Name.\n");
    printf("      [4] Edit A Student.\n");
    printf("      [5] Delete A Student.\n");
    printf("      [6] Sort Students by Name.\n");
    printf("      [0] Exit the Program.\n");
    printf("      ==========================\n");
    printf("Enter The Choice: ");
}

//Tiet 1
void displayStudents() {
    if (studentCount == 0) {
        printf("There are no students in the list.\n");
        return;
    }

    printf("                         **** All Students ****\n");
    printf("|============|======================|=================|==========|======================|=================|\n");
    printf("| %-10s | %-20s | %-15s | %-8s | %-20s | %-15s |\n", 
           "ID", "Name", "Date of Birth", "Gender", "Email", "Phone");
    printf("|============|======================|=================|==========|======================|=================|\n");

	int i;
    for (i = 0; i < studentCount; i++) {
        printf("| %-10s | %-20s | %02d/%02d/%04d      | %-8s | %-20s | %-15s |\n", 
                   students[i].studentId, 
                   students[i].name, 
                   students[i].dateOfBirth.day, 
                   students[i].dateOfBirth.month, 
                   students[i].dateOfBirth.year, 
                   students[i].gender ? "Male" : "Female", 
                   students[i].email, 
                   students[i].phone);
        printf("|------------|----------------------|-----------------|----------|----------------------|-----------------|\n");
    }

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------\n");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}




//Tiet 4
int isValidDate(int day, int month, int year) {
   
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0;
    }

 
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29; 
    }

    if (day > daysInMonth[month - 1]) {
        return 0;
    }

    return 1;
}


//Tiet 4
int isValidStudent(struct Student newStudent) {
    if (strlen(newStudent.studentId) == 0 || strlen(newStudent.email) == 0 || strlen(newStudent.name) == 0 || strlen(newStudent.phone) == 0 || strlen(newStudent.password) == 0 || 
	    strlen(newStudent.studentId) > 10 || strlen(newStudent.email) > 30 || strlen(newStudent.name) > 20|| strlen(newStudent.password) > 20 || strlen(newStudent.phone) > 20) {
        printf("Error: Book information cannot be empty or size invalid.\n");
        return 0;
    }

	if (!isValidDate(newStudent.dateOfBirth.day, newStudent.dateOfBirth.month, newStudent.dateOfBirth.year)) {
	    printf("Error: Invalid  DateOfBirth (%02d/%02d/%04d).\n", 
	        newStudent.dateOfBirth.day, 
	        newStudent.dateOfBirth.month, 
	        newStudent.dateOfBirth.year);
	    return 0;
    }
    
	int i;
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentId, newStudent.studentId) == 0) {
            printf("Error: Student ID '%s' already exists.\n", newStudent.studentId);
            return 0;
        }
        if (strcmp(students[i].email, newStudent.email) == 0) {
            printf("Error: Student email '%s' already exists.\n", newStudent.email);
            return 0;
        }
         if (strcmp(students[i].phone, newStudent.phone) == 0) {
            printf("Error: Student phone '%s' already exists.\n", newStudent.phone);
            return 0;
        }
    }
    return 1;
}



int isValidUpdateStudent(struct Student newStudent) {
    if (strlen(newStudent.studentId) == 0 || strlen(newStudent.email) == 0 || strlen(newStudent.name) == 0 || strlen(newStudent.phone) == 0 || strlen(newStudent.password) == 0 || 
	    strlen(newStudent.studentId) > 10 || strlen(newStudent.email) > 30 || strlen(newStudent.name) > 20|| strlen(newStudent.password) > 20 || strlen(newStudent.phone) > 20) {
        printf("Error: Book information cannot be empty or size invalid.\n");
        return 0;
    }

	if (!isValidDate(newStudent.dateOfBirth.day, newStudent.dateOfBirth.month, newStudent.dateOfBirth.year)) {
	    printf("Error: Invalid  DateOfBirth (%02d/%02d/%04d).\n", 
	        newStudent.dateOfBirth.day, 
	        newStudent.dateOfBirth.month, 
	        newStudent.dateOfBirth.year);
	    return 0;
    }
    
	int i;
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].email, newStudent.email) == 0) {
            printf("Error: Student email '%s' already exists.\n", newStudent.email);
            return 0;
        }
         if (strcmp(students[i].phone, newStudent.phone) == 0) {
            printf("Error: Student phone '%s' already exists.\n", newStudent.phone);
            return 0;
        }
    }
    return 1;
}


//Tiet 1
void addStudent() {
    printf("                         **** Add A New Student ****\n");

    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add student, list is full.\n");
        return;
    }

    struct Student newStudent;

  
    do {
        printf("Enter the Student ID: ");
        scanf("%s", newStudent.studentId);

        printf("Enter the Name: ");
        scanf(" %[^\n]%*c", newStudent.name);

        printf("Enter the Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &newStudent.dateOfBirth.day, &newStudent.dateOfBirth.month, &newStudent.dateOfBirth.year);

        printf("Enter the Gender (1 for Male, 0 for Female): ");
        scanf("%d", (int*)&newStudent.gender); 

        printf("Enter the Email: ");
        scanf("%s", newStudent.email);

        printf("Enter the Phone: ");
        scanf("%s", newStudent.phone);

        printf("Enter the Password: ");
        scanf("%s", newStudent.password);

    } while (!isValidStudent(newStudent)); 

  
    students[studentCount] = newStudent;
    studentCount++;

    printf("\nStudent Added Successfully.\n");

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("========== Thank You ==========\n");
            printf("========== See You Soon ==========\n\n");
            printf("--------------------------------------\n");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}


//Tiet 2
void editStudent() {
    printf("                         **** Edit A Student ****\n");
    char id[10];
    
    printf("Enter the Student ID: ");
    scanf("%s", id);

    int index = -1;

   	int i;
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentId, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Student with ID '%s' not found.\n", id);
        return;
    }

   
    printf("One Student Found for ID: %s\n\n", students[index].studentId);
    printf("Student Information\n");
    printf("------------------------------\n");
    printf("%-15s: %s\n", "ID", students[index].studentId);
    printf("%-15s: %s\n", "Name", students[index].name);
    printf("%-15s: %02d/%02d/%04d\n", "Date of Birth", 
           students[index].dateOfBirth.day, 
           students[index].dateOfBirth.month, 
           students[index].dateOfBirth.year);
    printf("%-15s: %s\n", "Gender", students[index].gender ? "Male" : "Female");
    printf("%-15s: %s\n", "Email", students[index].email);
    printf("%-15s: %s\n", "Phone", students[index].phone);
    printf("------------------------------\n");
    printf("                  *************** Update The Student ***************\n");

    struct Student updatedStudent;
    int valid;

    do {
        printf("Enter the new Name: ");
        scanf(" %[^\n]%*c", updatedStudent.name);

        printf("Enter the Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &updatedStudent.dateOfBirth.day, &updatedStudent.dateOfBirth.month, &updatedStudent.dateOfBirth.year);

        printf("Enter the Gender (1 for Male, 0 for Female): ");
        scanf("%d", (int*)&updatedStudent.gender);

        printf("Enter the Email: ");
        scanf("%s", updatedStudent.email);

        printf("Enter the Phone: ");
        scanf("%s", updatedStudent.phone);

        printf("Enter the Password: ");
        scanf("%s", updatedStudent.password);

       
        strcpy(updatedStudent.studentId, students[index].studentId);

        
        valid = isValidUpdateStudent(updatedStudent);

        if (!valid) {
            printf("Error: Invalid information. Please enter again.\n");
        }
    } while (!valid); 

   
    students[index] = updatedStudent;

    printf("Student Updated Successfully.\n");

   
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("========== Thank You ==========\n");
            printf("========== See You Soon ==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}


//Tiet 3
void deleteStudent() {
	printf("                         **** Delete A Student ****\n");
    char id[10];
    printf("Enter the Student ID to delete: ");
    scanf("%s", id);

    
    int index = -1;
    int i;
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentId, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Student with ID '%s' not found.\n", id);
        return;
    }
    
    printf("One Student Found for ID: %s\n\n", students[index].studentId);
    printf("Student Information\n");
    printf("------------------------------\n");
    printf("%-15s: %s\n", "ID", students[index].studentId);
    printf("%-15s: %s\n", "Name", students[index].name);
    printf("%-15s: %02d/%02d/%04d\n", "Date of Birth", 
           students[index].dateOfBirth.day, 
           students[index].dateOfBirth.month, 
           students[index].dateOfBirth.year);
    printf("%-15s: %s\n", "Gender", students[index].gender ? "Male" : "Female");
    printf("%-15s: %s\n", "Email", students[index].email);
    printf("%-15s: %s\n", "Phone", students[index].phone);

  
    printf("Are you sure you want to delete this student? (Y/N): ");
    int confirm;
    scanf(" %c", &confirm);
    if (confirm == 'Y') {
       
        int j;
        for (j = index; j < studentCount - 1; j++) {
            students[j] = students[j + 1];
        }
        studentCount--;
        printf("Student Deleted Successfully.\n");
    } else {
        printf("Student Deletion Cancelled.\n");
    }

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return;
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}

//Tiet 3
void sortStudentsByName() {
    int choice;
    printf("Choose sorting order:\n");
    printf("[1] Ascending (A to Z)\n");
    printf("[2] Descending (Z to A)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
	
	int i, j;
    for (i = 0; i < studentCount - 1; i++) {
        for (j = i + 1; j < studentCount; j++) {
            if ((choice == 1 && strcmp(students[i].name, students[j].name) > 0) ||
                (choice == 2 && strcmp(students[i].name, students[j].name) < 0)) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("Students sorted successfully by name.\n");
    displayStudents(students, studentCount);
}



//Tiet 4
void searchStudentByName() {
    char keyword[30];
    printf("Enter the name keyword to search: ");
    scanf(" %[^\n]%*c", keyword);

    int found = 0;
    printf("\nStudents matching '%s':\n", keyword); 
    printf("|============|======================|=================|==========|======================|=================|\n");
    printf("| %-10s | %-20s | %-15s | %-8s | %-20s | %-15s |\n", 
           "ID", "Name", "Date of Birth", "Gender", "Email", "Phone");
    printf("|============|======================|=================|==========|======================|=================|\n");
	int i;
    for (i = 0; i < studentCount; i++) {
        if (strstr(students[i].name, keyword) != NULL) { 
            printf("| %-10s | %-20s | %02d/%02d/%04d      | %-8s | %-20s | %-15s |\n", 
                   students[i].studentId, 
                   students[i].name, 
                   students[i].dateOfBirth.day, 
                   students[i].dateOfBirth.month, 
                   students[i].dateOfBirth.year, 
                   students[i].gender ? "Male" : "Female", 
                   students[i].email, 
                   students[i].phone);
            printf("|------------|----------------------|-----------------|----------|----------------------|-----------------|\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No students found with the keyword '%s'.\n", keyword);
    }
}



