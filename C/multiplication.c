#include<stdio.h>

int multiplication(int x);

int main(){
    int x;
    printf("enter a number: ");
    scanf("%d",&x);
    multiplication(x);
    return 0;
}

int multiplication(int x){
    int y = 1;
    while(y<=10){
        printf("%d*%d=%d\n",x,y,(x*y));
        y++;
    }
}