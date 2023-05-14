#include<stdio.h>
int main(){
int a[]={6,7,2,5,1,4,8,9,3};
int n=9;
printf("This is the array before the sorting");
for(int i=0;i<n;i++){
    printf("\n%d",a[i]);
}
for(int i=0;i<n;i++){
    for(int j=0;j<n-1-i;j++){
        if(a[j]>a[j+1]){
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        }
    }
}
printf("\nThis is the array after the swap");
for(int i=0;i<n;i++){
    printf("\n%d",a[i]);
}
return 0;
}