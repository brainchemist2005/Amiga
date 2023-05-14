/*Exercise2 
Problem to solve: A course code, such as CSC2302, is a string!  
Without using a 2D array, write a C program that asks the user for N 
courses codes that the user is taking, and your program should print how 
many of these courses are computer science ones! */



#include<Stdio.h>
#include<string.h>

int check(char *courses,int n)
{ 

    if(courses[0] == 'C' && courses[1] == 'S' && courses[2] == 'C')
    n++;

    return n;
}

int main()
{
    char courses[8];
    int n,j = 0;

    printf("How many courses do you have ? ");
    scanf("%d",&n);

    printf("Enter the courses one by one: ");
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",courses);
        j = check(courses,j);
    }

    printf("The number of cs courses are %d ",j);

    return 0;
}
