//Q146: Create Employee structure with nested Date structure for joining date and print details.

/*
Sample Test Cases:
Input 1:
Employee: Raj | ID: 11 | Joining Date: 12 05 2020
Output 1:
Name: Raj | ID: 11 | Joining Date: 12/05/2020

*/
#include <stdio.h>

// Define the nested Date structure
struct Date {
    int day;
    int month;
    int year;
};

// Define the Employee structure containing the Date structure
struct Employee {
    char name[50];
    int id;
    struct Date joiningDate;
};

int main() {
    struct Employee emp;

    // Input employee details matching the sample format
    scanf("Employee: %s | ID: %d | Joining Date: %d %d %d", 
          emp.name, 
          &emp.id, 
          &emp.joiningDate.day, 
          &emp.joiningDate.month, 
          &emp.joiningDate.year);

    // Print the formatted output with leading zeros for day and month
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n", 
           emp.name, 
           emp.id, 
           emp.joiningDate.day, 
           emp.joiningDate.month, 
           emp.joiningDate.year);

    return 0;
}
