/*Exercise1 
Problem to solve: one of the criteria used to check if a password is a strong 
one or not, is to check its length!   
Without using a 2D array, write a C program that request from the user 5 
passwords and your program should print the strongest password (the 
longest one)! */




#include<stdio.h>
#include<string.h>

void pass_check(char *password, char *pass)
{
    
    if(strlen(pass) < strlen(password))
    strcpy(pass,password);

}


int main()
{
    char password[15];
    char pass[15] = {'\0'};

    for(int i=0 ; i<5 ; i++)
    {
    fflush(stdin);
    printf("Enter a password: ");
    gets(password);
    if(strlen(pass) < strlen(password))
    strcpy(pass,password);
    }


    printf("The strongest password is %s",pass);

    return 0;
}