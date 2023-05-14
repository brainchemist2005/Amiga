#include<stdio.h>
#define PI 3.14
int shape ();
void V_Cuboid();
void V_Cylinder();

int menu(){
    int choice;

    choice = menu();
    if (choice == 1){
        V_Cuboid();
    }else if (choice == 2){
        V_Cylinder();
    }else {
        printf("wrong input");
    }
    return 0;
}

int menu(){
    int choice;

    printf("please choose one of the following shapes\n"
    "cuboid 1\n"
    "cylinder 2\n");
    scanf("%d", &choice);
    return choice;
}
void V_cuboid(){
    double length, width, height, volume;
    printf("enter the length, width, and height of the cuboid");
    scanf("%lf %lf %lf", &length, &width, &height);
    volume = length*width*height;
    printf("the volume of the cuboid is %lf\n", volume);
}
void V_cylinder(){
    double height, radius, volume;
    printf("enter the radius and the height of the cylinder ");
    scanf("%lf %lf",&radius,&height);
    volume = PI * radius * radius *height; 
    printf("the volume of the sphere is %lf\n", volume);
}