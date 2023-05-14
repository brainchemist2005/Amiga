#include<stdio.h>
int main(){
    int size,row=0,col;
    printf("enter a number of size: ");
    scanf("%d",&size);

    while(row<size){
        row++;
        col=0;
        while(col<row){
            col++;
            printf("*");
        }
        printf("\n");
    }
        
    
    }