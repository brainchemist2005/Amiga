#include<stdio.h>
#include<string.h>
int count(int n){
    if(n==0)
    return 0;
    else 
    return (n%10+count(n/10));


}


int main(){
    int n,i;
    printf("enter a number: ");
    scanf("%d",&n);
    i=count(n);
    printf("%d",i);
    return 0;
}