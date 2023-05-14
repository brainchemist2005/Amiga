#include<stdio.h>
void compare_numbers();

int main(){
    compare_numbers();

    return 0;
}

void compare_numbers(){
    int x,y;
    printf("enter two numbers ");
    scanf("%d %d",&x,&y);
    if(y==0)
        printf("%d > %d ",x,y);
        else 
            if (x/y>1)
                printf("%d > %d ",x,y);
                else 
                    printf("%d < %d ",x,y);
}