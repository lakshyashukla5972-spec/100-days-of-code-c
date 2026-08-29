//Q39: Write a program to find the product of odd digits of a number.

/*
Sample Test Cases:
Input 1:
12345
Output 1:
15 (1*3*5)

Input 2:
2468
Output 2:
1 (no odd digits, assume 1)

*/
#include <stdio.h>
int main() {
    int num, digit, product = 1;
    int hasOddDigit = 0; // Flag to check if there are any odd digits

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Process each digit of the number
    while (num > 0) {
        digit = num % 10; // Get the last digit
        if (digit % 2 != 0) { // Check if the digit is odd
            product *= digit; // Multiply the odd digit to the product
            hasOddDigit = 1; // Set flag to indicate presence of odd digit
        }
        num /= 10; // Remove the last digit
    }

    // If no odd digits were found, set product to 1
    if (!hasOddDigit) {
        product = 1;
    }

    printf("Product of odd digits is: %d\n", product);
    return 0;
}