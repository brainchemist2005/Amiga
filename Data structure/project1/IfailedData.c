#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int ID;
    int gpa;
    char name[100];
    struct node*next;
}node;

node*create(FILE*file)
{
    node*newnode;
    char temp,temp1[100];

    newnode = (node*)malloc(sizeof(node));

    for(int i=0 ; i<12 ; i++)
    {
        fscanf(file,"%c",&temp);
    }
    fscanf(file,"%s",newnode->name);
    fscanf(file,"%c",&temp);
    strcat(newnode->name," ");
    fscanf(file,"%s\n",temp1);
    strcat(newnode->name,temp1);


    for(int i=0 ; i<10 ; i++)
    {
        fscanf(file,"%c",&temp);
    }

    fscanf(file,"%d\n",&newnode->ID);

    for(int i=0 ; i<11 ; i++)
    {
        fscanf(file,"%c",&temp);
    }

    fscanf(file,"%d\n",&newnode->gpa);

    fgets(temp1,100,file);

    newnode->next = NULL;
    return newnode;
}


node*add_node(node*head,node*newnode)
{
    node*walker = head;

    if(head == NULL)
    head = newnode;

    else
    {
        if(head->gpa > newnode->gpa)
            {
                newnode->next = head;
                head = newnode;
                return head;
            }
        while(walker->next != NULL)
        {
            if(/*walker->gpa > newnode->gpa &&*/ walker->next->gpa > newnode->gpa)
            {
                newnode->next = walker->next; 
                walker->next = newnode;
                return head;
            }

            walker = walker->next;
        }
        walker->next = newnode; 
    }

    return head;
}


node*loading(node*head,node*newnode,FILE*file)
{
    while(!feof(file))
    {
        newnode = create(file);
        head = add_node(head,newnode);
    }

    printf("%s %d %d",head->name,head->ID,head->gpa);

    return head;
}


void display(node*head)
{
    node*walker = head;

    if(walker == NULL)
    return;

    while(walker != NULL)
    {
        printf("%d %d %s\n",walker->ID,walker->gpa,walker->name);
        walker = walker->next;
    }
}


int main()
{   
    char answer[4];
    node*head = NULL,*newnode;

    FILE*file = fopen("C:\\Users\\DELL\\Desktop\\Computer Science\\Data structure\\CSC5322_Roster.txt","r");

    if(file == NULL)
    printf("not found");

    else
    {

    do
    {
        head = loading(head,newnode,file);
        printf("Yes or no: ");
        scanf("%s",answer);
    }while(strcmp(answer,"yes") == 0);

    //display(head);
    }

    return 0;
}