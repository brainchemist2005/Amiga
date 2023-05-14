#include<stdio.h>
int main(){
    int x,j,n;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        printf("enter element by element: ");
        scanf("%d",&array[i]);
    }
    printf("watch me swap this array like a pro\n");
    j=n-1;
    for(int i=0;i<n/2;i++){
            x=array[i];
            array[i]=array[j];
            array[j]=x;
            j=j-1;
        }    
    
    for(int i=0;i<5;i++){
        printf("%d",array[i]);
    }
    return 0;
}