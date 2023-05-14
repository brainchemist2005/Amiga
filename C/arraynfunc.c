#include<stdio.h>
int fun(int array[],int x){
    for(int i=0;i<5;i++){
        printf("enter a value: ");
        scanf("%d",array[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d",array[i]);
    }
    return 0;
}
int main(){
    int array[5];
    fun(array,5);
    return 0;
}
