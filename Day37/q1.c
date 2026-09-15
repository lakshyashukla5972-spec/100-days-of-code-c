//Q73: Find the sum of each row of a matrix and store it in an array.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
6 15

*/
#include <stdio.h>
int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    int rowSums[rows];
    
    // Read the matrix and calculate the sum of each row
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0; // Initialize the sum for the current row
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            rowSums[i] += matrix[i][j]; // Add the element to the current row's sum
        }
    }
    
    // Print the sum of each row
    for (int i = 0; i < rows; i++) {
        printf("%d ", rowSums[i]);
    }
    printf("\n");
    
    return 0;
}