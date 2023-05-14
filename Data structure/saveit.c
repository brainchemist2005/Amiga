#include<stdio.h>
typedef struct{
    int year;
    int month;
    int day;
}birthday_info;
typedef struct{
    birthday_info b_date;
    char name[20];
}user_info;

int main(void){
    user_info p1;
    printf("\n---------------------------------------------------------------------------");
    printf("\n\t\tEnter the name of the user: ");
    gets(p1.name);
    printf("\n\t\tEnter a day of birth");
    scanf("%d",&p1.b_date.day);
    printf("\n\t\tEnter a month of birth");
    scanf("%d",&p1.b_date.month);
    printf("\n\t\tEnter a year of birth");
    scanf("%d",&p1.b_date.year);
    printf("\n--------------------------------------------------------------------------");
    printf("\n\t\t%s\t\t%d/%d/%d",p1.name,p1.b_date.day,p1.b_date.month,p1.b_date.year);
    return 0;
}