#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int age;
    char name[20];
    struct node*next;
}node;
node*create(void){
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter a name: ");
    scanf("%s",newnode->name);
    printf("Enter an age: ");
    scanf("%d",&newnode->age);
    newnode->next=NULL;
    return (newnode);
}
node*add(node*head,node*newnode){
    node*walker;
    if(head==NULL){
        head=newnode;
    }
    else{
        walker=head;
        while(walker->next!=NULL)
        walker=walker->next;
        walker->next=newnode;
    }
    return (head);
}
node*traverse(node*head){
    node*walker;
    walker=head;
    while(walker!=NULL){
    printf("%s %d\n",walker->name,walker->age);
    walker=walker->next;
    }
    return (head);
}
int main(){
    char answer;
    node*head,*newnode;
    head=NULL;
    do{
        newnode=create();
        head=add(head,newnode);
        printf("Do you want to add a node ?(y/n) ");
        scanf(" %c",&answer);
    }
    while(answer!='n');
    traverse(head);
    return 0;
}