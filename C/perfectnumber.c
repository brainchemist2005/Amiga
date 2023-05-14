#include<stdio.h>

int main(){
    int x,y=0,sum=0,n=1;
    printf("enter a number ");
    scanf("%d",&x);

    while (n<x){
        if (x%n==0)
        sum+=n;
        n++;
}
        if(sum == x){
            printf("this is a perfect number ");
        }
        else {
            printf("this is not a perfect number ");
        }
    

    
    return 0;
}