//Q66: Insert an element in a sorted array at the appropriate position.

/*
Sample Test Cases:
Input 1:
5
1 2 4 5 6
3
Output 1:
1 2 3 4 5 6
*/
#include <stdio.h>

#define MAX_SIZE 100  // Maximum array size

int main() {
    int arr[MAX_SIZE];
    int n, value, i, pos;

    // Read number of elements
    if (scanf("%d", &n) != 1 || n <= 0 || n >= MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Read sorted array elements
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        // Optional: Ensure input is sorted
        if (i > 0 && arr[i] < arr[i - 1]) {
            printf("Array is not sorted.\n");
            return 1;
        }
    }

    // Read value to insert
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Find position to insert
    pos = n; // default: insert at end
    for (i = 0; i < n; i++) {
        if (arr[i] > value) {
            pos = i;
            break;
        }
    }

    // Shift elements to the right
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the value
    arr[pos] = value;
    n++;

    // Print updated array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}