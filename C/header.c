#include<stdio.h>
#define PI 3.14

int menu(){
    int choice;
    printf("choose a shape\n"
    "Hemisphere-1\n"
    "Pyramid-2\n"
    "Cone-3\n"
    "Sphere-4\n");
    scanf("%d",&choice);
    return choice;
}
void V_hemisphere(){
    double radius, volume;
    printf("enter the radius of the hemisphere: ");
    scanf("%lf", &radius);
    volume = radius * PI * radius * radius * 2/3 ;
    printf("the volume of the hemisphere is %.3lf\n", volume);
}
void V_pyramid(){
    double height, length, volume;
    printf("enter the length and height of the pyramid: ");
    scanf("%lf %lf", &length, &height);
    volume = length * length * height * 1/3;
    printf("the volume of the pyramid is %.3lf\n", volume);
}
void V_cone(){
    double radius,height,volume;
    printf("enter the radius and height of the cone: ");
    scanf("%lf %lf", &radius, &height);
    volume = PI * radius* radius *height*1/3;
    printf("the volume of the cone is %.3lf\n", volume);
}
void V_sphere(){
    double radius,volume;
    printf("enter the radius of the sphere: ");
    scanf("%lf", &radius);
    volume = PI * radius * radius *radius * 4/3;
    printf("the volume of the sphere is %.3lf\n", volume);
}