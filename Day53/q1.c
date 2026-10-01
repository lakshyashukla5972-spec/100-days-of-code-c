//Q103: Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.

/*
Sample Test Cases:
Input 1:
nums = [1,7,3,6,5,6]
Output 1:
3

Input 2:
nums = [1,2,3]
Output 2:
-1

Input 3:
nums = [2,1,-1]
Output 3:
0

*/
#include <stdio.h>
#include <stdlib.h>

// Function to find the leftmost pivot index
int pivotIndex(int nums[], int n) {
    if (n <= 0) return -1;

    long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    long leftSum = 0;
    for (int i = 0; i < n; i++) {
        long rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i; // Found leftmost pivot index
        }
        leftSum += nums[i];
    }
    return -1; // No pivot index found
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    if (!nums) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            return 1;
        }
    }

    int result = pivotIndex(nums, n);
    printf("%d\n", result);

    free(nums);
    return 0;
}
