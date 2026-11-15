//Q145: Return a structure containing top student's details from a function.

/*
Sample Test Cases:
Input 1:
3 students: Riya 101 89, Karan 102 96, Meena 103 92
Output 1:
Top Student: Karan | Roll: 102 | Marks: 96

*/
#include <stdio.h>

// Define the structure for a Student
struct Student {
    char name[50];
    int roll;
    int marks;
};

// Function that accepts an array of structures and returns the top student's structure
struct Student getTopStudent(struct Student s[], int n) {
    struct Student top = s[0]; // Assume the first student has the highest marks
    
    for (int i = 1; i < n; i++) {
        if (s[i].marks > top.marks) {
            top = s[i]; // Update top student if current student has higher marks
        }
    }
    
    return top; // Return the structure containing the top student's details
}

int main() {
    int n;
    
    // Input the number of students
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student students[n];
    
    // Input details for each student
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", students[i].name, &students[i].roll, &students[i].marks);
    }
    
    // Call the function and store the returned structure
    struct Student winner = getTopStudent(students, n);
    
    // Output the top student's details in the required format
    printf("Top Student: %s | Roll: %d | Marks: %d\n", winner.name, winner.roll, winner.marks);
    
    return 0;
}
