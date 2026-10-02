//Q105: Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.

/*
Sample Test Cases:
Input 1:
nums = [3,2,3]
Output 1:
3

Input 2:
nums = [2,2,1,1,1,2,2]
Output 2:
2

Input 3:
nums = [2,2,1,1,1,2,2,3]
Output 3:
-1

*/
#include <stdio.h>
#include <stdlib.h>

// Function to find majority element using Boyer–Moore Voting Algorithm
int findMajorityElement(int nums[], int n) {
    int candidate = 0;
    int count = 0;

    // Phase 1: Find a candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    // Majority condition: strictly more than floor(n/2)
    if (count > n / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    int n;

    // Input array size
    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    if (!nums) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input.\n");
            free(nums);
            return 1;
        }
    }

    // Find and print majority element
    int result = findMajorityElement(nums, n);
    printf("%d\n", result);

    free(nums);
    return 0;
}
