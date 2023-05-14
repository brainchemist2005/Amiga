#include<stdio.h>

int decimal_binary(int x);

int main(){
    int x;
    printf("enter a number: ");
    scanf("%d",&x);
    decimal_binary(x);
    return 0;
}
int decimal_binary(int x){
    while(x>0){
        printf("%d",x%2);
        x = x/2;
    }
    }
