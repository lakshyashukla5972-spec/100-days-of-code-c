//Q69: Find the second largest element in an array.

/*
Sample Test Cases:
Input 1:
5
10 20 30 40 50
Output 1:
40

*/
#include <stdio.h>
int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n]; // Create an array to hold the elements

    // Read the original array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize variables to find the largest and second largest elements
    int largest = arr[0];
    int secondLargest = -1; // Assuming all elements are positive

    // Iterate through the array to find the largest and second largest elements
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    // Print the second largest element
    printf("%d\n", secondLargest);
    
    return 0;
}