#include<stdio.h>
int factorial(int a);
int main()
{
    int a;
    printf("please enter a number: ");
    scanf("%d",&a);
    printf("%d", factorial(a));
    scanf("%d",&a);
    return 0;
}
int factorial (int a)
{
    if(a==0)
    {
        return 1;
    }
    return a * factorial(a-1);
}