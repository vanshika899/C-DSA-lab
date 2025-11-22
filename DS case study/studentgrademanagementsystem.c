#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int studentID;
    char name[50];
    float marks_DS;
    float marks_C;
    struct Student *next;
} Student;

Student *head = NULL;

void displayMenu();
void addStudent();
void displayAllStudents();
void searchStudentByID();
void calculateAverages();
void deleteStudentByID();
void freeList();

int main() {
    int choice;
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("\n*** Invalid input! Please enter a number. ***\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudentByID(); break;
            case 4: calculateAverages(); break;
            case 5: deleteStudentByID(); break;
            case 6: 
                printf("\n*** Exiting the Student Management System. ***\n");
                freeList();
                break;
            default:
                printf("\n*** Invalid choice. Please try again (1-6). ***\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n==============================================\n");
    printf("  MCA Student Grade Management System (C/DS)\n");
    printf("==============================================\n");
    printf("1. Add New Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by ID\n");
    printf("4. Calculate and Display Averages\n");
    printf("5. Delete Student Record by ID\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addStudent() {
    Student *newNode = (Student*)malloc(sizeof(Student));
    if (!newNode) {
        printf("\n!!! Memory allocation failed. Cannot add student. !!!\n");
        return;
    }

    printf("\n--- Add New Student ---\n");

    int idUnique = 0;
    while (!idUnique) {
        printf("Enter Student ID: ");
        scanf("%d", &newNode->studentID);

        Student *current = head;
        idUnique = 1;
        while (current != NULL) {
            if (current->studentID == newNode->studentID) {
                printf("*** This Student ID (%d) already exists! Please enter a unique ID. ***\n", newNode->studentID);
                idUnique = 0;
                break;
            }
            current = current->next;
        }
    }

    printf("Enter Name: ");
    while (getchar() != '\n'); 
    fgets(newNode->name, 50, stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0;

    printf("Enter Marks in Data Structures: ");
    scanf("%f", &newNode->marks_DS);
    printf("Enter Marks in C Language: ");
    scanf("%f", &newNode->marks_C);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("\n>>> Student ID %d added as the first record. <<<\n", newNode->studentID);
    } else {
        Student *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
        printf("\n>>> Student ID %d added to the list. <<<\n", newNode->studentID);
    }
}

void displayAllStudents() {
    if (head == NULL) {
        printf("\n*** The student record list is currently empty. ***\n");
        return;
    }

    printf("\n========================================================================\n");
    printf("                       ALL STUDENT RECORDS\n");
    printf("========================================================================\n");
    printf(" ID   | Name                                | DS Marks | C Marks | Average\n");
    printf("------------------------------------------------------------------------\n");

    Student *current = head;
    printf("Existing Student IDs: ");
    while (current != NULL) {
        printf("%d ", current->studentID);
        current = current->next;
    }
    printf("\n------------------------------------------------------------------------\n");

    current = head;
    while (current != NULL) {
        float avg = (current->marks_DS + current->marks_C) / 2.0;
        printf(" %-4d | %-35s | %-8.2f | %-7.2f | %.2f\n",
               current->studentID, current->name,
               current->marks_DS, current->marks_C, avg);
        current = current->next;
    }
    printf("========================================================================\n");
}

void searchStudentByID() {
    if (head == NULL) {
        printf("\n*** The list is empty. Cannot search. ***\n");
        return;
    }

    int searchID;
    printf("\nEnter the Student ID to search: ");
    scanf("%d", &searchID);

    Student *current = head;
    int found = 0;
    while (current != NULL) {
        if (current->studentID == searchID) {
            printf("\n--- Student Found ---\n");
            printf("ID: %d\n", current->studentID);
            printf("Name: %s\n", current->name);
            printf("DS Marks: %.2f\n", current->marks_DS);
            printf("C Marks: %.2f\n", current->marks_C);
            printf("Overall Average: %.2f\n", (current->marks_DS + current->marks_C)/2.0);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found)
        printf("\n*** Student with ID %d not found in the records. ***\n", searchID);
}

void calculateAverages() {
    if (head == NULL) {
        printf("\n*** The list is empty. No averages to calculate. ***\n");
        return;
    }

    float totalDS = 0.0, totalC = 0.0;
    int count = 0;
    Student *current = head;

    while (current != NULL) {
        totalDS += current->marks_DS;
        totalC += current->marks_C;
        count++;
        current = current->next;
    }

    printf("\n--- Average Marks Report (Total %d Students) ---\n", count);
    printf("Average Marks in Data Structures: %.2f\n", totalDS / count);
    printf("Average Marks in C Language: %.2f\n", totalC / count);
    printf("-------------------------------------------------\n");
}

void deleteStudentByID() {
    if (head == NULL) {
        printf("\n*** The list is empty. Nothing to delete. ***\n");
        return;
    }

    int deleteID;
    printf("\nEnter the Student ID to delete: ");
    scanf("%d", &deleteID);

    Student *current = head;
    Student *prev = NULL;

    if (current != NULL && current->studentID == deleteID) {
        head = current->next;
        free(current);
        printf("\n>>> Student ID %d (Head Node) successfully deleted. <<<\n", deleteID);
        return;
    }

    while (current != NULL && current->studentID != deleteID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\n*** Student with ID %d not found. Deletion failed. ***\n", deleteID);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("\n>>> Student ID %d successfully deleted. <<<\n", deleteID);
}

void freeList() {
    Student *current = head;
    Student *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}
