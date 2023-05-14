#include<stdio.h>
#include<String.h>
#include<Stdlib.h>

int main()
{
    char code[10],temp[2];
    int num;

    scanf("%s",code);
    
    strcpy(temp,code[3]);
    num = atoi(temp);

    printf("%d",num);
}