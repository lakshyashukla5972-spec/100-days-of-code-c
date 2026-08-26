//Q34: Write a program to check if a number is prime.

/*
Sample Test Cases:
Input 1:
7
Output 1:
Prime

Input 2:
10
Output 2:
Not prime

*/
#include <stdio.h>
int main() {
    int num, i, flag = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // 0 and 1 are not prime numbers
    if (num <= 1) {
        printf("Not prime\n");
        return 0;
    }

    // Check for factors from 2 to the square root of num
    for (i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Prime\n");
    else
        printf("Not prime\n");

    return 0;
}