//Q22: Write a program to find profit or loss percentage given cost price and selling price.

/*
Sample Test Cases:
Input 1:
1000 1200
Output 1:
Profit 20%

Input 2:
1000 800
Output 2:
Loss 20%

Input 3:
1000 1000
Output 3:
No Profit No Loss

*/
#include <stdio.h>
int main() {
    float costPrice, sellingPrice, profitLossPercentage;

    printf("Enter cost price: ");
    scanf("%f", &costPrice);
    printf("Enter selling price: ");
    scanf("%f", &sellingPrice);

    if (sellingPrice > costPrice) {
        profitLossPercentage = ((sellingPrice - costPrice) / costPrice) * 100;
        printf("Profit %.2f%%\n", profitLossPercentage);
    } else if (sellingPrice < costPrice) {
        profitLossPercentage = ((costPrice - sellingPrice) / costPrice) * 100;
        printf("Loss %.2f%%\n", profitLossPercentage);
    } else {
        printf("No Profit No Loss\n");
    }

    return 0;
}