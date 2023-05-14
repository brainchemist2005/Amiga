#include<stdio.h>
int x,y,a;
int *ptr,*ptr1;
int main(){
ptr=&x;
ptr1=&y;
printf("enter two numbers: ");
scanf("%d %d",&x,&y);
a = *ptr;
*ptr = *ptr1;
*ptr1 = a;
printf("x=%d and y=%d",x,y);
return 0;
}
