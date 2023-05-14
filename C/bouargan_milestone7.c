#include<stdio.h>


void calculations();
int main(){
printf("Hello this program helps you rent vehicles\n");

calculations();

return 0;
}

void calculations(){
    double days,number,amount=0,result=0;
    char vehicle,answer;
    printf("Do you want to rent a car?(type y for yes, n for no) ");
    scanf(" %c",&answer);
    
    
    while(answer == 'y'){
    printf("choose a type of vehicule (type c for car, t for truck, l for luxury car and v for van): ");
    scanf(" %c",&vehicle);
    printf("how many ? ");
    scanf(" %lf",&number);

    if (vehicle == 'c'){
    printf("how many days ? ");
    scanf(" %lf",&days);
        if (days > 3){
            result = (days*number*500)-(days*10*500*number)/100;
            printf("the result is %2.lf MAD ",result) ;
            
        }
        else if (days < 3){
            result =  number*days*500;
            printf("the result is %2.lf MAD ", result);
            
        }
    }
    else if (vehicle == 'l'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            result =  (days*number*1500)-(days*10*1500*number)/100;
            printf("the result is %2.lf MAD ",result);
            
        }
        else if (days < 3){
            result = (number*days*1500);
            printf("the result is %2.lf MAD ", result);
            
        }
    }
        else if (vehicle == 't'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            result = (days*number*1100)-(days*25*1100*number)/100;
            printf("the result is %2.lf MAD ", result);
            
        }
        else if (days < 3){
            result = (number*days*1100);
            printf("the result is %2.lf MAD", result);
            
        }
        }
        else if (vehicle == 'v'){
            printf("how many days ? ");
            scanf(" %lf",&days);
        if (days >= 3){
            result = (days*number*800)-(days*20*800*number)/100;
            printf("the result is %2.lf MAD ", result);}
        else if (days < 3){
            result = (number*days*800);
            printf("the result is %2.lf MAD ", result);}
        }
        printf("\nDo you want to rent again? ");
        scanf(" %c",&answer);
        amount+=result;
        printf("the total amount is %2.lf MAD\n ",amount);
    }
    }
