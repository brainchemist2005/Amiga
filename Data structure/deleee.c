#include<Stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int age;
    char name[20];
    struct node*next;
    struct node*previous;
}node;
node*create(void){
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter name: ");
    gets(newnode->name);
    printf("Enter age: "); 
    scanf("%d",&newnode->age);
    newnode->next=NULL;   
    return (newnode);
}

node*add(node*head,node*newnode){
    node*walker;
    if(head==NULL){
        head=newnode;
    }
    else {
        walker=head;
        while(walker->next=NULL)
            walker=walker->next;
            newnode->previous=walker;
            walker->next=newnode;
            newnode->next=NULL;
    }
return(head);
}
void print(node*head,int choice){
    node*walker=head;
    if(head==NULL)
    printf("The linked list is empty");
    else{
        if(choice==1){
        while(walker!=NULL){
            printf("The name is %s and the age is %d\n",walker->name,walker->age);
            walker=walker->next;
        }//THe problem is here
        }
        else if(choice==2){
            while(walker->next!=NULL){
                walker=walker->next;
            }
            while(walker!=NULL){
                printf("The name is %s and the age is %d\n",walker->name,walker->age);
                walker=walker->previous;
            }
        }
    }
}


int main(){
    int answer,choice;
    node*head,*newnode;
    head=NULL;
    do{
        head=create();
        newnode=add(head,newnode);
        printf("Do you want to add a new node ?");
        scanf("%d",&answer);
        getchar();
    }
    while(answer==1);
    printf("Do you want to print forward(1) or backwards(2) ");
    scanf("%d",&choice);
    print(head,choice);
return 0;
}