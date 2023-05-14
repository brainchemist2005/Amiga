#include<stdio.h>
void prime_check(int x,int *ptr);
int main(){
    int x,flag=0;
    int *ptr=&flag;
    printf("enter the number: ");
    scanf("%d",&x);
    prime_check(x,ptr);
    if (*ptr == 1)
        printf("this is not prime ");
    else 
        printf("this is prime ");
    return 0;
}
void prime_check(int x,int *ptr){
    int y=2,result=0,flag=0;
    ptr=&flag; 
    while (x>y){
        result=x/y;
        
    if (x%y==0){

        *ptr=1;
        break;
    }
    y++;
    }
    
}