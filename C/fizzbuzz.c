#include<stdio.h>
int main(){
    int x=0;

    while (x<=100){
        x++;
        if(x%3==0)
            printf("Fizz\n");
        else if (x%5==0)
            printf("Buzz\n");
        else if(x%3==0 && x%5==0);
            printf("FizzBuzz\n"); 
    }
    return 0;
}