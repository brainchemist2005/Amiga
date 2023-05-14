#include<stdio.h>
int test ();
int main(){
    int a,b,result;
    printf("this is to test functions\n");
    printf("enter two numbers: ");
    scanf("%d %d",&a,&b);
    result = test(a,b);
    printf("%d",result);
    return 0;
}
int test(*ptr1 , *ptr2){
    
    return ;
}