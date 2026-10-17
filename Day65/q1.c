//Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

/*
Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if two strings are anagrams
int isAnagram(const char *s, const char *t) {
    // If lengths differ, they can't be anagrams
    if (strlen(s) != strlen(t)) {
        return 0;
    }

    int freq[26] = {0}; // Frequency array for lowercase letters

    // Count characters from s
    for (int i = 0; s[i] != '\0'; i++) {
        if (!islower(s[i])) { // Validate lowercase
            return 0;
        }
        freq[s[i] - 'a']++;
    }

    // Subtract counts using t
    for (int i = 0; t[i] != '\0'; i++) {
        if (!islower(t[i])) { // Validate lowercase
            return 0;
        }
        freq[t[i] - 'a']--;
    }

    // Check if all frequencies are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char s[101], t[101]; // Limit to 100 chars for safety

    printf("Enter first string (lowercase): ");
    if (scanf("%100s", s) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second string (lowercase): ");
    if (scanf("%100s", t) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isAnagram(s, t)) {
        printf("Anagram\n");
    } else {
        printf("Not Anagram\n");
    }

    return 0;
}
