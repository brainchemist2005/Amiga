#include<stdio.h>

int main(){
    int x;
    printf("enter a year ");
    scanf("%d",&x);

    if (x % 400 == 0){
    printf("this is a leap year ");
    }
    else if(x%4==0 && x%100!=0){
    printf("this is a leap year");
    }
    else{
        printf("this is not a leap year ");
    }
    

    return 0;

}
