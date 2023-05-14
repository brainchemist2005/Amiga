#include<stdio.h>
int main(){
    int flag = 0,x,rem,a;
    int seen[10]={0};
    printf("how many numbers of elements do you want?");
    scanf("%d",&a);
    int array[a];
    for(int i=0;i<a;i++){
        printf("enter element by element:");
        scanf("%d",&array[i]);
    }
    for(int i=0;i<a;i++){
        while(array[i]>0){
            if(seen[array[i]]==1){
                flag=1;
            break;
            }
            else {
            seen[array[i]]=1;
            array[i]=array[i]/10000;
            
        }
        
    }
    }
printf("%d",flag);
    return 0;
    }
    
