//Q134: Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.

/*
Sample Test Cases:
Input 1:
FAILURE
Output 1:
Operation failed

*/
#include <stdio.h>
#include <string.h>

// Define the enum for operation status
typedef enum {
    SUCCESS,
    FAILURE,
    TIMEOUT
} Status;

// Function to print the message based on the enum value
void printStatusMessage(Status status) {
    switch (status) {
        case SUCCESS:
            printf("Operation successful\n");
            break;
        case FAILURE:
            printf("Operation failed\n");
            break;
        case TIMEOUT:
            printf("Operation timed out\n");
            break;
        default:
            printf("Unknown status\n");
    }
}

int main() {
    // Simulating the sample test case input (FAILURE)
    Status currentStatus = FAILURE;
    
    printStatusMessage(currentStatus);
    
    return 0;
}
