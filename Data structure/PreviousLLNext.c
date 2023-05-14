#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int ID;
    char name[20];
    struct node*next;
    struct node*previous;
}node;

node*create(void){
node*newnode;
newnode=(node*)malloc(sizeof(node));
printf("Enter a name: ");
gets(newnode->name);
printf("Enter ID: ");
scanf("%d",&newnode->ID);
newnode->next=NULL;
newnode->previous=NULL;
return(newnode);
}
node* add(node* head, node* newnode) {
    node* walker;
    if (head == NULL){
        head = newnode;
}
    else {
        walker = head;
        while (walker->next != NULL)
        walker=walker->next;
        newnode->previous=walker;
        walker->next=newnode;
        newnode->next=NULL;
    }
    return (head);
}

int delete(node*head,int todelete){
    node*temp,*walker;
    
    if(head==NULL)
        return -1;
    else{
        if(head->ID==todelete){
        temp=head;
        head=head->next;
        free(temp);
        return 1;
        }
        while(walker->next!=NULL){
        if(walker->ID==todelete){
        temp=walker;
        walker=walker->next;
        free(temp);
        }
        walker=walker->next;
        }
        return 1;
    }
    return 0;
}


node*printing(node*head){
    int choice;
    node*walker=head;
    printf("Do you want to backwards(1), or forwards(2)");
    scanf("%d",&choice);
    if(choice==2){
        while(walker!=NULL){
        printf("\nThe name is %s and the ID is %d ",walker->name,walker->ID);
        walker=walker->next;
    }
    }
    else if(choice==1){
        while(walker->next!=NULL){
            walker=walker->next;
        }
        while(walker!=NULL){
            printf("The name is %s and the ID is %d\n",walker->name,walker->ID);
            walker=walker->previous;
        }
    }
    
}

int main(){
    char answer;
    int todelete,status;
    node*head,*newnode;
    head=NULL;
    do{
        newnode=create();
        head=add(head,newnode);
        printf("\nDo you want to add a new node ?(Y/N)");
        scanf(" %c",&answer);
        getchar();
    }
    while(answer!='n');
    printf("Delete an ID something");
    scanf("%d",&todelete);
    status=delete(head,todelete);
    printing(head);
    return 0;
}