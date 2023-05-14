#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
	char first_name[10];
	char last_name[10];
	int ticket_number;
}client;

//max # is 10 clients//

//Declare your functions here:
void menu(void);
char* Load_initial_list(FILE*, char*);
int Enqueue(char**, int, int*, char*);
char* Dequeue(char**, int, int*);
void Drop_client(int, client*, char**);
	
		
/*       Main Function       */			
main(){

  int choice, status, front=0, rear=0, i;
  char f_name[10], l_name[10], client_name[20], *arr_;
  //
  //clients_names = (char**)calloc(10, sizeof(char*));
  //for(i=0; i<10; i++)
  //clients_names[i] = (char*)calloc(20, sizeof(char));
		
		
		do{
			menu();
			scanf("%d",&choice);
			
			switch(choice){
			
				case 1:
						//arr_ = Load_initial_list(infp, arr);
						printf("%s", &arr_);
				 
				       break;
				       
				case 2: 
						printf("\n\tPlease enter the client first name: ");
						scanf("%s", f_name);
						//strcpy(new_client->first_name, f_name);
						printf("\n\tPlease enter the client last name: ");
						//scanf("%s", s_name);
						//strcpy(new_client->last_name, l_name);
						//client_name = strcat(f_name, l_name);
						//status = Enqueue(clients, size, rear, name);
						if(status == 0)
							printf("\n\t We are sorry!! The queue is FULL!\n");
						else
							printtf("\n\t%s is successfully added to the queue\n", client_name);
				        break; 
				        
				case 3: 
						//strcpy(client_name, Dequeue(clients_names, front, &rear));
						if(strcmp(client_name, "EMPTY") == 0)
							printf("\n\t We are sorry but the queue is EMPTY");
						else
							printf("\n\t%s is successfully served!\n", client_name);
				       break; 
				       
		  		case 4:
		  				//Drop_client(front, ToRemove, clients);
		  		
		  		       break;
		  		       
				default: printf("\n\tInvalid Choice!\n");  
		    } // End of switch
		}while(choice!=5);		
}


void menu(void){
  printf("\n\t----------- Menu--------------\n");
  printf("\n\t1. Load Initial List\n");
  printf("\n\t2. Add New Client\n");
  printf("\n\t3. Serve a Client\n");
  printf("\n\t4. Drop a Client from the queue\n");
  printf("\n\t5. Quit\n");
  printf("\n\tYour choice:");
}


char* Load_initial_list(FILE* infp, char *arr){
	
	//infp = fopen(clients_appt.txt, "r");
	
	if(infp == NULL)
	printf("Failure to open the file");
	
	else{
		while(!feof(infp)){
        //ch = getc(infp);
        //size++;
   	    }
	    //To put the cursor at the beginning of the file again in order to scan the content
	    //fseek(fptr, 0, 0);
	    //Allocating memory
	    infix_arr = (char*) calloc(size, sizeof(char));
	    fgets(infix_arr, size, fptr);
	    return (arr);
    }
}


int Enqueue(char** clients, int size, int* rear, char* name){
	if((*rear) == size)
	return(0);
	else{
		strcpy(clients[(*rear)], name);
		return(1);
	}
}


char* Dequeue(char** clients, int front, int* rear){
	char ToReturn[20];
	int i;
		if((*rear) == 0)
			strcpy(ToReturn, "EMPTY");
		else{
			stcpy(ToReturn, clients[front]);
			//shifting elements backward
			for(i=front+1; i<(*rear); i++)
			strcpy(clients[i-1], clients[i]);
			//reduce size by 1
			(*rear)--; 
			return(ToReturn);
		}
}


void Drop_client(int front, client* ToRemove, char** clients){
	int i;
		if(rear == 0)
			printf("Queue is EMPTY");
		else{
			for(i=front, i<rear; i++){
				if(strcmp(clients[i]->ticket_number, ToRemove->ticket_number)) == 0){
					do{
						//shifting elements backward
						strcpy(clients[i-1], clients[i]);
						i++;
					}while(i<(*rear))
					//reduce size by 1
					(*rear)--; 
				}
			}
		}
}


