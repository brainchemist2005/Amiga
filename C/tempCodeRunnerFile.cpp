#include<iostream>
#include<string.h>
int main(){
    char answer[12];
    printf("Hello world ");
    printf("Wassup? ");
    scanf("%s",answer);
    printf("%s",answer);
    if(strcmp(answer,"cool")==0){
        printf("F u");
    }
    else
    printf("OK");
    return 0;
}