#include<stdio.h>

void swap(int *ptr_N, int *ptr_M);
    
    int main(){
        int N=25, M=18;
        int *ptr_N = &N;
        int *ptr_M = &M;
        printf("N=%d and M=%d\n",N,M);
        swap(ptr_N,ptr_M);
        printf("N=%d and M=%d",N,M);
        return 0 ;
    }
    void swap(int *ptr_N, int *ptr_M){
        int Z;
        Z = *ptr_N;
        *ptr_N = *ptr_M;
        *ptr_M = Z;
        

    }