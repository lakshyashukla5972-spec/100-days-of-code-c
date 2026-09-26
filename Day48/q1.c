//Q95: Check if one string is a rotation of another.

/*
Sample Test Cases:
Input 1:
abcde
deabc
Output 1:
Rotation

Input 2:
abc
acb
Output 2:
Not rotation

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if s2 is a rotation of s1
int isRotation(const char *s1, const char *s2) {
    // Check if lengths are equal
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (len1 != len2) {
        return 0; // Different lengths => not rotation
    }

    // Concatenate s1 with itself
    char *concat = malloc(len1 * 2 + 1);
    if (!concat) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    strcpy(concat, s1);
    strcat(concat, s1);

    // Check if s2 is a substring of concat
    int result = strstr(concat, s2) != NULL;

    free(concat);
    return result;
}

int main() {
    char s1[101], s2[101];

    printf("Enter first string: ");
    if (scanf("%100s", s1) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second string: ");
    if (scanf("%100s", s2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isRotation(s1, s2)) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }

    return 0;
}
