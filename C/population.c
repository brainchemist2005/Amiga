#include<stdio.h>
int main(){
    int x=9870,y=1,z=0;
    printf("Year = %d, The population is %d",y,x);
    while(x<=30000){
        y++;
        x+=x*10/100;
        
        printf("\nYear = %d, The population is %d\n",y,x);
    }
    return 0;
}