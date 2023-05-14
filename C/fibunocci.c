#include<stdio.h>
int main(){
    int x1=0, y, x2=1, next_term=x1+x2, counter;
    printf("enter a number of terms: ");
    scanf("%d",&y);
    printf("%d %d ",x1,x2);
    for(counter = 3;counter <= y; counter++ ){
        printf("%d ",next_term);
        x1 = x2;
        x2 = next_term;
        next_term = x1 + x2;
    }
    return 0;
}