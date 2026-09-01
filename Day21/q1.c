//Q41: Write a program to swap the first and last digit of a number.

/*
Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001

*/
#include <stdio.h>
int main() {
    int num, firstDigit, lastDigit, numDigits = 0, tempNum, swappedNum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Store the original number for later use
    tempNum = num;

    // Find the last digit
    lastDigit = num % 10;

    // Count the number of digits and find the first digit
    while (tempNum > 0) {
        firstDigit = tempNum % 10;
        tempNum /= 10;
        numDigits++;
    }

    // If the number has only one digit, no swap is needed
    if (numDigits == 1) {
        printf("Swapped number: %d\n", num);
        return 0;
    }

    // Remove the first and last digits from the original number
    int middlePart = (num / 10) % (int)pow(10, numDigits - 2);

    // Construct the new number with swapped digits
    swappedNum = lastDigit * (int)pow(10, numDigits - 1) + middlePart * 10 + firstDigit;

    printf("Swapped number: %d\n", swappedNum);
    
    return 0;
}