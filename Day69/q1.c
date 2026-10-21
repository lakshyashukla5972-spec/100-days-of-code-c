//Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

/*
Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input array size
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Invalid size. Must be > 1.\n");
        return 1;
    }

    int *nums = malloc(n * sizeof(int));
    if (!nums) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input.\n");
            free(nums);
            return 1;
        }
    }

    // Find max value to size the seen array
    int maxVal = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    // Allocate seen array (initialized to 0)
    int *seen = calloc(maxVal + 1, sizeof(int));
    if (!seen) {
        printf("Memory allocation failed.\n");
        free(nums);
        return 1;
    }

    // Single iteration to find repeated element
    for (int i = 0; i < n; i++) {
        if (seen[nums[i]] == 1) {
            printf("Repeated element: %d\n", nums[i]);
            free(nums);
            free(seen);
            return 0; // Found, exit immediately
        }
        seen[nums[i]] = 1;
    }

    // If no repeated element found (shouldn't happen per problem statement)
    printf("No repeated element found.\n");

    free(nums);
    free(seen);
    return 0;
}
