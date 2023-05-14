#include<stdio.h>
int main(){
    int Garray[5],Irray[5],sum=0,max,min,ID;
    double Average=0;
    for(int i=0;i<5;i++){
        printf("enter the ID: ");
        scanf("%d",&Irray[i]);
        printf("enter a GPA: ");
        scanf("%d",&Garray[i]);
        sum+=Garray[i];
    }
    Average = sum/5;
    max = Garray[0];
    min = Garray[0];
    for(int i=1; i<5;i++){
        if(Garray[0]>Garray[i])
        max = Garray[i];
        ID = Irray[i];
    }
    for(int i=1;i<5;i++){
        if(Garray[0]<Garray[i])
    min = Garray[i];
    ID = Irray[i];
    }
    printf("The class average is %2.lf\n",Average);
    printf("The highest GPA is %d\n ",max);
    return 0;
}