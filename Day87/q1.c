//Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.

/*
Sample Test Cases:
Input 1:
GUEST
Output 1:
Welcome Guest!

*/
#include <stdio.h>
#include <string.h>

// 1. Define the enum for user roles
typedef enum {
    ADMIN,
    USER,
    GUEST,
    UNKNOWN
} UserRole;

int main() {
    char input[50];
    UserRole role = UNKNOWN;

    // 2. Read the input role from the user
    // (Using scanf to read the string)
    if (scanf("%49s", input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // 3. Map the input string to the corresponding enum value
    if (strcmp(input, "ADMIN") == 0) {
        role = ADMIN;
    } else if (strcmp(input, "USER") == 0) {
        role = USER;
    } else if (strcmp(input, "GUEST") == 0) {
        role = GUEST;
    }

    // 4. Display messages based on the role using a switch-case statement
    switch (role) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
        default:
            printf("Welcome Unknown Role!\n");
            break;
    }

    return 0;
}