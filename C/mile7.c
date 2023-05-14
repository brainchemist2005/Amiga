#include<stdio.h>
double day(double days);
char vehicl(char vehicle);
double num(double number);

int main(){
    char answer = 'y';
    double days,vehicle,number,result;
    printf("Hello this program is helping rent vehicles ");
    while(answer == 'y'){
        vehicle=vehicl(vehicle);
        number=num(number);
        days=day(days);
        if (vehicle == 'c'){
            if (days >= 3){
                result = (days*number*500)-(days*10*500*number)/100;
                printf("the result is %2.lf MAD ",result) ;
            
        }
        else if (days < 3){
            result =  number*days*500;
            printf("the result is %2.lf MAD ", result);
            
        }
    }
    else if (vehicle == 'l'){
            
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
            
        if (days >= 3){
            result = (days*number*800)-(days*20*800*number)/100;
            printf("the result is %2.lf MAD ", result);}
        else if (days < 3){
            result = (number*days*800);
            printf("the result is %2.lf MAD ", result);}
        }    
        printf("\nDo you want to rent a car?(type y for yes, n for no) ");
        scanf(" %c",&answer);
    }
        return 0;
}



double day(double days){
    printf("enter how many days: ");
    scanf("%lf",&days); 
    return days;
}
char vehicl(char vehicle){
    printf("choose a type of vehicule (type c for car, t for truck, l for luxury car and v for van): ");
    scanf(" %c",&vehicle);
    return vehicle;
}

double num(double number){
    printf("how many ? ");
    scanf(" %lf",&number);
    return number;
}