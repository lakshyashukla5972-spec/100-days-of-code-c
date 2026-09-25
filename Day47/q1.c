//Q93: Check if two strings are anagrams of each other.

/*
Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHAR_RANGE 256  // Total possible ASCII characters

// Function to check if two strings are anagrams
int areAnagrams(const char *str1, const char *str2) {
    int count[CHAR_RANGE] = {0};
    int i;

    // Count frequency of each character in str1
    for (i = 0; str1[i] != '\0'; i++) {
        if (!isspace((unsigned char)str1[i])) { // Ignore spaces
            count[tolower((unsigned char)str1[i])]++;
        }
    }

    // Subtract frequency based on str2
    for (i = 0; str2[i] != '\0'; i++) {
        if (!isspace((unsigned char)str2[i])) { // Ignore spaces
            count[tolower((unsigned char)str2[i])]--;
        }
    }

    // If all counts are zero, they are anagrams
    for (i = 0; i < CHAR_RANGE; i++) {
        if (count[i] != 0) {
            return 0; // Not anagrams
        }
    }
    return 1; // Anagrams
}

int main() {
    char str1[101], str2[101];

    printf("Enter first string: ");
    if (!fgets(str1, sizeof(str1), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("Enter second string: ");
    if (!fgets(str2, sizeof(str2), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (areAnagrams(str1, str2)) {
        printf("Anagrams\n");
    } else {
        printf("Not anagrams\n");
    }

    return 0;
}
