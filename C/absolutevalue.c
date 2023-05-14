#include<stdio.h>

void factorial();

int main(){
    int x;
    printf("enter a number: ");
    scanf("%d",&x);
    factorial(x);
    return 0;
}
void factorial(){
int y=1,x;

    while(x>y){
        x=y*x;
        y++;
        }
    printf("the factorial is %d",y);
}
