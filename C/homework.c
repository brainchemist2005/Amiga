#include <stdio.h>
#include "header.c"

int main(){
    int choice;
    char answer = 'y';
    printf("This program computes the volume of some shapes you can choose between the hemisphere, the pyramid, the cone and the sphere\n");
while(answer == 'y'){
    choice = menu();
    if(choice == 1){
        V_hemisphere();
    }else if (choice == 2){
        V_pyramid();
    }else if(choice == 3){
        V_cone();
    }else if(choice == 4){
        V_sphere();
    }else{
        printf("wrong input\n");
    }
printf("do you want to compute again ? (type y for yes or n for no)");
scanf(" %c",&answer);
    }
    return 0;
}