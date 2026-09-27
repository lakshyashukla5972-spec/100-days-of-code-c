//Q100: Print all sub-strings of a string.

/*
Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c

*/
#include <stdio.h>
#include <string.h>

// Function to print all substrings of a given string
void printSubstrings(const char *str) {
    int len = strlen(str);
    int firstPrinted = 0; // To handle comma formatting

    // Outer loop for start index
    for (int start = 0; start < len; start++) {
        // Inner loop for end index
        for (int end = start; end < len; end++) {
            // Print comma before substring except for the first one
            if (firstPrinted) {
                printf(",");
            }
            firstPrinted = 1;

            // Print substring from start to end
            for (int k = start; k <= end; k++) {
                printf("%c", str[k]);
            }
        }
    }
    printf("\n");
}

int main() {
    char input[100];

    printf("Enter a string: ");
    // Read input safely
    if (scanf("%99s", input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Handle empty string case
    if (strlen(input) == 0) {
        printf("No substrings for empty string.\n");
        return 0;
    }

    printSubstrings(input);

    return 0;
}
