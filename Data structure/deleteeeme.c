#include<stdio.h>
#include<string.h>
typedef struct family{
    int number;
    char name[10];
}family;
typedef struct members{
    struct family d;
    int numberofpeople;
}members;
family p1;
int main(){
    printf("Start\n");
    p1.number=2;
    strcpy(p1.name,"zak");
    printf("%d %s",p1.number,p1.name);
    return 0;
}