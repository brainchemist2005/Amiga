#include<stdio.h>
#include<string.h>
#include<ctype.h>

int i=0,a=0,d=0;
int main(){
    char word[100000];
    printf("enter something: ");
    scanf("%s",word);
    while(word[i]!='\0'){
        if(isalpha(word[i]))
        a++;
        if(isdigit(word[i])){
        d++;
        }
        i++;
    }
    printf("the number of characters are %d",a);
    printf("the number of digits are %d",d);
    return 0;
}