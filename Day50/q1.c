//Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

/*
Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to validate date format dd/04/yyyy
int validate_date(const char *date) {
    // Expected length: 10 characters (dd/mm/yyyy)
    if (strlen(date) != 10) return 0;

    // Check slashes at correct positions
    if (date[2] != '/' || date[5] != '/') return 0;

    // Check month is "04"
    if (date[3] != '0' || date[4] != '4') return 0;

    // Check day is between 01 and 30 (April has 30 days)
    int day = atoi(date);
    if (day < 1 || day > 30) return 0;

    // Check year is numeric
    for (int i = 6; i < 10; i++) {
        if (date[i] < '0' || date[i] > '9') return 0;
    }

    return 1;
}

int main() {
    char date[20];
    char day[3], year[5];

    printf("Enter date in dd/04/yyyy format: ");
    if (scanf("%19s", date) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Validate input
    if (!validate_date(date)) {
        printf("Invalid date format or month not April.\n");
        return 1;
    }

    // Extract day and year
    day[0] = date[0];
    day[1] = date[1];
    day[2] = '\0';

    year[0] = date[6];
    year[1] = date[7];
    year[2] = date[8];
    year[3] = date[9];
    year[4] = '\0';

    // Output in dd-Apr-yyyy format
    printf("%s-Apr-%s\n", day, year);

    return 0;
}
