/*Exercise3 
Problem to solve: The digits you have in a course code means the 
following:  
- First digit: Year where you are supposed to take the course 
- Second digit: number of credits 
- The last two digits: represent the course sequence. For instance, 
CSC2302 means the second CSC course to take! 
Without using a 2D array, write a C program that asks the user for N 
courses codes and your program should display the total number of 
credits! 
N.B: you need to find how to change a char to an int!  */




#include<stdio.h>
#include<string.h>
#include<stdlib.h> //x = atoi

int credits(char* course, int n)
{
    int crd;
    char c;    

    /*if(course[4] == '0')
    crd = 0;
    else if(course[4] == '1')
    crd = 1;
    else if(course[4] == '2')
    crd = 2;
    else if(course[4] == '3')
    crd = 3;
    else if(course[4] == '4')
    crd = 4;*/

    c = course[4];

    crd = atoi(&c);

    n += crd;

    return n;
}



int main()
{
    char course[8];
    int n,j = 0;

    printf("How many courses do you have: ");
    scanf("%d",&n); 

    printf("Enter your courses one by one: ");

    for(int i=0 ; i<n ; i++)
    {
        scanf("%s",course);
        j = credits(course,j);
    }

    printf("The number of credits you entered are: %d",j);

    return 0;
}