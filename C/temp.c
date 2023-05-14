#include<stdio.h>
int main(){
    double c,f,k ;
    char Temp;

    printf("choose a unit ");
    scanf("%c", &Temp);
    if (Temp == 'c'){
        printf("enter the temperature in c ");
        scanf("%lf", &c);
        k= c + 273.15 ;
        f= (c * 9/5) + 32 ;
        printf("%2.lf in celsius is %2.lf in k and %2.lf in f ", c,k,f);}
        else if (Temp == 'k'){
            printf("enter the temperature in k");
    scanf("%lf", &k);
        c= k - 273.15 ;
        f= (k - 273.15) * 9/5 + 32 ;
        printf("%2.lf in kelvin is %2.lf in c and %2.lf in f ",k,c,f);}
        else if (Temp == 'f'){
            printf("enter the temperature in f ");
    scanf("%lf", &f);
        c= (f - 32) * 5/9 ;
        k= (f - 32) * 5/9 + 273.15 ;
        printf("%2.lf in farheneit is %2.lf in c and %2.lf in k ", f,c,k);}
    else {
        printf("error "); } 
        return 0;                         
    }
     
