#include<stdio.h>
#include<string.h>
//  > <

typedef struct tag{
	char student_name[20];
	int student_id;
	struct tag* next;
}student_node;


//Declare your functions here:
void menu(void);
void add_student(student_node** HT, student_node* ToAdd, int index);
student_node* delete_student(student_node** HT, int id, int index);
char* search_student(student_node** HT, int id, int index);
void display_students(student_node** HT, int size);
student_node* create_initiatize_node();
void initialize_hash_table(student_node** HT, int size);
int hash_function(int id, int size);
int check_empty_hash_table(student_node** HT, int size);

			
/*       Main Function       */			
main(){

  int choice, index, size, id;
  student_node *hash_table[10], *node;
  char name[20];
  size = 10; 
		
		initialize_hash_table(hash_table, size);
		do{
			menu();
			scanf("%d",&choice);
			
			switch(choice){
				
				case 1: 
						node = create_initiatize_node();
						index = hash_function(node->student_id, size);
						add_student(hash_table, node, index);
				       break;
				       
				case 2:
						printf("\n\tPlease input the student ID you wanna delete: "); 
						scanf("%d", &id);
						index = hash_function(id, size);
						node = delete_student(hash_table, id, index);
						
						if(node == NULL)
							printf("\n\tThe %d id is NOT FOUND", id);
						else{
							printf("\n\t%d is removed successfully", node->student_id);
							free(node);
						}	
				       break; 
				       
				case 3:
						printf("\n\tPlease input the student id: ");
						scanf("%d", &id);
						index = hash_function(id, size);
						strcpy(name, search_student(hash_table, id, index));
						if(strcmp(name, "NOT_FOUND") == 0)
							printf("\n\t%d is NOT FOUND", id);
						else
							printf("%d is successfully found", id);	
				       break;
					    
			 	case 4:
			 			display_students(hash_table, size);
    			       break;
    			
				case 5:
						printf("\n\tBye!");
			 			
    			       break;       
				default: printf("\n\tInvalid Choice!\n");  
				
			} // End of switch
			
		}while(choice!=5);		
}

void menu(void){
  printf("\n\t----------- Menu--------------\n");
  printf("\n\t1. Add a student to Hash Table\n");
  printf("\n\t2. Delete a student from Hash Table\n");
  printf("\n\t3. Search for a student in Hash Table\n");
  printf("\n\t4. Display list of students in Hash Table\n");
  printf("\n\t5. Quit\n");
  printf("\n\tYour choice:");
}


void add_student(student_node** HT, student_node* ToAdd, int index){
	if(HT[index] == NULL)
		HT[index] = ToAdd;
	else{
		ToAdd->next = HT[index];
		HT[index] = ToAdd;
	}
}


student_node* delete_student(student_node** HT, int id, int index){
	student_node *walker, *temp;
	
	if(HT[index] == NULL)
		return(NULL);
	else{
		walker = HT[index];
		if(walker->student_id == id){
			HT[index] = walker->next;
			return(walker);
		}
		else{
			while(walker->next != NULL){
				if(walker->next->student_id == id){
					temp = walker->next;
					walker->next = walker->next->next;
					return(temp);
				}
				else
					walker = walker->next;
			}
		}
		return(NULL);
	}
}


char* search_student(student_node** HT, int id, int index){
	student_node* walker;
	
	walker = HT[index];
	if(walker == NULL)
		return("NOT_FOUND");
	else{
		while(walker != NULL){
			if(walker->student_id == id)
				return(walker->student_name);
			else
				walker = walker->next;	
		}
		return("NOT_FOUND");
	}	
}


void display_students(student_node** HT, int size){
	int status, i;
	student_node* walker;
	
	status = check_empty_hash_table(HT, size);
	if(status == 0)
		printf("\n\tHash Table is EMPTY!");
	else{
		printf("\n\tThis is the content of the Hash Table: \n");
		for(i=0; i<size; i++){
			walker = HT[i];
			while(walker != NULL){
				printf("\n\t%s\t%\n", walker->student_name, walker->student_id);
				walker = walker->next;
			}
		}
	}	
}


student_node* create_initiatize_node(){
	student_node* new_node;
	char temp;
	
	new_node=(student_node*)malloc(sizeof(student_node));
	scanf("%c", &temp);
	printf("\n\tInput the student name: ");
	gets(new_node->student_name);
	printf("\n\tInput the student id: ");
	scanf("%d", &new_node->student_id);
	new_node->next = NULL;
	
	return(new_node);
}


void initialize_hash_table(student_node** HT, int size){
	int i;
	
	for(i=0; i<size; i++)
		HT[i] = NULL;
}


int hash_function(int id, int size){
	return(id%size);
}


int check_empty_hash_table(student_node** HT, int size){
	int i;
	
	for(i=0; i<size; i++){
		if(HT[i] != NULL)
		return(1);
	}
	return(0);	
}
