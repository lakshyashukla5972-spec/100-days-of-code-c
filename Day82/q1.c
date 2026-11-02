//Q132: Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.

/*
Sample Test Cases:
Input 1:
GREEN
Output 1:
Go

*/
#include <stdio.h>

// Define an enum for traffic lights
enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main() {
    // Variable declaration and assignment
    enum TrafficLight currentLight = GREEN;

    // Print action based on the traffic light value
    switch (currentLight) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
        default:
            printf("Invalid Light\n");
            break;
    }

    return 0;
}
