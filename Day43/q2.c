//Q86: Check if a string is a palindrome.

/*
Sample Test Cases:
Input 1:
madam
Output 1:
Palindrome

Input 2:
hello
Output 2:
Not palindrome

*/
#include <stdio.h>
int main() {
    char str[100];
    scanf("%s", str);
    
    // Find the length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    // Check if the string is a palindrome
    int isPalindrome = 1; // Assume it is a palindrome
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
    }
    
    if (isPalindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    
    return 0;
}