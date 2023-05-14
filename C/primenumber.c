#include<stdio.h>
int main(){
    int x,y=2,result=0,flag=0;
    printf("enter a number ");
    scanf("%d",&x);
    while (x>y){
        result=x/y;
        
    
    if (x%y==0){

        flag=1;
        break;
    }
    y++;
    }
    if (flag == 1)
    printf("this is not prime ");
    else 
    printf("this is prime ");
    return 0;    
}