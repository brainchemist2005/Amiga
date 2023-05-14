#include<stdio.h>
int fun(int x);
int main(){
    int Array[5],Arrays[5],x;
    for(int i=0;i<5;i++){
    printf("enter a number: ");
    scanf("%d",&x);
    if(x%2==0){
        Array[i]=x;
    }
    else{
    Arrays[i]=x;
    }
}
for(int j=0;j<5;j++){
    printf("\nThe even numbers are %d\nThe odd numbers are %d",Array[j],Arrays[j]);
}
return 0;
}