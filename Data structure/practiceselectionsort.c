#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubble(int Numbers[10],int n){
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            if(Numbers[j]>Numbers[j-1])
            swap(&Numbers[j],&Numbers[j-1]);
        }
    }
}
int main(){
    int Numbers[]={54,65,255,76,123,541,876,183,6335,1242},n=10;
    printf("Watch me sort this array like a pro\n");
    bubble(Numbers,n);
    for(int i=0;i<n;i++){
        printf("%d\n",Numbers[i]);
    }
    return 0;
}