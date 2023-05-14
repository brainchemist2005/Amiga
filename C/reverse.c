#include<stdio.h>
int main(){
    int x,y=0,sum=0;
    printf("enter a number ");
    scanf("%d",&x);
    while(x>0)
    {
        y=x%10;
        sum=sum*10 + y;
        x=x/10;
        printf("%d",sum);
    }
        
    
return 0;
}