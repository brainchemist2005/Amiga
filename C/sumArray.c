#include<stdio.h>
int fun(int *array);
int main(){
    int array[5];
    int sum=0;
    sum = fun(&array[0]);
    printf("%d",sum);
    return 0;
}

int fun(int *array){
    int sum=0;
    for(int i=0;i<5;i++){
        printf("enter a number: ");
        scanf("%d",&array[i]);
        sum+=array[i];
    }
    return sum;
}