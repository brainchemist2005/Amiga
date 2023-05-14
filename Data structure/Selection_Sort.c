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

void selectionsort(int ID[5],double grades[5],int n){
    int j,i;
    int start_index,max_index;
    for(i=0;i<n-1;i++){
        start_index=i;
        max_index=start_index;
        for(j=start_index+1;j<n-1;j++){
        if(grades[j]>grades[max_index])
        max_index=j;
        }
        if(max_index!=start_index){
        swapdouble(&grades[start_index],&grades[max_index]);
        swapint(&ID[start_index],&ID[max_index]);
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
    selectionsort(ID,grades,n);
    display(ID,grades);
    return 0;
}