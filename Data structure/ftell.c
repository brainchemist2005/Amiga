#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
//ftell gives you the size of a file
int main(){
    int x;
    FILE*file=fopen("test.txt","w");
    fprintf(file,"Hello World");
    x=ftell(file);
    fclose(file);
    printf("%d",x);
    return 0;
}