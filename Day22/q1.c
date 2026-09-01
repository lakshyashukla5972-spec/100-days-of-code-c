//Q43: Write a program to check if a number is a strong number.

/*
Sample Test Cases:
Input 1:
145
Output 1:
Strong number

Input 2:
123
Output 2:
Not strong number

*/
#include <stdio.h>
int main() {
    int num, tempNum, sum = 0, digit, factorial;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    tempNum = num;
    
    while (tempNum > 0) {
        digit = tempNum % 10;
        
        // Calculate factorial of the digit
        factorial = 1;
        for (int i = 1; i <= digit; i++) {
            factorial *= i;
        }
        
        sum += factorial;
        tempNum /= 10;
    }
    
    if (sum == num) {
        printf("Strong number\n");
    } else {
        printf("Not strong number\n");
    }
    
    return 0;
}