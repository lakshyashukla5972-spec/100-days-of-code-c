//Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

/*
Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30

*/
#include <stdio.h>
#include <string.h>

// Define the enum for menu choices
typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    INVALID
} MenuChoice;

int main() {
    char opStr[20];
    double num1, num2, result;
    MenuChoice choice = INVALID;

    // Read the operation and the two numbers
    if (scanf("%s %lf %lf", opStr, &num1, &num2) != 3) {
        printf("Invalid Input\n");
        return 1;
    }

    // Map the input string to the corresponding enum value
    if (strcmp(opStr, "ADD") == 0) {
        choice = ADD;
    } else if (strcmp(opStr, "SUBTRACT") == 0) {
        choice = SUBTRACT;
    } else if (strcmp(opStr, "MULTIPLY") == 0) {
        choice = MULTIPLY;
    }

    // Perform the operation using switch-case
    switch (choice) {
        case ADD:
            result = num1 + num2;
            printf("%.0f\n", result);
            break;
        case SUBTRACT:
            result = num1 - num2;
            printf("%.0f\n", result);
            break;
        case MULTIPLY:
            result = num1 * num2;
            printf("%.0f\n", result);
            break;
        default:
            printf("Invalid Operation\n");
            break;
    }

    return 0;
}
