#include<stdio.h>
#include<string.h>
int main(){
    char fullname[100][30];
    char CIN[100][8];//the number of CIN code is 7 and not more thats why i put 8 in the size
    int a,result=0;
    printf("how many vahicles do you need? ");
    scanf("%d",&a);
    int type[a],days[a],price[a],num[a],number[a];
    for(int i=0;i<a;i++){
    printf("What is your full name: ");
    getchar();
    gets(fullname[i]);
    printf("What is your CIN code ");
    scanf("%s",&CIN[i]);
        printf("what type of vehicle do you want? (1 for standart car,2 for truck, 3 for van) :");
        scanf("%d",&type[i]);
        if(type[i]==1){
            printf("how many do want? ");
            scanf("%d",&num[i]);
            printf("how many days? ");
            scanf("%d",&days[i]);
            if (days[i] > 3){
                price[i] = (days[i]*num[i]*500)-(days[i]*10*500*num[i])/100;
                result += price[i];
            }
            else if (days[i] < 3){
                price[i] =  num[i]*days[i]*500;
                result += price[i];            
                }
            
        }
        if(type[i]==2){
            printf("how many do want? ");
            scanf("%d",&num[i]);
            printf("how many days? ");
            scanf("%d",&days[i]);
            if (days[i] >= 3){
                price[i]= (days[i]*num[i]*1100)-(days[i]*25*1100*num[i])/100;
                result += price[i]; 
            }
            else if (days[i] < 3){
                price[i] = (num[i]*days[i]*1100);
                result += price[i]; 
            }
        }
        if(type[i] == 3){
            printf("how many do want? ");
            scanf("%d",&num[i]);
            printf("how many days? ");
            scanf("%d",&days[i]);
            if(days[i] >= 3){
            price[i] = (days[i]*num[i]*800)-(days[i]*20*800*num[i])/100;
                result += price[i]; }
            else if (days[i] < 3){
                price[i] = (num[i]*days[i]*800);
                result += price[i]; 
            }
            
        }
    }
    
    for(int i=0;i<a;i++){
        printf("%s\t",fullname[i]);
        printf("%s\t",CIN[i]);
        printf("the vehicle type %d\t",type[i]);
        printf("the amount:%d\t",num[i]);
        printf("the number of days:%d\t",days[i]);
        printf("the price is:%d MAD\t",price[i]);
        printf("\n");
    }
    printf("the total result is %d MAD",result);
    return 0;
}