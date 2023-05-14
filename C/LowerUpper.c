#include <stdio.h>
#include <ctype.h>

int main(){
    char word[10000];
    int i=0,a=0,A=0;
    printf("enter somthing ");
    scanf("%s",word);
    while(word[i]!='\0'){
        if(isupper(word[i]))
            A++;
        if(islower(word[i])){
            a++;
        }
        
        i++;
        
    }
    i = 0;
    while(word[i]!='\0'){
    if(a>A){
        printf("%c",tolower(word[i]));
        }
        else if(a<A){
            printf("%c",toupper(word[i]));
        }
        else{
            printf("%c",tolower(word[i]));
        }
        i++;
    }
    return 0;
}