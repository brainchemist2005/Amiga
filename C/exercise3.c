#include<stdio.h>
int main(){
    int x,y,counter,result;
    printf("enter two values: ");
    scanf(" %d %d",&x,&y);
    counter = 0;
    result = 1;
    if (y==0)
        printf("result is 1 ");
        else {
    while (counter<y)
    {
        counter++;
        result*=x;
        
    }
    printf("result is %d ",result);
        }
    return 0;
}

