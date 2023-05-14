#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag{
	char name[30];
	int ticket_number;
	char requested_service[10];
	struct tag *next;	
                   }client_info;

//Functions declaration
void menu(void);
client_info* create_fill_node(int*,int*,int*);
void enqueue_client(client_info*,client_info**);
int dequeue_client(client_info**,FILE*,int); 
client_info* switch_tickets(client_info*, int, int,int*);
void swap(client_info*,client_info*);
void end_of_service(FILE*,client_info**,client_info**,client_info**);



int main(void){
	  int choice;
   	client_info* front1=NULL,* front2=NULL,* front3=NULL;
   	client_info* new_node;
    int cnt1=1,cnt2=1,cnt3=1,i=0,status,X,Y;
    FILE *infp1,*infp2,*infp3,*infp4;
   

  do{
    menu();
		scanf("%d",&choice);
		switch(choice){
		case 1:new_node=create_fill_node(&cnt1,&cnt2,&cnt3);
           if(strcmp(new_node->requested_service,"Money")==0)
            enqueue_client(new_node, &front1);
          else if(strcmp(new_node->requested_service,"Account")==0)
            enqueue_client(new_node, &front2);
          else if(strcmp(new_node->requested_service,"Meeting")==0)
            enqueue_client(new_node, &front3);
          else if(strcmp(new_node->requested_service,"None")==0)
            printf("The service requested is not available\n");
           break;
        
		case 2:  printf("Enter the number corresponding to the service:\n 1. Money transactions\n 2. Account Issues\n 3. Meet the bank director\n-> ");
            scanf("%d",&i);
            while(i!=1 && i!=2 && i!=3){
              printf("Wrong choice! Enter again\n-> ");
              scanf("%d",&i);          }
            if(i==1)
            	status=dequeue_client(&front1,infp1,i);                               
            else if(i==2)
            	status=dequeue_client(&front2,infp2,i);
            else if(i==3)
            	status=dequeue_client(&front3,infp3,i);
            if(status==0)
              printf("The queue is empty!\n");
            else 
              printf("The client is dequeued succesfully\n");
		       break;
              
	  	case 3: printf("Enter the number corresponding to the service:\n 1. Money transactions\n 2. Account Issues\n 3. Meet the bank director\n-> ");
            scanf("%d",&i);
            while(i!=1 && i!=2 && i!=3){
              printf("Wrong choice! Enter again\n-> ");
              scanf("%d",&i);          }
            printf("Enter the numbers of the two tickets that want to switch places:\n-> ");
            scanf("%d%d",&X,&Y);
            if(i==1)
              front1=switch_tickets(front1, X, Y,&status);
            else if(i==2)
               front2=switch_tickets(front2, X, Y,&status);
            else if(i==3)
               front3=switch_tickets(front3, X, Y,&status);
            
            if(status==0)
              printf("Could not switch tickets!\n");
            else 
              printf("The tickets were switched succesfully\n");
   			    break;    
        
		case 4:end_of_service(infp4,&front1,&front2,&front3);
		       printf("Bye!\n");
               break;        
        
		default:printf("You have entered a wrong number!\n");
                break; }
	}while(choice!=4);


return 0;}

void menu(void){
    printf("\t*************Welcome to our bank!*************\n");
	printf("\t\tPlease choose from the menu below:\n");
	printf("\t\t1. Add a client to a queue\n");
	printf("\t\t2. Serve a client in the queue\n");
	printf("\t\t3. Switch tickets in a queue\n");
	printf("\t\t4. Bank Service is over\n");
	printf("\t**********************************************\n");
	printf("\t\t\n-> ");
                }
    
     
client_info* create_fill_node(int *cnt1,int *cnt2,int *cnt3){
	client_info * new_node;
	char name[30],ch;
  int choice;
  
  new_node=(client_info*)malloc(sizeof(client_info));
  printf("Enter please the  name of the client\n-> ");
  
  ch = getchar();
  gets(name);
  
  strcpy(new_node->name,name);
  printf("Enter please the requested service of the client, choose from the menu below:\n 1 for Money, 2 for Account, or 3 for Meeting  ");
  scanf("%d",&choice);
  if(choice==1){
    strcpy(new_node->requested_service,"Money");
    new_node->ticket_number=*cnt1;
     (*cnt1)++;}
    
  else if(choice==2){
    strcpy(new_node->requested_service,"Account");
    new_node->ticket_number=*cnt2;
    (*cnt2)++;      }         
  else if(choice==3){
    strcpy(new_node->requested_service,"Meeting");
    new_node->ticket_number=*cnt3;
     (*cnt3)++;     }
  else
    strcpy(new_node->requested_service,"None"); 

	  new_node->next=NULL;
    return(new_node);}     


void enqueue_client(client_info* node ,client_info** front){
  client_info * walker;
  
  if(*front==NULL)
    *front=node;
  else{
    walker= *front;
    while(walker->next!=NULL){
      walker=walker->next;}
      walker->next=node;
      }
}


int dequeue_client(client_info** front, FILE* infp,int i){
  client_info* walker= *front;
  if(i==1)
    infp=fopen("Money_S.txt","a");
  else if(i==2)
    infp=fopen("Account_S.txt","a");
  else if(i==3)
    infp=fopen("Meeting_S.txt","a");
  
    if(*front==NULL)
    return(0);

  else {fprintf(infp,"%s \n",walker->name);
      *front=(*front)->next;
      free(walker);   
                      }
     fclose(infp);
      return(1);  }                 



client_info* switch_tickets(client_info* front, int X, int Y,int* status){
  client_info* walker1, *walker2;
  
  if(front==NULL)
    *status=0;
  else{
    walker1=front;
    walker2=front;
    while(walker1!=NULL){
      if(walker1->ticket_number==X)
       break;  
      walker1=walker1->next;}
    while(walker2!=NULL){
      if(walker2->ticket_number==Y)
        break;
      walker2=walker2->next;
                       }
      }
     
      if(walker1==NULL || walker2==NULL)
         *status=0;
      else{
        swap(walker1,walker2);
        *status=1;
                  }  
                  return(front);}                                   


void swap(client_info* c1,client_info* c2){
  char  client[20];
  strcpy(client,c1->name);
  strcpy(c1->name,c2->name);
  strcpy(c2->name,client);                }         



void end_of_service(FILE* infp,client_info** front1,client_info** front2,client_info** front3){
	client_info* walker, *temp;
	infp=fopen("clients_not_served.txt","w");
	
  fprintf(infp,"The clients left in the queue of Money are:\n");
		if(*front1==NULL)
    		fprintf(infp,"\tnone\n");
    	else{
        walker=*front1;
    		while(walker!=NULL){
      			fprintf(infp,"\t%s  \n", walker->name);
                temp=walker;
      		      walker=walker->next;
                *front1=walker;
                free(temp);
                       }
         }
        
   fprintf(infp,"The clients left in the queue of Account are:\n");
		if(*front2==NULL)
    		fprintf(infp,"\tnone\n");
    	else{
        walker=*front2;
    		while(walker!=NULL){
      		fprintf(infp,"\t%s  \n", walker->name);
      			  temp=walker;
      			  walker=walker->next;
              *front2=walker;
              free(temp);
                         }
      }
    fprintf(infp,"The clients left in the queue of Meeting are:\n");
		 if(*front3==NULL)
    		fprintf(infp,"\tnone\n");
    	else{
        walker=*front3;
    		while(walker!=NULL){
      	 fprintf(infp,"\t%s  \n", walker->name);
      		  temp=walker;
      			walker=walker->next;
            *front3=walker;
            free(temp);
                       }
         }
 
  fclose(infp);} 
