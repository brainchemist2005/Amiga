#include<stdio.h>
int main (){
    int number;
    printf("enter a number : ");
    scanf(" %d",&number);
    switch (number){
        case 1 :
        printf("It's monday! ");
        break;
        case 2 :
        printf("It's tuesday! ");
        break;
        case 3 :
        printf("It's wensday! ");
        break;
        case 4 :
        printf("It's thursdsay! ");
        break;
        case 5 :
        printf("It's friday! ");
        break;
        case 6 :
        printf("It's saturday! ");
        break;
        case 7 :
        printf("It's sunday! ");
        break;
        default :
        printf("There is only 7 days a week not more ");

    return 0;
    }
    
    return 0;

}