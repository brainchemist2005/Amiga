#include<stdio.h>
void swap(int *A, int *B){
int temp;
temp=*A;
*A=*B;
*B=temp;
}
int main(){
int a[]={4,1,5,8,2,9,3};
int n=7;
int temp;
for(int i=0;i<n-1;i++){
int min=i,max;
        max=min;
for(int j=min+1;j<n;j++){
if(a[max]<a[j]){
                max=j;
            }
        }
if(max!=min){
swap(&a[min],&a[max]);
            }
    }
for(int i=0;i<n;i++){
printf("%d\n",a[i]);
    }
return 0;
}