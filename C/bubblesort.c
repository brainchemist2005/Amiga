#include<stdio.h>
int main(){
    int n,temp;
    printf("enter a size: ");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        printf("enter element #%d ",i);
        scanf("%d",&array[i]);
    }
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(array[j]<array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
    printf("%d\t",array[i]);
}
return 0;
}