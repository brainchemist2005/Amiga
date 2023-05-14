#include<stdio.h>
#include<ctype.h>
char word[10000];
int main(){
    int x;
    printf("enter a word: ");
    scanf("%s",word);
    int i=1;
    printf("%c",toupper(word[0]));
    while(word[i]!='\0'){
        printf("%c",tolower(word[i]));
        i++;
    }

    return 0;
}