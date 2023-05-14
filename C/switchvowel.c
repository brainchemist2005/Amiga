#include<stdio.h>

int main(){
    char c; 
    printf("enter a something ");
    scanf("%c",&c);
    switch(c)
    {
    case'a':      
    case'e':
    case'i':
    case'o':
    case'u':
    case'y':
    printf("it is a vowel");
    break;
    case'1':
    case'2':
    case'3':
    case'4':
    case'5':
    case'6':
    case'7':
    case'8':
    case'9':
    printf("this is a digit ");
    break;
    default:
    printf("it is a consonant ");
    }
    
return 0;
}