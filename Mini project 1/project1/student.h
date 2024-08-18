/*
 * student.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Rola
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int id;             /* Student ID */
	char name[50];      /* Student Name */
	int age;            /* Student Age */
	float gpa;          /* Student GPA */
};

/* Define a node structure to create a linked list of students */
struct node
{
	struct student data;      /* Student data stored in the node */

	struct node *next;        /* Pointer to the next node in the list */
};


// Function prototypes
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
void deleteStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);

#endif

