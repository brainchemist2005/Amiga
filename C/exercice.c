#include<stdio.h>
int main(){
    int x, result, vehicule; 
    
    printf("what type of vehicule do need ? ");
    scanf("%d", &vehicule);
    printf("how many do you need ?");
    scanf("%d",&x);

    if (vehicule == 'c'){
        result = x*500;
        printf("the amount you need to pay is %d", result);}
        else if (vehicule == 't'){
            result = x*1100;
            printf("the amount you need to pay is %d",result);}
            else {
                printf("error ");
            }
return 0;
}