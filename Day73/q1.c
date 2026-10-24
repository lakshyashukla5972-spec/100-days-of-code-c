//Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

/*
Sample Test Cases:
Input 1:
File: sample.txt (Content: Hello world\nThis is C programming)
Output 1:
Characters: 31
Words: 5
Lines: 2

*/
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("info.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    int characters = 0, words = 0, lines = 0;
    int c;
    int inWord = 0;

    while ((c = fgetc(fp)) != EOF) {
        characters++;

        if (c == '\n')
            lines++;

        if (isspace(c)) {
            inWord = 0;   // we are outside a word
        } else {
            if (!inWord) {
                words++;  // starting a new word
                inWord = 1;
            }
        }
    }

    fclose(fp);

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
