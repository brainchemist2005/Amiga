#include<stdio.h>

int main(){
    double n=1,terms,sum=0;
    printf("enter a number of terms ");
    scanf("%lf",&terms);
    while(n<terms){
    printf("%lf_+1/",n);
    sum+=1/n ;
    n++;
    printf("%2.lf",sum);
    }

    return 0;
}
