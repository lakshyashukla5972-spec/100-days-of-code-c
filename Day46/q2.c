//Q92: Find the first repeating lowercase alphabet in a string.

/*
Sample Test Cases:
Input 1:
stress
Output 1:
s

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the first repeating lowercase alphabet
char firstRepeatingLowercase(const char *str) {
    int freq[26] = {0}; // Frequency array for lowercase letters

    // First pass: count occurrences
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower((unsigned char)str[i])) {
            freq[str[i] - 'a']++;
        }
    }

    // Second pass: find the first lowercase letter with freq > 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower((unsigned char)str[i]) && freq[str[i] - 'a'] > 1) {
            return str[i];
        }
    }

    return '\0'; // No repeating lowercase letter found
}

int main() {
    char input[1000];

    printf("Enter a string: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char result = firstRepeatingLowercase(input);

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("No repeating lowercase alphabet found.\n");
    }

    return 0;
}

