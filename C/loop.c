#include<stdio.h>
int main (){
    int x,n=0,sum=0;
    printf("enter a number ");
    scanf("%d",&x);
    for(n=1;n<=x;n++){
        sum+=n;
        printf("%d ",n);

    }
    
printf("%d ",sum);
    return 0;
}
