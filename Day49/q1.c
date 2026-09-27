//Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to print initials in "X.Y." format
void printInitials(const char *name) {
    int len = strlen(name);
    int i = 0;

    // Skip leading spaces
    while (i < len && name[i] == ' ') {
        i++;
    }

    // If first character exists, print it as uppercase
    if (i < len && isalpha((unsigned char)name[i])) {
        printf("%c.", toupper((unsigned char)name[i]));
    }

    // Loop through the rest of the string
    for (; i < len; i++) {
        // If current char is space and next char is a letter, print initial
        if (name[i] == ' ' && i + 1 < len && isalpha((unsigned char)name[i + 1])) {
            printf("%c.", toupper((unsigned char)name[i + 1]));
        }
    }
}

int main() {
    char name[100];

    printf("Enter full name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printInitials(name);
    printf("\n");

    return 0;
}
