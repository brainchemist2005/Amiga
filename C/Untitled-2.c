#include<stdio.h>

void grade_cal(double x, double y);

int main(){
    double x,y;
    int c = 1;
    while (c = 1){
        printf("this program computes the overall grade \n");
        printf("enter the class grade and the lab grade\n");
        scanf("%lf %lf",&x,&y);
        grade_cal(x,y);
        printf("\ndo you want to redo ");
        scanf("%d",c);
    }
    return 0;
}
void grade_cal(double x, double y){
    double result;
    result=70*x/100 + 30*y/100;
    printf("the overall grade is %2.lf",result);
}
