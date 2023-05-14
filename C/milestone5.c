#include<stdio.h>
#define car = c
#define truck = t
#define luxury car = l
#define van = v
int main(){
    double days,number;
    char vehicle;
    printf("choose a type of vehicule (type c for car, t for truck, l for luxury car and v for van): ");
    scanf(" %c",&vehicle);
    
    printf("how many ? ");
    scanf(" %lf",&number);

    if (vehicle == 'c'){
    printf("how many days ? ");
    scanf(" %lf",&days);
        if (days > 3){
            printf("the result is %2.lf", (days*number*500)-(days*10*500*number)/100);}
        else if (days < 3){
            printf("the result is %2.lf", number*days*500);}
    }
    else if (vehicle == 'l'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            printf("the result is %2.lf", (days*number*1500)-(days*10*1500*number)/100);}
        else if (days < 3){
            printf("the result is %2.lf", (number*days*1500));}
    }
        else if (vehicle == 't'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            printf("the result is %2.lf", ((days*number*1100)-(days*25*1100*number)/100));}
        else if (days < 3){
            printf("the result is %2.lf", (number*days*1100));}
        }
        else if (vehicle == 'v'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            printf("the result is %2.lf", ((days*number*800)-(days*20*800*number)/100));}
        else if (days < 3){
            printf("the result is %2.lf", (number*days*800));}
        }
    return 0;
    }