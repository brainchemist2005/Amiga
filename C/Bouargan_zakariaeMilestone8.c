#include<stdio.h>
void day(double *days);
void vehicl(char *vehicle);
void num(double *number);

int main(){
    char answer = 'y', *ptv,vehicle;
    double days,number,result, *ptd, *ptn, *ptr,amount;
    ptd = &days;
    ptn = &number;
    ptr = &result;
    printf("Hello this program is helping rent vehicles ");
    while(answer == 'y'){
        ptv = &vehicle;
        vehicl(ptv);
        

        num(ptn);
        day(ptd);
        if (vehicle == 'c'&&days >= 3){
            
                result = (days*number*500)-(days*10*500*number)/100;
                printf("the result is %2.lf MAD ",result) ;
        }
        
        else if (vehicle == 'c'){
            result =  number*days*500;
            printf("the result is %2.lf MAD ", result);
            
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
        amount+=result;
        printf("the total amount is %2.lf MAD",amount);
    }
        return 0;
}



void day(double *days){
    printf("enter how many days: ");
    scanf("%lf",days); 
}
void vehicl(char *vehicle){
    printf("choose a type of vehicule (type c for car, t for truck, l for luxury car and v for van): ");
    scanf(" %c",vehicle);
}

void num(double *number){
    printf("how many ? ");
    scanf(" %lf",number);
}