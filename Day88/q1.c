//Q138: Print all enum names and integer values using a loop.

/*
Sample Test Cases:
Input 1:
No input
Output 1:
RED=0
YELLOW=1
GREEN=2

*/
#include <stdio.h>

// Define the enum with explicit values (optional, as defaults start at 0)
enum TrafficLight {
    RED = 0,
    YELLOW = 1,
    GREEN = 2
};

int main() {
    // Array of string representations matching the enum values
    const char *colorNames[] = {"RED", "YELLOW", "GREEN"};
    
    // Loop through the enum values using their underlying integer equivalents
    for (int i = RED; i <= GREEN; i++) {
        printf("%s=%d\n", colorNames[i], i);
    }

    return 0;
}
