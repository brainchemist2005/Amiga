#include<stdio.h>

int main(){
    
    int x,fact=0,counter;
    printf("enter a number: ");
    scanf("%d",&x);

    if ( x < 0)
    printf("error ");
    else {
        for (counter = 0; counter++; counter <= x) {
            fact*=counter ;
        }
    printf("%d",fact);
    }
    return 0;
}
