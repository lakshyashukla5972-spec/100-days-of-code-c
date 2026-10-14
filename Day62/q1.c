//Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.

/*
Sample Test Cases:
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr[] = [-2, -4]
Output 2:
-2

Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

// Function implementing Kadane's algorithm
int maxSubarraySum(int arr[], int n) {
    int max_so_far = INT_MIN; // Tracks overall maximum sum
    int max_ending_here = 0;  // Tracks current subarray sum

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];

        // Update max_so_far if needed
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }

        // If current sum becomes negative, reset it to 0
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

int main() {
    int n;

    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
    }

    // Special handling for all-negative arrays
    int all_negative = 1;
    int largest_negative = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            all_negative = 0;
            break;
        }
        if (arr[i] > largest_negative) {
            largest_negative = arr[i];
        }
    }

    int result;
    if (all_negative) {
        result = largest_negative; // Largest (least negative) element
    } else {
        result = maxSubarraySum(arr, n);
    }

    printf("Maximum contiguous subarray sum: %d\n", result);

    free(arr);
    return 0;
}
