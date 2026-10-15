//Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

/*
Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3

*/
#include <stdio.h>
#include <string.h>

#define CHAR_RANGE 256  // Total possible ASCII characters

// Function to find length of longest substring without repeating characters
int longestUniqueSubstringLength(const char *s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int lastIndex[CHAR_RANGE]; // Stores last index of each character
    for (int i = 0; i < CHAR_RANGE; i++)
        lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0; // Start index of current window

    for (int end = 0; end < n; end++) {
        unsigned char ch = s[end];

        // If character was seen before and is inside current window
        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1; // Move start to avoid repetition
        }

        lastIndex[ch] = end; // Update last seen index
        int windowLen = end - start + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }

    return maxLen;
}

int main() {
    char s[1001]; // Buffer for input string (up to 1000 chars)

    printf("Enter string: ");
    if (scanf("%1000s", s) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int result = longestUniqueSubstringLength(s);
    printf("%d\n", result);

    return 0;
}
