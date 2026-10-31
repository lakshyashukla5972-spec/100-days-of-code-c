//Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

/*
Sample Test Cases:
Input 1:
Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int n, i;
    
    // Variables to hold input data
    char name[50];
    int roll;
    float marks;

    // 1. Writing records to the file
    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Roll Number: ");
        scanf("%d", &roll);
        printf("Marks: ");
        scanf("%f", &marks);

        // Write to file using fprintf
        fprintf(file, "%s %d %.2f\n", name, roll, marks);
    }
    fclose(file);
    printf("\nRecords successfully saved to file.\n\n");

    // 2. Reading records from the file
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("--- Student Records ---\n");
    // Read from file using fscanf until end of file (EOF)
    while (fscanf(file, "%s %d %f", name, &roll, &marks) == 3) {
        // Displaying records in the required sample output format
        printf("Name: %s | Roll: %d | Marks: %.0f\n", name, roll, marks);
    }
    
    fclose(file);
    return 0;
}
