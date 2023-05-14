#include <stdio.h>

int main(){
    int cars, trucks, totalamount;
    printf("please enter the number of cars:");
    scanf("%d", &cars);
    printf("please enter the number of trucks:");
    scanf("%d", &trucks);
    totalamount = cars * 500 + trucks * 1100;
    printf("the total amount is: %d\n", totalamount);
    return 0;
}