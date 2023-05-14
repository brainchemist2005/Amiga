#include<stdio.h>
#include<string.h>
#define Size 30


typedef struct{
	char s_name[30];
	int s_id;
	int earned_crd;
}student_info;


//Declare your functions here:
void menu(void);
int add_new_student_heap(student_info* max_heap, int* n_students, student_info new_student);
void delete_student_heap(student_info* max_heap, int* n_students, char* ToServe);
void print_heap_content(student_info* max_heap, int n_students);
void heap_sort(student_info* max_heap, int n_students);
int construct_heap(FILE* infp, student_info* max_heap);
void heapify(student_info* max_heap, int parent_index, int last_index);
void swap(student_info* X, student_info*Y);
int find_largest_element_index(student_info* max_heap, int index1, int index2);
	
		
/*       Main Function       */			
main(){
//  > <
  student_info max_heap[Size], new_student;
  FILE* infp;
  int i, choice, flag=0, returned_value, n_students;
  char ToServe[30];
  
	  infp = fopen("requests.txt", "r");
	  
	  if(infp == NULL)
	  	printf("\n\tFailure To Open The File!\n");
	  	
	  else{
	  		do{
				menu();
				scanf("%d",&choice);
					
				switch(choice){
				
					case 1:	
							n_students = construct_heap(infp, max_heap);
							printf("\n\tHeap Constructed Successfully\n");
							flag = 1;
	     				break;
					       
					case 2:
							if(flag == 0)
								printf("\n\tHeap is not constructed yet!!\n");
							else{
								printf("\nPlease input:\n\tStudent Name: ");
								scanf("%s", new_student.s_name);
								printf("\n\tStudent ID: ");
								scanf("%d", new_student.s_id);
								printf("\n\tStudent earned credits: ");
								scanf("%d", new_student.earned_crd);
								
								returned_value = add_new_student_heap(max_heap, &n_students, new_student);
								if(returned_value == 0)
									printf("\n\tHeap is FULL\n");
								else
									printf("\n\tSuccessfully Added\n");	
							}	 
							
	   					break; 
					        
					case 3: 
				            delete_student_heap(max_heap, &n_students, ToServe);
							if(strcmp(ToServe, "EMPTy") == 0)
								printf("\n\tHeap is EMPTY\n");
							else
								printf("You can register");		
	      				break; 
					       
			  		case 4:
			  				if(flag == 0)
								printf("\n\tHeap is not constructed yet!!\n");
							else
								print_heap_content(max_heap, n_students);
			  	     	break;
			  	     	
			  		case 5:
			  				if(flag == 0)
								printf("\n\tHeap is not constructed yet!!\n");
			  				else
			  					heap_sort(max_heap, n_students);	
						break;
			  	     	
					case 6:
			  					printf("\n\tBye\n\t");
			  	     	break;
						   	          
					default: printf("\n\tInvalid Choice!\n");  
			    } // End of switch
			}while(choice!=6);
	  }	
				
}


void menu(void){
  printf("\n\t----------- Menu--------------\n");
  printf("\n\t----------- Course Registration- Credits Based System--------------\n");
  printf("\n\tPlease choose an option:");
  printf("\n\t1. Construct the heap\n");
  printf("\n\t2. Add a new student to the heap\n");
  printf("\n\t2. Grant a Student a place\n");
  printf("\n\t3. Print the content of the heap\n");
  printf("\n\t4. Heap sort\n");
  printf("\n\t5. Quit\n");
  printf("\n\tYour choice:");
}


int add_new_student_heap(student_info* max_heap, int* n_students, student_info new_student){
		
	int index;
	
	if(n_students == Size)
		return (0);
	else{
		index = (*n_students)++;
		max_heap[index] = new_student;
		while(index >= 1 && max_heap[index].earned_crd > max_heap[(index-1)/2].earned_crd){
			swap(&max_heap[index], &max_heap[(index-1)/2]);
			index = (index-1)/2;
		}
		return (1);
	}	
}


void delete_student_heap(student_info* max_heap, int* n_students, char* ToServe){
	
	int child_index, root_index=0, last_index;
	
	if(*n_students == 0)
		strcpy(ToServe, "EMPTY");
	else{
		strcpy(ToServe, max_heap[root_index].s_name);
		max_heap[root_index] = max_heap[--(*n_students)];
		last_index = *n_students-1;
		
		if(last_index < 0)
			return;
		else{
			child_index = (root_index*2)+1;
			while(child_index <=last_index){
				if(child_index+1 < last_index && max_heap[child_index].earned_crd < max_heap[child_index+1].earned_crd)
					child_index++;
				if(max_heap[child_index].earned_crd < max_heap[root_index].earned_crd){
					swap(&max_heap[child_index], &max_heap[root_index]);
					root_index = child_index;
					child_index = (2*root_index)+1;
				}
				else
					break;
			}
		}	
	}
}


void print_heap_content(student_info* max_heap, int n_students){

	int i;
	
		for(i = 0; i<n_students; i++)
			printf("\n\t%s with %d crd\n", max_heap[i].s_name, max_heap[i].earned_crd);
}


void heap_sort(student_info* max_heap, int n_students){

	student_info temp[Size];
	int i, n_student_temp = n_students;
	char testing[30];
	
	for(i=0; i<n_students; i++)
		temp[i] = max_heap[i];
	
	while(n_student_temp != 0){
		delete_student_heap(temp, &n_student_temp, testing);
		printf("\n\t%s\n", testing);
	}		
}


int construct_heap(FILE* infp, student_info* max_heap){
	
	int i=0, last_index, n_students;
	char temp[30];
	
	//fill the array with the information in the file
	while(!feof(infp)){
		fscanf(infp, "%s", max_heap[i].s_name);
		fscanf(infp, "%d", max_heap[i].s_id);
		fscanf(infp, "%d", max_heap[i].earned_crd);
		fscanf(infp, "%s", temp);
		i++;
	}
	// i will be the number of elements!
	n_students = i;
	last_index = n_students-1;
	
	for(i=((last_index+1)/2)-1; i>=0; i--)
		heapify(max_heap, i, last_index);
	
	return(n_students);	
}


//Heapify
void heapify(student_info* max_heap, int parent_index, int last_index){

	int left_child_index, right_child_index, largest;
	
	//Base Case: we reach a leaf
	if(parent_index > (((last_index+1)/2)-1))
		return;
	else{
		//check if the parent has one kid or two
		left_child_index = (2*parent_index)+1;
		right_child_index = (2*parent_index)+2;
		
		//Case parent has a left child only
		if(right_child_index > last_index)
			largest = find_largest_element_index(max_heap, left_child_index, parent_index);
		//Case parents had two kids
		else{
			largest = find_largest_element_index(max_heap, left_child_index, parent_index);
			largest = find_largest_element_index(max_heap, right_child_index, largest);
		}
		if(largest != parent_index){
			swap(&max_heap[largest] , &max_heap[parent_index]);
			heapify(max_heap, largest, last_index);
		}
	}	
}


void swap(student_info* X, student_info*Y){
	
	student_info temp;
	
	temp = *X;
	*X = *Y;
	*Y = temp;
}


int find_largest_element_index(student_info* max_heap, int index1, int index2){
	
	if(max_heap[index1].earned_crd > max_heap[index2].earned_crd)
		return(index1);
	else
		return(index2);	
}

/*
void create_max_heap(student_info* max_heap, int n_students){

	int i, last_index = n_elements-1;
	
	for(i = ((last_index+1)/2)-1; i >= 0; i--)
	heapify(max_heap, i, last_index);
}*/
