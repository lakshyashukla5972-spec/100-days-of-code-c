//Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

/*
Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]

*/
#include <stdio.h>
#include <stdlib.h>

// Function to compute product array except self
void productExceptSelf(int *nums, int n, int *answer) {
    // Arrays to store prefix and suffix products
    int *prefix = (int *)malloc(n * sizeof(int));
    int *suffix = (int *)malloc(n * sizeof(int));

    if (!prefix || !suffix) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Build prefix products
    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Build suffix products
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Build answer array
    for (int i = 0; i < n; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    free(prefix);
    free(suffix);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    int *answer = (int *)malloc(n * sizeof(int));

    if (!nums || !answer) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            free(answer);
            return 1;
        }
    }

    productExceptSelf(nums, n, answer);

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if (i < n - 1) printf(",");
    }
    printf("]\n");

    free(nums);
    free(answer);
    return 0;
}
