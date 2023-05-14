#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int size = 5;
int ticket = 0;

typedef struct node
{
    int ticket;
    char name[20];
}node;

node*enqueue(node*front,node**rear,node*newnode)
{
    if(front == NULL)
    front = *rear = newnode;

    else
    {
        *rear->next = newnode;
        *rear = newnode;
    }

    return front;
}

node*dequeue(node**front,node**rear)
{
    node*temp;

    if(*front == NULL)
    return NULL;

    else
    {
        temp = *front;
        *front = (*front)->next;
        if((*front)->next == NULL)
        *rear = NULL;
        return temp;
    }
}



int main()
{   
    node array[5];
    node toadd;
    int rear=-1;


    for(int i=0 ; i<5 ; i++)
    {
        printf("\nEnter a name: ");
        scanf("%s",toadd.name);

        (toadd.ticket) = ticket++;

        enqueue(array,&rear,5,toadd);
    }
    dequeue(array,&rear);
    for(int i=0 ; i<5 ; i++)
    {
        printf("%s %d\n",array[i].name,array[i].ticket);
    }
    return 0;
}