#include<stdio.h>
#include "headerparity.c"

int main(){
    int x, p,d;
    printf("enter a number: ");
    scanf("%d",&x);

    odd_even(x);
    absolute(x);
    p = prime(x); 
    if(p == 0)
    printf("the number is prime");
    else 
    printf("the number is composite");
    d = factorial(x);
        printf("the result of the factorial is %d\n",d);
    
    return 0;

}