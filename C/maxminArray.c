#include<stdio.h>
int main(){
    int array[1000];
    int n,min,max;
    printf("enter a number of elements:");
    scanf("%d",&n);
    printf("enter element by element:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    max=min=array[0];
    for(int i=0;i<n;i++){
        if(max<array[i])
        max=array[i];
        if(min>array[i])
        min=array[i];
    }
    printf("the max is %d\t",max);
    printf("the min is %d",min);
    return 0;
}