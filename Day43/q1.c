//Q85: Reverse a string.

/*
Sample Test Cases:
Input 1:
abcd
Output 1:
dcba

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
    
    // Reverse the string
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    
    printf("\n");
    return 0;
}