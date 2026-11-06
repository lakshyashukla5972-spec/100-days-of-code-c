//Q135: Assign explicit values starting from 10 and print them.

/*
Sample Test Cases:
Input 1:
No input
Output 1:
A=10
B=11
C=12

*/
#include <stdio.h>

int main() {
    enum Values { A = 10, B, C };

    printf("A=%d B=%d C=%d\n", A, B, C);

    return 0;
}
