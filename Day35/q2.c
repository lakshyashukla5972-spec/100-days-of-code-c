//Q70: Rotate an array to the right by k positions.

/*
Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
4 5 1 2 3

*/
#include <stdio.h>
int main () {
    int n, i, k;
    scanf("%d", &n);
    int arr[n]; // Create an array to hold the elements

    // Read the original array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the number of positions to rotate
    scanf("%d", &k);

    // Normalize k to be within the bounds of the array length
    k = k % n;

    // Create a temporary array to hold the rotated elements
    int temp[n];

    // Rotate the array to the right by k positions
    for (i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Print the rotated array
    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    
    return 0;
}