#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    char name[20];
    int age;
    struct node*next;
}node;

node*create(void){
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter your name: ");
    gets(newnode->name);
    printf("Enter your age: ");
    scanf("%d",&newnode->age);
    newnode->next=NULL;
    return newnode;
}

void enqueue(node**head,node*newnode,node**tail){
    if(*head==NULL)
        *head=newnode;
    else{
        (*tail)->next=newnode;
    }
    (*tail)=newnode;
}

char dequeue(node**head,node**tail){
    char left[10];
    node*temp;
    if(*head==NULL)
    printf("The queue is empty");
    else{
        
    }
    return ;
}

void print(node*head){
    node*walker;
    walker=head;
    while(walker!=NULL){
    printf("The name is %s and the age is %d\n",walker->name,walker->age);
    walker=walker->next;
    }
    
}

int main(){
    char answer;
    node*head=NULL,*newnode,*tail;
    do{
    newnode=create();
    add(&head,newnode,&tail);
    printf("Do you want to add? ");
    scanf(" %c",&answer);
    getchar();
    }
    while(answer!='n');
    print(head);
    return 0;
}