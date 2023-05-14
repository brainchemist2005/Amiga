#include<stdio.h>
int main(){
    char array[10];
    printf("enter a word: ");
    scanf("%s",array);
    int i=0;
    while(array[i]!='\0'){
        i++;
    }
    printf("%d",i);
    return 0;

}