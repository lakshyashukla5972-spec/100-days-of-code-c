//Q79: Perform diagonal traversal of a matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/
#include <stdio.h>
int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int d = 0; d < rows + cols - 1; d++) {
        if (d % 2 == 0) {
            for (int i = d < rows ? d : rows - 1; i >= 0 && d - i < cols; i--) {
                printf("%d ", matrix[i][d - i]);
            }
        } else {
            for (int i = d < cols ? 0 : d - cols + 1; i < rows && d - i >= 0; i++) {
                printf("%d ", matrix[i][d - i]);
            }
        }
    }
    printf("\n");
    return 0;
}