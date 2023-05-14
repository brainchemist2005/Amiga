#include<stdio.h>
int main(){
    double x,sum=0,result=0;
    int counter=0;
    printf("enter a number ");
        scanf("%lf",&x);
    
    while(x>0){
        sum+=x;
        counter++;
        printf("enter a number ");
        scanf("%lf",&x);
    }
    result=sum/counter;
    printf("the result is %2.lf\n",result);
    printf("the counter is %d ",counter);
    return 0;
}