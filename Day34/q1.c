//Q67: Insert an element in an array at a given position.

/*
Sample Test Cases:
Input 1:
4
10 20 30 40
2 15
Output 1:
10 20 15 30 40

*/
#include <stdio.h>
int main () {
    
    int n, i, pos, element;
    scanf("%d", &n);
    int arr[n + 1]; // Create an array with one extra space for the new element

    // Read the original array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the position and the new element to be inserted
    scanf("%d %d", &pos, &element);

    // Shift elements to the right to make space for the new element
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified position
    arr[pos - 1] = element;

    // Print the updated array
    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}