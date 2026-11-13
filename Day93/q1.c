//Q143: Find and print the student with the highest marks.

/*
Sample Test Cases:
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)

*/
#include <stdio.h>

// Define a structure to hold student details
struct Student {
    char name[50];
    int rollNo;
    int marks;
};

int main() {
    int n, i, topperIndex = 0;

    // Read the number of students
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    struct Student s[n];

    // Read details for each student
    for (i = 0; i < n; i++) {
        scanf("%s %d %d", s[i].name, &s[i].rollNo, &s[i].marks);
        
        // Update topperIndex if the current student has higher marks
        if (s[i].marks > s[topperIndex].marks) {
            topperIndex = i;
        }
    }

    // Print the topper's name and marks in the exact required format
    printf("Topper: %s (Marks: %d)\n", s[topperIndex].name, s[topperIndex].marks);

    return 0;
}
