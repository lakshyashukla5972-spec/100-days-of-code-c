//Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

/*
Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400

*/
#include <stdio.h>
#include <stdlib.h>

// Function to find maximum sum of subarrays of size k
int maxSubarraySum(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        return -1; // Invalid k
    }

    // Calculate sum of first window
    int window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

    int max_sum = window_sum;

    // Slide the window
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    return max_sum;
}

int main() {
    int n, k;

    // Input array size
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    // Input k
    printf("Enter subarray size k: ");
    if (scanf("%d", &k) != 1) {
        printf("Invalid input.\n");
        free(arr);
        return 1;
    }

    int result = maxSubarraySum(arr, n, k);
    if (result == -1) {
        printf("Invalid subarray size k.\n");
    } else {
        printf("Maximum sum of subarrays of size %d is: %d\n", k, result);
    }

    free(arr);
    return 0;
}
