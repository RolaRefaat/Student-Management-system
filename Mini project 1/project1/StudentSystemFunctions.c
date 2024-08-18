/*
 * StudentSystemFunctions.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Rola
 */
#include "student.h"


/* Initialize the head of the linked list to NULL */
struct node * head=NULL;

/* Function to add a new student to the linked list */

void addStudent(const struct student *const ptr) {
    // Allocate memory for a new node
    struct node *link = (struct node *)malloc(sizeof(struct node));

    // Check if memory allocation was successful
    if (NULL == link) {
        printf("Memory allocation failed\n");
        return;
    }

    // Copy student data from the input pointer to the new node
    link->data.id = ptr->id;
    strcpy(link->data.name, ptr->name);
    link->data.age = ptr->age;
    link->data.gpa = ptr->gpa;
    link->next = NULL;

    // If the linked list is empty, add the new node as the first element
    if (NULL == head) {
        head = link;
        return;
    }

    // Traverse the list to check if the student ID already exists
    struct node *current = head;
    struct node *prev=NULL;
    while (NULL != current) {
        if (current->data.id == ptr->id) {
            printf("Error: This ID already exists\n");
            free(link);  // Free the allocated memory as it's no longer needed
            return;
        }
        prev=current;
        current = current->next;
    }

        // Link the new node to the end of the list
        prev->next = link;
    }



/* Function to display the details of all students in the linked list */

void displayStudents(void) {
    int i = 0;  // Initialize a counter to track the student number

    // Check if the linked list is empty
    if (NULL == head) {
        printf("The list is empty\n");  // Print a message if no students are present
        return;
    }

    struct node *current = head;  // Start traversing from the head of the list

    // Traverse the linked list
    while (NULL != current) {
        // Print the details of the current student, each on a separate line
        printf("Student[%d] details:\n", ++i);
        printf("ID: %d\n", current->data.id);
        printf("Name: %s\n", current->data.name);
        printf("Age: %d\n", current->data.age);
        printf("GPA: %.2f\n", current->data.gpa);

        // Move to the next node in the list
        current = current->next;

        printf("----------------------------\n");
    }
   }

/* Function to search for a student by their ID and display their details */

void searchStudentByID(int id) {
    // Check if the linked list is empty
    if (NULL == head) {
        printf("There are no students in the List.\n");
        return;
    }

    struct node *current = head;  // Start traversing from the head of the list

    // Traverse the linked list to find the student by ID
    while (NULL != current) {
        // Check if the current student's ID matches the search ID
        if (current->data.id == id) {
            // If the student is found, print the student's details
            printf("The student information is:\n");
            printf("ID: %d\n", current->data.id);
            printf("Name: %s\n", current->data.name);
            printf("Age: %d\n", current->data.age);
            printf("GPA: %.2f\n", current->data.gpa);
            return;  // Exit the function as the student has been found
        }
        current = current->next;  // Move to the next node in the list
    }

    // If the student is not found, print a message indicating this
    printf("This ID was not found in the list.\n");
}

/* Function to update the details of a student with the given ID */

void updateStudent(int id) {
    // Check if the linked list is empty
    if (NULL == head) {
        printf("There are no students in the list.\n");
        return;
    }

    struct node *current = head;  // Start traversing from the head of the list

    // Traverse the linked list to find the student by ID
    while (NULL != current) {
        if (current->data.id == id) {
            // If the student is found, update the student's information
            printf("Student found in the list.\n");

            printf("Please enter the student's new name:\n");
            scanf(" %[^\n]s",current->data.name);

            printf("Please enter the student's new age:\n");
            scanf("%d", &(current->data.age));

            printf("Please enter the student's new GPA:\n");
            scanf("%f", &(current->data.gpa));

            printf("Student information updated successfully.\n");
            return;
        }
        current = current->next;  // Move to the next node in the list
    }

    // If the student is not found, print a message indicating this
    printf("Student not found in the list.\n");
}

/* Function to calculate and return the average GPA of all students */

float calculateAverageGPA(void) {
    float sum = 0.0;               // Initialize the sum of GPAs to 0
    int num_of_students = 0;       // Initialize the number of students to 0
    struct node *current = head;   // Start traversing from the head of the list

    // Check if the linked list is empty
    if (NULL == head) {
        printf("The list is empty.\n");
        return 0;  // Return 0 if there are no students
    }

    // Traverse the linked list to sum the GPAs and count the students
    while (NULL != current) {
        sum += current->data.gpa;  // Add the current student's GPA to the sum
        num_of_students++;         // Increment the number of students
        current = current->next;   // Move to the next node in the list
    }

    // Calculate and return the average GPA
    return sum / num_of_students;
}

/* Function to find and display the student with the highest GPA */
void searchHighestGPA(void) {
    // Check if the linked list is empty
    if (NULL == head) {
        printf("The list is empty.\n");
        return;
    }

    struct node *current = head->next;  // Start from the second node
    struct node *temp = head;           // Temp pointer to keep track of the highest GPA

    float max = head->data.gpa;         // Initialize max with the GPA of the first student

    // Traverse the linked list to find the student with the highest GPA
    while (NULL != current) {
        if ((current->data.gpa) > max) {
            max = current->data.gpa;
            temp = current;
        }
        current = current->next;
    }

    // Print the details of the student with the highest GPA
    if (temp) {
        printf("The student with the highest GPA information is:\n");
        printf("ID: %d\n", temp->data.id);
        printf("Name: %s\n", temp->data.name);
        printf("Age: %d\n", temp->data.age);
        printf("GPA: %.2f\n", temp->data.gpa);
    }
}
/* Function to delete a student from the linked list by their ID */

void deleteStudent(int id) {
    struct node *current = NULL;
    struct node *prev = NULL;
    struct node *delete_node = NULL;

    // Check if the linked list is empty
    if (NULL == head) {
        printf("The list is empty.\n");
        return;
    }

    // Check if the student to be deleted is the first node (head)
    if (head->data.id == id) {
        delete_node = head;
        head = head->next;
        free(delete_node);
        printf("Student data successfully deleted.\n");
        return;
    }

    current = head->next;
    prev = head;

    // Traverse the list to find the student by ID
    while (NULL != current) {
        if (current->data.id == id) {
            delete_node = current;
            prev->next = current->next;
            free(delete_node);
            printf("Student data successfully deleted.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    // If the student was not found in the list
        printf("This ID was not found in the list.\n");
    }

