/*Exercise 5 
For this exercise, you are asked to work with a 2D array of 
characters where you will have to do the following:  
- Use a function called filling(): used to fill the 2D array with 
N words 
o  N must be specified by the user before you call the 
function  
- Use a function called sort_array(): used to sort the content of 
the array alphabetically from A to Z using bubble sort. */


#include<Stdio.h>
#include<string.h>

void filling(char *courses,int n)
{

    for(int i=0; i<n ; i++)
    {
        scanf("%s",courses[i]);
    }

}

void swap(char *B,char *A)
{
    char temp[20];

    strcpy(temp,*A);
    strcpy(*A,*B);
    strcpy(*B,temp);

}

void bubblesort(char *courses ,int n){
    int j,i;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(courses[j]>courses[j-1]){
                swap(&courses[j],&courses[j-1]);
            }
        }
    }
}


int main()
{
    int n;

    printf("Enter number of courses: ");
    scanf("%d",&n);
    char courses[n][8];

    filling(courses,n);

    bubblesort(courses,n);

    for(int i=0;i<n;i++)
    {
        printf("%s\n",courses[i]);
    }

    return 0;
}