#include<Stdio.h>
#include<string.h>
#include<stdlib.h>
int ticket_number_n=0;
int ticket_number_u=0;

typedef struct client_info{
    int ticket;
    char name[20];
}client_info;

typedef struct urgent_client_info{
    struct client_info client_info;
    struct urgent_client_info*next;
}urgent_client_info;

void fill_client(struct client_info*client,int *front ,int *rear){
    if(*front==0){
    printf("\n\t\tEnter the name: ");
    (*front)=++ticket_number_n;
    (*rear)=(*front);
    gets(client[ticket_number_n].name);
    client[ticket_number_n].ticket=ticket_number_n;
    printf("\n\t\tYour ticket number is %d",ticket_number_n);
    }
    else{
    printf("\n\t\tEnter the name: ");
    ticket_number_n++;
    (*rear)=ticket_number_n;
    gets(client[ticket_number_n].name);
    client[ticket_number_n].ticket=ticket_number_n;
    printf("\n\t\tYour ticket number is %d",ticket_number_n);
    } 
}


void swap(int ticket,int *rear,struct client_info *client){
    int j,flag;
    for(j=1;j<=*rear;j++){
        if(client[j].ticket==ticket){
            flag=1;
        break;
    }
        else if(flag==1)
        printf("\n\t\tNot found");
    }

    for(int i=j;i<*rear;i++){
        client[i]=client[i+1];
    }
    --(*rear);
}

urgent_client_info*fill_urgent_client(urgent_client_info*head,urgent_client_info*newnode){
    urgent_client_info*walker;
    if(head==NULL)
    head=newnode;
    else{
        walker=head;
        while(walker->next!=NULL)
        walker=walker->next;
        walker->next=newnode;
    }
        printf("\n\t\tYour ticket number is %d",ticket_number_u);
    return head;
}

void printNormal(struct client_info *client,int front,int rear){
    
    if(front!=rear || front==rear){
    for(int i=front;i<=rear;i++){
        printf("\n\t\tThe name is %s and the ticket number is %d",client[i].name,client[i].ticket);
    }
    }
    else
    printf("\n\t\tThe queue is empty");
}

void serving(struct client_info *client, struct urgent_client_info** head,int *front){
    urgent_client_info*temp;
    if(*head!=NULL){
        printf("\n\t\tThe client %d (%s) has been served ",(*head)->client_info.ticket,(*head)->client_info.name);
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    else if(*head==NULL){
        printf("\n\t\tThe client %d (%s) has been served ",*front,client[*front].name);
        (*front)++;
    }
    else
    printf("\n\t\tThe queue is empty");
    
}

void printUrgent(urgent_client_info*head){
    urgent_client_info*walker;
    int i=0;
    if(head==NULL)
    printf("\n\t\tThe urgent queue is empty");
    else{
        walker=head;
        while(walker!=NULL){
            printf("\n\t\tThe name is %s and the ticket number is %d",walker->client_info.name,walker->client_info.ticket);
            walker=walker->next;
            i++;
        }
    }
}

urgent_client_info*create(void){
    urgent_client_info*newnode;
    newnode=(urgent_client_info*)malloc(sizeof(urgent_client_info));
    printf("\n\t\tEnter your name :");
    gets(newnode->client_info.name);
    newnode->client_info.ticket=++ticket_number_u;
    newnode->next=NULL;
    return newnode;
}

void menu(void){
    printf("\n\t\t-------- Menu TO Use--------\n"); 
    printf("\n\t\t1. Receive a new client\n");
	printf("\n\t\t2. Serve a client\n"); 
	printf("\n\t\t3. Check a queue content\n");
	printf("\n\t\t4. Change the status of a client\n");
	printf("\n\t\t5. Service is over\n");
	printf("\n\t\t---------------------------\n");
	printf("\n\t\tYour choice:");
}


int main(){
    int choice,type,ticket,front=0,rear=0;
    char queue[10];
    urgent_client_info*head=NULL,*newnode;
    client_info *client;
    client=(client_info*)malloc(50*sizeof(client_info));
do{
    out:
    menu(); 
    scanf("%d",&choice); 
    switch(choice){
	case 1:
	printf("\n\t\tIs it an emergency case(1) or a normal case(0) ?");
    scanf("%d",&type);
    getchar();
    if(type==0)
    fill_client(client,&front,&rear);
    else{
    newnode=create();
    head=fill_urgent_client(head,newnode);
    }
	    break;
    case 2:
    	serving(client,&head,&front);
    break;
    case 3:
	printf("\n\t\tWhich queue do you want to check:(normal/urgent) ");
    scanf("%s",queue);
    if(strcmp(queue,"urgent")==0){
        printUrgent(head);
    }
    else if(strcmp(queue,"normal")==0){
        printNormal(client,front,rear);
    }
    else
    printf("\n\t\tWrong input");
    break;
	case 4:
	printf("\n\t\tEnter you ticket number: ");
    scanf("%d",&ticket);
    swap(ticket,&rear,client);
    getchar();
    newnode=create();
    head=fill_urgent_client(head,newnode);
    
    break;
	case 5:
    if(head!=NULL){
    printf("\n\t\tThe emergency queue is not empty yet");
    goto out;
    }
    else if(front>0){
    for(int i=front;i<=rear;i++){
        printf("\n\t\tDear client %d (%s), sorry to inform you that the doctor can receive another day",client[i].ticket,client[i].name);
    }
    }
    printf("\n\t\tTake care!\n\n\t\t");
    break;
    default: printf("\n\t\tSorry That was an INVALID Choice!\n");
	}
}while(choice!=5);

    return 0;
}