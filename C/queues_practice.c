#include<stdio.h>
#include<String.h>
#include<Stdlib.h>

int ticket_n = 0;

typedef struct node
{
    int ticket;
    char name[50];
    struct node*next;
    struct node*previous;
}node;

