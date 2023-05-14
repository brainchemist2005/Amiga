#include<stdio.h>
int x;
int main(){
    char word[1000];
    char word1[1000];
    printf("enter a word: ");
    scanf("%s",word);
    printf("enter another word: ");
    scanf("%s",word1);
    int i=0,flag=0;
    while(word[i]!='\0'){
        if(word[i]!=word1[i]){
            flag=1;
        }
        i++;
    }
printf("%d",flag);
    return 0;
}