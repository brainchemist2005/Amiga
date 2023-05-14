#include<stdio.h>
 int main(){
     int x,y,result;
     printf("how many cars do you need? ");
     scanf("%d",&x);

     printf("how many trucks do you need? ");
     scanf("%d",&y);

     result = 500*x+y*1100 ;
    printf("the resut is %d\n", result);
    return 0;

 }