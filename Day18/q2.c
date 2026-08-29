//Q36: Write a program to find the HCF (GCD) of two numbers.

/*
Sample Test Cases:
Input 1:
12 18
Output 1:
6

Input 2:
7 9
Output 2:
1

*/
#include <stdio.h>
int main() {
    int num1, num2, hcf;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Find the HCF using the Euclidean algorithm
    while (num2 != 0) {
        hcf = num2;
        num2 = num1 % num2;
        num1 = hcf;
    }

    printf("HCF (GCD) is: %d\n", hcf);

    return 0;
}