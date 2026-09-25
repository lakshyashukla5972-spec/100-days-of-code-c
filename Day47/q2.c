//Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    char longest[50] = "";
    char word[50];
    int maxLen = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize the sentence into words
    char *token = strtok(sentence, " \n");
    while (token != NULL) {
        int len = strlen(token);
        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, token);
        }
        token = strtok(NULL, " \n");
    }

    printf("Longest word: %s\n", longest);
    return 0;
}
