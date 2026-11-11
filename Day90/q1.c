//Q140: Define a struct with enum Gender and print person's gender.

/*
Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male

*/
#include <stdio.h>
#include <string.h>

// Define the Gender enum
typedef enum {
    MALE,
    FEMALE,
    OTHER
} Gender;

// Define the Person struct
typedef struct {
    Gender gender;
} Person;

int main() {
    char input[20];
    Person p1;

    // Read the input gender string
    if (scanf("%19s", input) == 1) {
        // Map the input string to the corresponding enum value
        if (strcmp(input, "Gender=MALE") == 0 || strcmp(input, "MALE") == 0) {
            p1.gender = MALE;
        } else if (strcmp(input, "Gender=FEMALE") == 0 || strcmp(input, "FEMALE") == 0) {
            p1.gender = FEMALE;
        } else {
            p1.gender = OTHER;
        }

        // Print the gender based on the struct's enum value
        switch (p1.gender) {
            case MALE:
                printf("Male\n");
                break;
            case FEMALE:
                printf("Female\n");
                break;
            case OTHER:
                printf("Other\n");
                break;
        }
    }

    return 0;
}
