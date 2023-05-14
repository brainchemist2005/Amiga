#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//  > <

typedef struct{
	char s_name[20];
	int ID;
}student;

typedef struct{
	student data;
	int flag;
}hash_table_item;

//Declare your functions here:
int n_elements=0;
void menu(void);
int search_student(hash_table_item* HT, int id, int size);
int delete_student(hash_table_item* HT, int id, int size);
int add_student(hash_table_item* HT, student s, int size);
void display_students(hash_table_item* HT, int size);
void init_HT(hash_table_item* HT, int size);

			
/*       Main Function       */			
main(){

  int choice, status, SIZE;
  char temp;
  student stud;
  hash_table_item* HT;
  
  
  printf("\n\tPlease input the number of students: ");
  scanf("%d", &SIZE);
  
  HT = (hash_table_item*)calloc(SIZE, sizeof(hash_table_item));
  init_HT(HT, SIZE); 
		
		do{
			menu();
			scanf("%d",&choice);
			
			switch(choice){
				
				case 1: 
						scanf("%c", &temp);
						printf("\n\tPlease input the student name you wanna add: ");
						gets(stud.s_name);
						printf("\n\tPlease input the student ID: ");
						scanf("%d", &stud.ID);
						status = add_student(HT, stud, SIZE);
						if(status == 1)
							printf("%s is added successfully", stud.s_name);
						else
							printf("\n\tHash table is FULL");	
				       break;
				       
				case 2:
						printf("\n\tInput the student ID you wanna delete: ");
						scanf("%d", &stud.ID);
						status = delete_student(HT, stud.ID, SIZE);
						 if(status == 1)
							printf("%d is deleted successfully", stud.ID);
						else
							printf("\n\t%d is NOT FOUND", stud.ID);
				       break; 
				       
				case 3:
						printf("\n\tInput the student ID: ");
						scanf("%d", &stud.ID);
						status = search_student(HT, stud.ID, SIZE);
						if(status == 1)
							printf("%d is found successfully", stud.ID);
						else
							printf("\n\t%d is NOT FOUND", stud.ID);
				       break;
					    
			 	case 4:
			 			if(n_elements == 0)
			 				printf("\n\tHash table is EMPTY");
			 			else
						 	display_students(HT, SIZE);	
    			       break;
    			
				case 5:
						printf("\n\tHash table contains %d students", n_elements);
				       break; 
					    
				case 6:
						printf("\n\tBye\n");
				       break;	        
				       
				default: printf("\n\tInvalid Choice!\n");  
				
			} // End of switch
		
		}while(choice!=6);		
}

void menu(void){
  printf("\n\t----------- Menu--------------\n");
  printf("\n\t1. Add student\n");
  printf("\n\t2. Delete student\n");
  printf("\n\t3. Find student\n");
  printf("\n\t4. Print list students\n");
  printf("\n\t5. Check number of students\n");
  printf("\n\t6. Quit\n");
  printf("\n\tYour choice:");
}


void init_HT(hash_table_item* HT, int size){
	int i;
	for(i=0; i<size; i++)
	HT[i].flag = 0;
}


int Hash_Function(int id, int size){
	return(id % size);
}


int add_student(hash_table_item* HT, student s, int size){
	int index, i;
	
	index = Hash_Function(s.ID, size);
	i = index;
	
	while(HT[i].flag == 1){
		i = (i+1)%size;
		if(i == index)
			return(0);
	}
	HT[i].flag = 1;
	HT[i].data = s;
	n_elements++;
	return(1);
}


void display_students(hash_table_item* HT, int size){
	int i;
	printf("\n\tStudent Name\tStudent ID\tIndex\n");
	for(i=0; i<size; i++)
		if(HT[i].flag == 1)
			printf("\n\t%s\t%d\t%d", HT[i].data.s_name, HT[i].data.ID, i);			
}


int delete_student(hash_table_item* HT, int id, int size){
	int index, i;
	
	index = Hash_Function(id, size);
	i = index;
	
	while(HT[i].flag != 0){
		if(HT[i].flag == 1 && HT[i].data.ID == id){
			HT[i].flag = -1;
			HT[i].data.ID = 0000;
			strcpy(HT[i].data.s_name, "\0");
			n_elements--;
			return(1);
		}
		i = (i+1) % size;
		if(i == index)
			return(0);
	}
}


int search_student(hash_table_item* HT, int id, int size){
	int index, i;
	
	index = Hash_Function(id, size);
	i = index;
	
	while(HT[i].flag != 0){
		if(HT[i].flag == 1 && HT[i].data.ID == id)
			return(1);
		i = (i+1) % size;
		if(i == index)
			return(0);	
	}
}
