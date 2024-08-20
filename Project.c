/*
 *  Created on: Aug 11, 2024
 *  Author: kareem Medhat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    char name[75];
    int age;
    float gpa;
    struct student* next;
};

struct student* head = NULL;

void addStudent(struct student* newStudent);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);

int main(void)
{
    int choice, id;
    struct student newStudent;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Calculate Average GPA\n");
        printf("7. Find Student with Highest GPA\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student ID: ");
            scanf("%d", &newStudent.id);
            printf("Enter name: ");
            scanf("%s", newStudent.name);
            printf("Enter age: ");
            scanf("%d", &newStudent.age);
            printf("Enter GPA: ");
            scanf("%f", &newStudent.gpa);
            addStudent(&newStudent);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter student ID to search: ");
            scanf("%d", &id);
            searchStudentByID(id);
            break;
        case 4:
            printf("Enter student ID to update: ");
            scanf("%d", &id);
            updateStudent(id);
            break;
        case 5:
            printf("Enter student ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
        case 6:
            printf("Average GPA: %.2f\n", calculateAverageGPA());
            break;
        case 7:
            searchHighestGPA();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addStudent(struct student* newStudent)
{
    struct student* current = head;

    while (current != NULL)
    {
        if (current->id == newStudent->id)
        {
            printf("Student ID already exists!\n");
            return;
        }
        current = current->next;
    }

    struct student* newNode = (struct student*)malloc(sizeof(struct student));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    *newNode = *newStudent;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Student added successfully!\n");
}

void displayStudents(void)
{
    struct student* current = head;

    if (current == NULL)
    {
        printf("No students found!\n");
        return;
    }
    while (current != NULL)
    {
        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", current->id, current->name, current->age, current->gpa);
        current = current->next;
    }
}

void searchStudentByID(int id)
{
    struct student* current = head;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", current->id, current->name, current->age, current->gpa);
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
}

void updateStudent(int id)
{
    struct student* current = head;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("Enter new name: ");
            scanf("%s", current->name);
            printf("Enter new age: ");
            scanf("%d", &current->age);
            printf("Enter new GPA: ");
            scanf("%f", &current->gpa);
            printf("Student updated successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("Student not found!\n");
}

float calculateAverageGPA(void)
{
    struct student* current = head;

    int count = 0;
    float sum = 0.0;

    while (current != NULL)
    {
        sum += current->gpa;
        count++;
        current = current->next;
    }
    if (count == 0)
        return 0.0;

    return sum / count;
}

void searchHighestGPA(void)
{
    struct student* current = head;

    if (current == NULL)
    {
        printf("No students found!\n");
        return;
    }

    struct student* maxStudent = current;

    while (current != NULL)
    {
        if (current->gpa > maxStudent->gpa)
        {
            maxStudent = current;
        }
        current = current->next;
    }
    printf("Student with the highest GPA: ID: %d, Name: %s, Age: %d, GPA: %.2f\n", maxStudent->id, maxStudent->name, maxStudent->age, maxStudent->gpa);
}

void deleteStudent(int id)
{
    struct student* current = head;
    struct student* prev = NULL;

    while (current != NULL)
    {
        if (current->id == id)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Student deleted successfully!\n");

            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Student not found!\n");
}
