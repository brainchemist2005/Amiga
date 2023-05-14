#include<stdio.h>
int main(){
    int n,b=0;
    printf("How many elements do you want in your array ?");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        printf("enter the element #%d ",i);
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]==array[j])
            b++;
        }
    }
    printf("there are %d duplications",b);
    return 0;

}