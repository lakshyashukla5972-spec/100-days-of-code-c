//Q84: Convert a lowercase string to uppercase without using built-in functions.

/*
Sample Test Cases:
Input 1:
hello
Output 1:
HELLO

*/
#include <stdio.h>
int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') { // Check if character is lowercase
            str[i] = str[i] - ('a' - 'A'); // Convert to uppercase
        }
        i++;
    }
    printf("%s", str);
    return 0;
}