#include<stdio.h>
int main(){
    int array[1000],n,min_idx,temp;
    printf("enter a size: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the element #%d ",i);
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n-1;i++){
        min_idx=i;
        for(int j=i+1;j<n;j++){
            if(array[min_idx]>array[j])
            min_idx=j;
        }
    temp=array[i];
    array[i]=array[min_idx];
    array[min_idx]=temp;
    }
for(int i=0;i<n;i++){
    printf("%d",array[i]);
}

    return 0;
}