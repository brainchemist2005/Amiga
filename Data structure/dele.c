#include<stdio.h>
#include<string.h>
typedef struct {
    double height;
    char Haircolor[10];
}type;
typedef struct{
    char name[20];
    int age;
    int ID;
    type body;
}info;
int filling(int n, info p1[10]){
    int i=0;
    while(i<n){
        printf("\nEnter the name, ID and age: ");
        scanf("%s %d %d",&p1[i].name,&p1[i].ID,&p1[i].age);
        if(p1[i].age<18){
            printf("\nAge not allowed");
            return 0;
        }
        else if(p1[i].age>18){
            printf("\nHow tall are you? ");
            scanf("%lf",&p1[i].body.height);
            printf("\nWhat color your hair is ?");
            scanf("%s",&p1[i].body.Haircolor);
        }
        i++;
    }
}
int tell(int n,info p1[10]){
    for(int i=0;i<n;i++){
        printf("\nThe name is %s \nThe age is %d\nThe ID is %d\nThe height is %.2lf\nThe hair color is %s",p1[i].name,p1[i].age,p1[i].ID,p1[i].body.height,p1[i].body.Haircolor);
    }
    return 0;
}
int file(int n,info p1[10]){
    FILE *fptr=fopen("database.txt","w");
    for(int i=0;i<n;i++){
        fprintf(fptr,"\nThe name is %s \nThe age is %d\nThe ID is %d\nThe height is %.2lf\nThe hair color is %s",p1[i].name,p1[i].age,p1[i].ID,p1[i].body.height,p1[i].body.Haircolor);
    }
    fclose(fptr);
    return 0;
}
int main(){
    info p1[10];
    int n;
    printf("Hello I will be gathering information");
    printf("\n How many students are there ? ");
    scanf("%d",&n);
    filling(n,p1);
    tell(n,p1);
    file(n,p1);
    return 0;
}