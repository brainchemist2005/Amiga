#include <stdio.h>
#include <stdlib.h>

int main()
{
int students[5][6],min,total;
float average[5];
for(int i=0;i<5;i++)
{
    printf("enter the ID of the student\n");
    scanf("%d",&students[i][0]);
for(int j=1;j<6;j++)
{
    printf("enter a grade\n");
    scanf("%d",&students[i][j]);
}
}
for(int i=0;i<5;i++)
{
min=students[i][1];
total=0;
for(int j=2;j<6;j++)
{
if(students[i][j]<min)
min=students[i][j];
}
for(int j=1;j<6;j++)
total=total+students[i][j];
average[i]=(float)(total-min)/4;
}
for(int i=0;i<5;i++)
{
for(int j=0;j<6;j++)
{
printf("%d\t",students[i][j]);
}
printf("The average of this student is %.2f\n",average[i]);
}
return 0;
}