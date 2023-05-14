#include<stdio.h>
int main(){
    double table[3][4],average=0,sum,Average[3],aaverage;
    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 4; j++)
        {
            printf("Enter a grade ");
            scanf("%lf",&table[i][j]);
    }
    }
    for(int i=0; i < 3; i++)
    {
        sum=0;
        for(int j=0; j < 4; j++)
        {
            sum+=table[i][j];
        }
        average = sum/4;
        Average[i]=average;
        printf("\nThe average of this section is %.2lf",average);
        }
        
    aaverage = su/ 3;
    return 0;
}