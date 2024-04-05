#include <stdio.h>
#define MAX 30

typedef struct {
    int ra;        
    float partial;  
    float exam;     
    int absences;   
} Student;

Student students[MAX];
int numStudents = 0;

void RegisterStudents() {
    if (numStudents >= MAX) {
        printf("Maximum number of students reached.\n");
        return;
    }
    int newRA;
    printf("Enter the Registration Number: ");
    scanf("%i", &newRA);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].ra == newRA) {
            printf("\nRA already registered.\n");
            return;
        }
    }

    students[numStudents].ra = newRA;

    printf("Enter the partial grade: ");
    scanf("%f", &students[numStudents].partial);

    printf("Enter the exam grade: ");
    scanf("%f", &students[numStudents].exam);

    printf("Enter the number of absences: ");
    scanf("%i", &students[numStudents].absences);

    numStudents++;

    printf("STUDENT REGISTERED SUCCESSFULLY!\n");
}

void Show() {
    printf("%-10s %-10s %-10s %-10s %-10s\n", "RA", "Partial", "Exam", "Absences", "Average");

    for (int i = 0; i < numStudents; i++) {
        float average = (students[i].exam + students[i].partial) / 2.0;
        if (students[i].absences > 20 || average < 7) {
            printf("%-10d %-10.2f %-10.2f %-10i %-10.2f FAILED\n",
                students[i].ra, students[i].partial, students[i].exam, students[i].absences, average);
        } else {
            printf("%-10d %-10.2f %-10.2f %-10i %-10.2f PASSED\n",
                students[i].ra, students[i].partial, students[i].exam, students[i].absences, average);
        }
    }
}

void Search() {

    int raToSearch;
    int studentFound = 0;

    printf("Enter the Registration Number of the student you want to search for:\n");
    scanf("%i", &raToSearch);

    printf("%-10s %-10s %-10s %-10s %-10s\n", "RA", "Partial", "Exam", "Absences", "Average");
    for (int i = 0; i < numStudents; i++) {
        float average = (students[i].exam + students[i].partial) / 2.0;
        if (students[i].ra == raToSearch) {
            printf("\n%-10d %-10.2f %-10.2f %-10i %-10.2f",
                students[i].ra, students[i].partial, students[i].exam, students[i].absences, average);
            studentFound = 1;
            break;
        } else {
            printf("Student not found.");
        }
    }
}

void Modify() {
    int newRA;
    printf("Enter the Registration Number of the student you want to modify: ");
    scanf("%i", &newRA);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].ra == newRA) {
            printf("Enter the new partial grade: ");
            scanf("%f", &students[i].partial);

            printf("Enter the new exam grade: ");
            scanf("%f", &students[i].exam);

            printf("Enter the new number of absences: ");
            scanf("%i", &students[i].absences);

            printf("STUDENT MODIFIED SUCCESSFULLY!\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void Report() {
    if (numStudents == 0) {
        printf("No students registered.\n");
        return;
    }

    int numPassed = 0;
    int numFailed = 0;
    float totalAverages = 0.0;
    float highestAverage = -1.0;
    float lowestAverage = 11.0;

    for (int i = 0; i < numStudents; i++) {
        float average = (students[i].exam + students[i].partial) / 2.0;
        totalAverages += average;

        if (average >= 7.0 && students[i].absences <= 20) {
            numPassed++;
        } else {
            numFailed++;
        }

        if (average > highestAverage) {
            highestAverage = average;
        }

        if (average < lowestAverage) {
            lowestAverage = average;
        }
    }

    float classAverage;

    if (numStudents > 0) {
        classAverage = totalAverages / numStudents;
    } else {
        classAverage = 0.0;
    }
    float passRate = (float)numPassed / numStudents * 100.0;
    float failRate = (float)numFailed / numStudents * 100.0;

    printf("\nReport:\n");
    printf("Total students: %d\n", numStudents);
    printf("Class Average: %.2f\n", classAverage);
    printf("Number of Passed Students: %d\n", numPassed);
    printf("Number of Failed Students: %d\n", numFailed);
    printf("Pass Rate: %.2f%%\n", passRate);
    printf("Fail Rate: %.2f%%\n", failRate);
    printf("Highest Average: %.2f\n", highestAverage);
    printf("Lowest Average: %.2f\n", lowestAverage);
}

int main() {
    int menu;

    do {
        printf("\n1- Register\n2- Show\n3- Search\n4- Modify\n5- Report\n6- Exit\n");
        scanf("%i", &menu);

        switch (menu) {
            case 1:
                RegisterStudents();
                break;

            case 2:
                Show();
                break;

            case 3:
                Search();
                break;

            case 4:
                Modify();
                break;

            case 5:
                Report();
                break;

            case 6:
                menu = 6;
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Select one of the menu options!\n");
        }
    } while (menu != 6);

    return 0;
}
