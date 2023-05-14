#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 

typedef struct node{
    int id;
    char name[20];
    struct node*next;
}node;

typedef struct node1{
    int id;
    char name[20],reason[50];
}node1;

int create_heap(FILE*file,node1*max_heap){
    char temp[30];
    int n_students,i=0,last_index;
    while(!feof(file)){
        fscanf(file,"%[^\n]",max_heap.name);
        fscanf(file,"%d",&max_heap.id);
        fscanf(file,"%[\n]",max_heap.reason);
        fscanf(file,"%s",temp);
        i++;
    }
    n_students=i;
    last_index=n_students;
    for(i=(last_index-1)/2;i>=0;i++)
    heapify(max_heap,i,last_index);
    return n_students;
}

void heapify(node1*max_heapify,int parent_index,int last_index){
    int right_child_index,left_child_index,largest_index;
    

}

node*add_node(node*head,node*newnode){
    node*walker;
    if(head==NULL)
    head=newnode;
    else{
    walker=head;
    while(walker->next!=NULL)
    walker=walker->next;
    walker->next=newnode;
    }
    return head;
}

node*create_node(FILE*file){
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    fscanf(file,"%d ",&newnode->id);
    fscanf(file,"%[^\n]",newnode->name);
    newnode->next=NULL;
    return newnode;
}

void menu(void){
    printf("\n\t\t-------- Menu TO Use--------\n"); 
    printf("\n\t\t1. Start the program\n");
	printf("\n\t\t2. Deposit the special request\n"); 
	printf("\n\t\t3. Drop the course\n");
	printf("\n\t\t4. Print special request list\n");
	printf("\n\t\t5. Special request process is over\n");
	printf("\n\t\t---------------------------\n");
	printf("\n\t\tYour choice:");
}

void add_student_LL(node**head,node**newnode){
    FILE*file=fopen("CSC5322_Roster.txt","r");
    while(!feof(file)){
        *newnode=create_node(file);
        *head=add_node(*head,*newnode);
    }
    fclose(file);
}

void traverse(node*head){
    node*walker;
    walker=head;
    while(walker!=NULL){
        printf("\n\t\t%s %d",walker->name,walker->id);
    walker=walker->next;
    }
}

int main(){
    int answer;
    node*newnode,*head=NULL;
    
    do{
        menu();
        scanf("%d",&answer);
        switch(answer){
            case 1:

            add_student_LL(&head,&newnode);
            traverse(head);
            /*case 2:
            case 3:
            case 4:
            case 5:*/
        }

    }
    while(answer!='5');
    return 0;
}