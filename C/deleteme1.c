#include<stdio.h>

void vowel_check(char c);
int main(){
    char c;
    printf("enter a letter: ");
    scanf("%c",&c);
    vowel_check(c);
    return 0;
}

void vowel_check(char c){
    switch (c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'y':
        case 'u':
        printf("it's a vowel");
        break;
        }
        printf("it's a consont");
    
    
}