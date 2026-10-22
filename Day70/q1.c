//Q120: Write a program to take a string input. Change it to sentence case.

/*
Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.

*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to convert a string to sentence/title case
void toSentenceCase(char *str) {
    int capitalizeNext = 1; // Flag to capitalize the next letter

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace((unsigned char)str[i])) {
            // If space found, next character should be capitalized
            capitalizeNext = 1;
        } else if (capitalizeNext && isalpha((unsigned char)str[i])) {
            // Capitalize first letter of each word
            str[i] = toupper((unsigned char)str[i]);
            capitalizeNext = 0;
        } else {
            // Lowercase other letters
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}

int main() {
    char str[500];

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    toSentenceCase(str);

    printf("Sentence Case: %s\n", str);

    return 0;
}
