//Q52: Write a program to print the following pattern:
/*
*

*
*
*

*
*
*
*
*

*
*
*

*
*/


/*
Sample Test Cases:
Input 1:

Output 1:
Pattern with stars spaced irregularly as shown.

*/
#include <stdio.h>
int main() {
    int n = 5; // Number of rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) {
            printf("*");
            if (k < i) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}