#include<stdio.h>

int pwr(int x);

int main(){
    int x;
    printf("enter a number: ");
    scanf("%d",&x);
    pwr(x);
    return 0;
}
int pwr(int x){
    printf("the result is %d",x*x);
    return 0;
}