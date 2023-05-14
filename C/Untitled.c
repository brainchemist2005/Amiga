#include<stdio.h>

int main(){
    int x,y,flag;
    printf("enter a number: ");
    scanf("%d",&x);

    for(y=2;x>y;y++){
        if (x%y==0){
        flag = 1;
        break;}
        else {
        flag = 0;
        break;}
    }
    if (flag == 1){
        printf("This is not a prime number ");}
        else if (flag == 0);
            printf("this is a prime number ");

    return 0; 
}