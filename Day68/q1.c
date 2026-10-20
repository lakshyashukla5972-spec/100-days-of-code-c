//Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number

/*
Sample Test Cases:
Input 1:
nums1 = [0,3,2,4]
Output 1:
1

Input 2:
nums1 = [1,2,3]
Output 2:
0

Input 3:
nums1 = [0,4,3,1,5]
Output 3:
2

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    
    // Input validation for array size
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Size must be a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers (between 0 and %d, one missing):\n", n, n);
    long long sum = 0; // Use long long to avoid overflow for large n

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    // Expected sum of numbers from 0 to n
    long long expected_sum = (long long)n * (n + 1) / 2;

    // Missing number
    long long missing = expected_sum - sum;

    printf("Missing number: %lld\n", missing);

    free(arr);
    return 0;
}
