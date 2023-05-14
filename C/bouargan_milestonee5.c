#include<stdio.h>

int main(){
    double days,number,result1=0, result2=0, result3=0, result4=0,amount=0 ;
    char car='c',luxury_car='l', truck='t', van='v', answer;
    printf("Do you want to rent a vehicle? (type y or n)");
    scanf("%c",&answer);
    
    while (answer = y){
    printf("choose a type of vehicule (type c for car, t for truck, l for luxury car and v for van): ");
    scanf(" %c ",&car);
    
    printf("how many ? ");
    scanf(" %lf",&number);

    if (car == 'c'){
    printf("how many days ? ");
    scanf(" %lf",&days);
        if (days > 3){
            result1 = (days*number*500)-((days*10*500*number)/100));
            printf("the result is %2.lf MAD ", result1) ;
            }
        else if (days < 3){
            result1 = number*days*500;
            printf("the result is %2.lf MAD ", result1);}
    }
    else if (luxury_car == 'l'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            result1 = (days*number*1500)-((days*10*1500*number)/100));
            printf("the result is %2.lf MAD ", result2) ;
            }
        else if (days < 3){
            result1 =  (number*days*1500);
            printf("the result is %2.lf MAD ", result2);}
    }
        else if ( truck == 't'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            result1 = ((days*number*1100)-((days*25*1100*number)/100);
            printf("the result is %2.lf MAD ", result3);}
        else if (days < 3){
            result1 = (number*days*1100);
            printf("the result is %2.lf MAD ", result3);}
        }
        else if (van == 'v'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            result1 = ((days*number*800)-((days*20*800*number)/100);
            printf("the result is %2.lf MAD ", result4);}
        else if (days < 3){
            printf("the result is %2.lf MAD ", (number*days*800));}
        }
    }

    return 0;
    }