//Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0

*/
#include <stdio.h>
#include <stdlib.h>

// Function to find first negative integer in every window of size k
void firstNegativeInWindow(int arr[], int n, int k) {
    int negIndex[n]; // Stores indices of negative numbers
    int front = 0, rear = 0; // Queue pointers

    // Process first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negIndex[rear++] = i;
        }
    }

    // Output for first window
    if (front < rear) {
        printf("%d ", arr[negIndex[front]]);
    } else {
        printf("0 ");
    }

    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove negatives that are out of this window
        while (front < rear && negIndex[front] <= i - k) {
            front++;
        }

        // Add new negative number if present
        if (arr[i] < 0) {
            negIndex[rear++] = i;
        }

        // Output first negative for current window
        if (front < rear) {
            printf("%d ", arr[negIndex[front]]);
        } else {
            printf("0 ");
        }
    }
    printf("\n");
}

int main() {
    int n, k;

    // Input array size
    printf("Enter number of elements: ");
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

    // Input window size
    printf("Enter window size k: ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid window size.\n");
        free(arr);
        return 1;
    }

    // Process and output results
    firstNegativeInWindow(arr, n, k);

    free(arr);
    return 0;
}
