#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct corona{
	char country[30];
	int affected_people;
	int deaths;
	struct corona* next;
}node;


//Declare your functions here:
void menu(void);
void load_screen(FILE*);
void create_LL(FILE* ,node*);
void update_records(node*, char*, int*, int*);
void quit(node*, FILE*);
	
		
/*       Main Function       */	
		
int main(){

  int choice, d;
  FILE*data;
  node*head; 
		
		
		do{
		menu();
		scanf("%d",&choice);
		
		switch(choice){
		
		case 1: 
		d= load_screen();
		       break;
		case 2: 
		d= create_LL(,);
		       break; 
		case 3: 
		d= update_records(, , ,);
		       break; 
		case 4:printf("\n\tTHE END!!!!!\n\n\t"); 
		d=quit( , );
		       break; 
		default: printf("\n\tInvalid Choice!\n");  
		} // End of switch
		}while(choice!=4);		
}
void menu(void){
  printf("\n\t----------- Menu--------------\n");
  printf("\n\t1. Load data to screen\n");
  printf("\n\t2. Create Linked List\n");
  printf("\n\t3. Update Data\n");
  printf("\n\t4. QUIT\n");
  printf("\n\tYour choice:");
}
void load_screen(FILE *data){
	char country;
	int affected_people, deaths;
	FILE *data;
	data= fopen("D:\CSC2302_Exam1_Files","r");
	if (data==NULL)
	printf("Not Found");
	else {
	do {
		fscanf(data, "%s\n%d\n%d",country, &affected_people, &deaths);
		printf ("%s\n%d\n%d",country,affected_people,deaths);
		printf ("-------------------------------------------------------------");
		end_file=getc(data);
	}while (end_file!=EOF);
	fclose(data);
	}
	return(0);
}

void create_LL(FILE*data ,node *head){
	node *head, *new_node, *last;
	char answer;
	
	head= (node*)malloc(sizeof(node));
	printf("Create the head of the LL Input the country name, the affected people,and the deaths: ");
	scanf("%s %d %d", head->country, &head->affected_people, &head->deaths);
	last=head;
	printf("\n The next nodes: \n");
	do {
		new_node= (node*)malloc(sizeof(node));
			printf("Create the head of the LL Input the country name, the affected people,and the deaths: ");
			scanf("%s %d %d", new_node->country, &new_node->affected_people, &new_node->deaths);
			last->next=new_node;
			last=new_node;
			printf("Add new node? Y/N:");
			scanf("%c",&answer);
		}while(answer=='Y' || answer=='y');
		last->next=NULL;
return;
}

void update_records(node *head, char*country_name, int*new_affected, int*new_deaths){
	node*head, *walker, *NodeToAdd;
	
	do{
		
		if(node->new_affected!=node->affected_people || node->deaths!=node->deaths){
			node->affected_people=node->new_affected;
			node->deaths=node->deaths;
		}
	}while(node!=NULL);
	
	
	if(NodeToAdd->affected_people<head->affected_people){
		NodeToAdd->net=head;
		head=NodeToAdd
	}
	else {
		walker=head;
		while(walker->next!=NULL){
			if(NodeToAdd->affected_people<walker->affected_people){
			   NodeToAdd->next=NodeToAdd;
			   break;
			}
			walker=walker->next;
		}
		if(walker->next==NULL){
			walker->next=NodeToAdd;
			NodeToAdd->next=NULL;	
		}
	}
return;	
}

void quit(node*head, FILE*data) {
	int*new_affected, *new_deaths;
	node*head, *walker, *NodeToAdd;
	if(NodeToAdd->affected_people<head->affected_people){
		NodeToAdd->net=head;
		head=NodeToAdd
	}
	else {
		walker=head;
		while(walker->next!=NULL){
			if(NodeToAdd->affected_people<walker->affected_people){
			   NodeToAdd->next=NodeToAdd;
			   break;
			}
			walker=walker->next;
		}
		if(walker->next==NULL){
			walker->next=NodeToAdd;
			NodeToAdd->next=NULL;	
		}
	return;
}
