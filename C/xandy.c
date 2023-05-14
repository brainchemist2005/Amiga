#include<stdio.h>

int large_num(int x, int y);
int main(){
    int x,y,result;
    printf("enter two integers: ");
    scanf("%d %d",&x ,&y);
    large_num(x,y);
    
    return 0;
}

int large_num(int x, int y){
    int result;
    result = x - y;
    
    return if(result > 0)
        printf("%d > %d",x,y);
    else
    printf("%d > %d",y,x);;
} 