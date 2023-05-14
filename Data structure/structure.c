#include<stdio.h>
struct info{
    char name[30];
    int age;
    double height;
} EX;
void func(struct info *EX){
    printf("\nEnter your name: ");
        scanf("%[^\n]s",EX->name);
        printf("\nHow old are you: ");
        scanf("%d",EX->age);
        printf("\nHow tall are you: ");
        scanf("%lf",EX->height);
        printf("\t%s\t%d\t%.2lf",EX->name,EX->age,EX->height);
}
    int main(){
        func(&EX);
        printf("\n%s %d %.2lf",EX.name,EX.age,EX.height);
        return 0;
    }