#include<stdio.h>
void swapint(int *A, int *B){
int temp;
temp=*A;
*A=*B;
*B=temp;
}
void swapdouble(double *A, double *B){
double temp;
temp=*A;
*A=*B;
*B=temp;
}
void bubblesort(int ID[5],double grades[5],int n){
    int j,i;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(grades[j]>grades[j-1]){
                swapdouble(&grades[j],&grades[j-1]);
                swapint(&ID[j],&ID[j-1]);
            }
        }
    }
}
void display(int ID[5], double grades[5]){
    printf("\nThis is the content of the array");
    for(int i=0;i<5;i++){
    printf("\n%d  %.2lf",ID[i],grades[i]);
    }
    
}
int main(){
    double grades[5]={54,23,75,12,98};
    int ID[5]={12345,54321,67896,23587,35823},n=5;
    display(ID,grades);
    bubblesort(ID,grades,n);
    display(ID,grades);
    return 0;
}