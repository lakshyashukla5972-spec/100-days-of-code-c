//Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

/*
Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1

*/
#include <stdio.h>

// Function to find pivot integer
int findPivot(int n) {
    // Total sum from 1 to n
    long totalSum = (long)n * (n + 1) / 2;

    // Iterate through possible pivot values
    for (int x = 1; x <= n; x++) {
        long leftSum = (long)x * (x + 1) / 2; // Sum from 1 to x
        long rightSum = totalSum - leftSum + x; // Sum from x to n

        if (leftSum == rightSum) {
            return x; // Found pivot
        }
    }
    return -1; // No pivot found
}

int main() {
    int n;

    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int pivot = findPivot(n);
    printf("%d\n", pivot);

    return 0;
}
