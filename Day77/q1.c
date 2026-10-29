//Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

/*
Sample Test Cases:
Input 1:
Input File (input.txt): Hello World\nC programming
Output 1:
Output File (output.txt): HELLO WORLD\nC PROGRAMMING

*/
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;

    // Open input.txt in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    // Open output.txt in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt\n");
        fclose(inputFile);
        return 1;
    }

    // Read character by character
    while ((ch = fgetc(inputFile)) != EOF) {
        // Convert lowercase to uppercase
        ch = toupper(ch);
        // Write to output file
        fputc(ch, outputFile);
    }

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}