//Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    fgets(name, sizeof(name), stdin);

    // Remove trailing newline if present
    name[strcspn(name, "\n")] = '\0';

    int len = strlen(name);
    int lastSpace = -1;

    // Find position of last space (surname start)
    for (int i = len - 1; i >= 0; i--) {
        if (name[i] == ' ') {
            lastSpace = i;
            break;
        }
    }

    // Print initials for all words except surname
    printf("%c.", toupper(name[0]));
    for (int i = 1; i < lastSpace; i++) {
        if (name[i] == ' ' && i + 1 < lastSpace) {
            printf("%c.", toupper(name[i + 1]));
        }
    }

    // Print surname in full
    printf(" %s\n", name + lastSpace + 1);

    return 0;
}
