#include<stdio.h>

int main(){
    int x, y, result;
    char oper; 
    
    printf("enter a number x ");
    scanf("%d", &x);

    printf("enter a number y ");
    scanf("%d", &y);

    printf("choose an symbol n");
    scanf("%c",&oper);

    result = x + oper + y;

    printf("result is %d %c %d is %d ", x, oper, y, result);
    
    return 0;
}