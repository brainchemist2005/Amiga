#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int ticket;
    char name[20];
    struct node*next;
}node;

int enqueue(){

}

int dequeue(){

}

node*create(int i){
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter your name: ");
    gets(newnode->name);
    newnode->ticket=i;
    newnode->next=NULL;
    return (newnode);
}

node*add(node*head,node*newnode){
    node*walker;
    if(head==NULL)
    head=newnode;
    else{
        walker=head;
        while(walker->next!=NULL)
        walker=walker->next;
        walker->next=newnode;
    }
    return (head);
}

node*print(node*head){
    node*walker;
    if(head==NULL)
    printf("The Linked list is empty");
    else{ 
        walker=head;
        while(walker!=NULL){
            printf("The name is %s and the ticket number is %d\n",walker->name,walker->ticket);
            walker=walker->next;
        }
    }
    return head;
}
int main(){
    int i=0;
    char answer;
    node*head=NULL,*newnode;
    do{
    newnode=create(i);
    head=add(head,newnode);
    printf("Do you want to add(y/n) ?");
    scanf(" %c",&answer);
    getchar();
    i++;
    }
    while(answer!='n');
    print(head);
    return 0;
}