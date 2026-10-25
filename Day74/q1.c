//Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

/*
Sample Test Cases:
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char sourceFile[100], destFile[100];
    FILE *fpSource, *fpDest;
    int ch;

    // Get filenames from the user
    printf("Enter the source file name: ");
    scanf("%99s", sourceFile);

    printf("Enter the destination file name: ");
    scanf("%99s", destFile);

    // Open source file in read mode
    fpSource = fopen(sourceFile, "r");
    if (fpSource == NULL) {
        printf("Error: Cannot open source file %s\n", sourceFile);
        exit(1);
    }

    // Open destination file in write mode
    fpDest = fopen(destFile, "w");
    if (fpDest == NULL) {
        printf("Error: Cannot open or create destination file %s\n", destFile);
        fclose(fpSource);
        exit(1);
    }

    // Copy contents character by character using fgetc() and fputc()
    while ((ch = fgetc(fpSource)) != EOF) {
        fputc(ch, fpDest);
    }

    printf("File copied successfully to %s\n", destFile);

    // Close both files
    fclose(fpSource);
    fclose(fpDest);

    return 0;
}
