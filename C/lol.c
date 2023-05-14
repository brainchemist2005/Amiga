#include<stdio.h>

int main(){
    int x,y,calc;
    printf("enter a your withdrawl and deposit ");
    scanf("%d %d",&x,&y);
    calc = x - y;
    if (calc < 0) 
    printf("loss ");
    else 
    printf("profit ");


    return 0;
}