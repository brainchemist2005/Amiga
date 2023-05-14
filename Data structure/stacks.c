#include<Stdio.h>
#include<String.h>
#include<stdlib.h>

int display(FILE*file)
{
    int i = 0; 
    char c;
    
    while(c != '\n')
    {
        fscanf(file,"%c",&c);
        i++;
        printf("%c",c);
    }


    return i;
}

void push(char*stack,int size,int *top,int topush)
{
    if(*top == size-1)
    return ;

    else
    stack[++(*top)] = topush;
}

char pop(char*stack,int *top)
{
    if(*top == -1)
    return '+';

    else
    return stack[(*top)--];
}

int checking(char *stack,int size,int *top)
{
    FILE *file = fopen("Expression.txt","r");

    char c,ch;

    while(!feof(file))
    {
    fscanf(file,"%c",&c);
    if(c == '(' || c == '[' || c == '{')
    push(stack,size,top,c);
    
    else if(c == ']' || c == ')' || c == '}')
    {
    if(c == ')' && stack[*top] == '(')
    {
        ch = pop(stack,top);
    }

    else if(c == ']' && stack[*top] == '[')
    {
        ch = pop(stack,top);
    }

    else if(c == '}' && stack[*top] == '{')
    {
        ch = pop(stack,top);
    }
    
    else{
    return -1 ;
    }
    }
    
    }
    
    fclose(file);
    
}

int main()
{
    char*stack;
    int i = 0,top = -1,flag = 0;

    FILE*file = fopen("Expression.txt","r");

    i = display(file);

    fclose(file);

    stack = (char*)malloc(i*sizeof(char));

    flag = checking(stack,i,&top);

    if(top != -1 || flag == -1)
    printf("\nUnbalanced expression");
    else if(top == -1 && flag == 0)
    printf("\nBalanced expression");

    

    return 0;
}