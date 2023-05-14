#include<stdio.h>

void pattern(int x, char c);
int main(){
    int x,row=0,col,y=0;
    char c;
    printf("enter a number: ");
    scanf("%d",&x);
    printf("enter a character: ");
    scanf(" %c",&c);
    pattern(x,c);
    return 0;
}

void pattern(int x, char c){
    int row=0,col=0;
    for(int i=1;i<=x;i++){
        for(int j=1; j<=x;j++){
            if(i==j){
                printf("%c",c);
            }
            else{
                printf("%d",j);
            }
        }
    printf(" ");
    }
}
