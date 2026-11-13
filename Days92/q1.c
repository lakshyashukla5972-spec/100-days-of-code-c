//Q142: Store details of 5 students in an array of structures and print all.

/*
Sample Test Cases:
Input 1:
Details of 5 students (Name, Roll, Marks)
Output 1:
Tabular list of all 5 students with their details

*/
#include <stdio.h>

// Define the structure for a student
struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s[5]; // Array of structures for 5 students
    int i;

    // Input details for 5 students
    printf("Enter details of 5 students (Name, Roll, Marks):\n");
    for (i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);
        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Output: Tabular list of all 5 students
    printf("\n--- Tabular List of Students ---\n");
    printf("%-20s %-10s %-10s\n", "Name", "Roll", "Marks");
    printf("----------------------------------------\n");
    for (i = 0; i < 5; i++) {
        printf("%-20s %-10d %-10.2f\n", s[i].name, s[i].roll, s[i].marks);
    }

    return 0;
}
