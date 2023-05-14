#include<stdio.h>

void odd_even(int x){
    if(x%2==0)
        printf("this number is even");
    else 
        printf("This number is odd");
}

void absolute(int x){
    if(x<0)
        printf("the result is %d",(-x));
    else
        printf("the result is %d",x);
}

int factorial(int x){
    int y;
    int f=1;
    for(y=2;y<=x;y++){
        f*=y;
    }
    return f;
}

int prime(int x){
    int y,flag = 0;
    for(y=2;y<x;y++){
        if (x%y==0)
        flag = 1;
        break;
    }
    return flag;
}