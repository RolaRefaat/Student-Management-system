/*
 ============================================================================================================
 * Mini_project
 * Name:Rola Refaat Bekhit Attalla
 * Created on: Aug 9, 2024
 * Diploma:91
 ============================================================================================================
 */
#include  "student.h"

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    struct student temp_student;  // Temporary storage for student details
    int num_of_operation;         // Variable to store the user's choice of operation
    int id;                       // Variable to store the student ID for operations

    while (1) {
        // Display the menu options
    	printf("-----------------------------------------------------\n");
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Search student by ID\n");
        printf("4. Update student information\n");
        printf("5. Delete student\n");
        printf("6. Calculate average GPA\n");
        printf("7. Search for student with highest GPA\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        // Read the user's choice as an integer
        scanf(" %d", &num_of_operation);
        printf("-----------------------------------------------------\n");
        // Handle the user's choice using a switch-case structure
        switch (num_of_operation) {
            case 1:
                // Adding a new student
                printf("Enter student ID: ");
                scanf("%d", &(temp_student.id));  // Read student ID (integer)

                printf("Enter student name: ");
                scanf(" %[^\n]s",temp_student.name);  // Read student name (string)

                printf("Enter student age: ");
                scanf("%d", &(temp_student.age));  // Read student age (integer)

                printf("Enter student GPA: ");
                scanf("%f", &(temp_student.gpa));  // Read student GPA (float)

                // Add the student to the list
                addStudent(&temp_student);
                break;

            case 2:
                // Displaying all students
                displayStudents();
                break;

            case 3:
                // Searching for a student by ID
                printf("Enter the ID of the student you are looking for: ");
                scanf("%d", &id);  // Read the student ID (integer)

                // Search for the student by ID
                searchStudentByID(id);
                break;

            case 4:
                // Updating a student's information
                printf("Enter the ID of the student whose data you want to modify: ");
                scanf("%d", &id);  // Read the student ID (integer)

                // Update the student's information
                updateStudent(id);
                break;

            case 5:
                // Deleting a student by ID
                printf("Enter the ID of the student you want to delete: ");
                scanf("%d", &id);  // Read the student ID (integer)

                // Delete the student from the list
                deleteStudent(id);
                break;

            case 6:
                // Calculating and displaying the average GPA of all students
                printf("Average GPA = %.2f\n", calculateAverageGPA());
                break;

            case 7:
                // Searching for and displaying the student with the highest GPA
                searchHighestGPA();
                break;

            case 8:
                // Exiting the program
                printf("Exiting the program.\n");
                return 0;

            default:
                // Handling invalid input
                printf("Invalid input. Please enter a number between 1 and 8.\n");
                break;
        }
    }

    return 0;
}















