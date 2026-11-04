//Q133: Create an enum for months and print how many days each month has.

/*
Sample Test Cases:
Input 1:
FEB
Output 1:
28 or 29 days

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the enum for months
typedef enum {
    JAN, FEB, MAR, APR, MAY, JUN, 
    JUL, AUG, SEP, OCT, NOV, DEC, 
    INVALID
} Month;

// Function to convert string input to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Function to map string input to the Month enum
Month string_to_month(char *str) {
    to_uppercase(str);
    
    if (strcmp(str, "JAN") == 0 || strcmp(str, "JANUARY") == 0) return JAN;
    if (strcmp(str, "FEB") == 0 || strcmp(str, "FEBRUARY") == 0) return FEB;
    if (strcmp(str, "MAR") == 0 || strcmp(str, "MARCH") == 0) return MAR;
    if (strcmp(str, "APR") == 0 || strcmp(str, "APRIL") == 0) return APR;
    if (strcmp(str, "MAY") == 0) return MAY;
    if (strcmp(str, "JUN") == 0 || strcmp(str, "JUNE") == 0) return JUN;
    if (strcmp(str, "JUL") == 0 || strcmp(str, "JULY") == 0) return JUL;
    if (strcmp(str, "AUG") == 0 || strcmp(str, "AUGUST") == 0) return AUG;
    if (strcmp(str, "SEP") == 0 || strcmp(str, "SEPTEMBER") == 0) return SEP;
    if (strcmp(str, "OCT") == 0 || strcmp(str, "OCTOBER") == 0) return OCT;
    if (strcmp(str, "NOV") == 0 || strcmp(str, "NOVEMBER") == 0) return NOV;
    if (strcmp(str, "DEC") == 0 || strcmp(str, "DECEMBER") == 0) return DEC;
    
    return INVALID;
}

// Function to print the number of days using a switch statement
void print_days_in_month(Month month) {
    switch (month) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            printf("31 days\n");
            break;
            
        case APR:
        case JUN:
        case SEP:
        case NOV:
            printf("30 days\n");
            break;
            
        case FEB:
            printf("28 or 29 days\n");
            break;
            
        default:
            printf("Invalid Month\n");
            break;
    }
}

int main() {
    char input[20];
    
    if (scanf("%19s", input) == 1) {
        Month m = string_to_month(input);
        print_days_in_month(m);
    }
    
    return 0;
}
