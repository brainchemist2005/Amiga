#include<Stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int id;
    char name[50];
    int gpa;
    struct node*next;
    struct node*previous;
}node;

node*create(FILE*fp)
{
    char temp,temp1[50];
    node*newnode;
    newnode = (node*)malloc(sizeof(node));

        for(int i=0; i<12 ; i++)
        {
            fscanf(fp,"%c",&temp);
        }
        fgets(newnode->name,50,fp);

        for(int i=0; i<10 ; i++)
        {
            fscanf(fp,"%c",&temp);
        }
        fscanf(fp,"%d\n",&newnode->id);

        for(int i=0; i<11 ; i++)
        {
            fscanf(fp,"%c",&temp);
        }
        fscanf(fp,"%d\n",&newnode->gpa);
        fgets(temp1,100,fp);

    newnode->next = NULL;
    newnode->previous = NULL;

    return newnode;
}

node*add_node(node*head,node*newnode)
{
    node*walker = head;

    if(head == NULL)
    head = newnode;

    else
    {
        while(walker->next != NULL)
        walker = walker->next;
        walker->next = newnode;
        newnode->next = NULL;
    }
    return head;
}

node*filling()
{
    node*head = NULL, *newnode;
    FILE *fp = fopen("C:\\Users\\DELL\\Desktop\\Computer Science\\Data structure\\CSC5322_Roster.txt","r");

    while(!feof(fp))
    {
        newnode = create(fp);
        head = add_node(head,newnode);
    }
    
    return head;
}


void displaying(node*head)
{
    node*walker = head;

    while(walker->next != NULL)
    {
        printf("The ID: %d\nThe name: %sThe GPA:%d\n",walker->id,walker->name,walker->gpa);
        printf("---------------\n");
        walker = walker->next;
    }

}

int main()
{
    node*head = NULL, *newnode;
    char answer[3];

    
    head = filling(&head,&newnode);
    displaying(head);

    return 0;
}