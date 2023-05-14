#include<stdio.h>


//Declare your functions here:
void menu(void);
int load_numbers(char* file_name, int* arr, int* status);
void print_heap(int* arr, int n_elements);
void create_max_heap(int* arr, int n_elements);
void heapify(int* arr, int parent_index, int last_index);
int find_max_element_index(int* arr, int index1, int index2);
void swap(int* X, int*Y);
int add_number_heap(int* arr, int* n_elements, int value, int size);
int delete_high_priority(int* arr, int* n_elements);
void heap_sort(int* arr, int n_elements, int size);

	
		
/*       Main Function       */			
main(){
//  > <
  int choice, n_elements, arr[15], element_to_add, flag=0, max_size, p_element;
  char file_name[20];
  max_size = 15;
  
  //As long as the file is not accessed	
  while(flag == 0){
  	printf("Please input the file name: ");
  	gets("file_name");
  	n_elements = load_numbers(file_name, arr, &flag);
  }
  print_heap(arr, n_elements);
  printf("==> Make sure you construct the max heap first");
		
		do{
			menu();
			scanf("%d",&choice);
				
			switch(choice){
			
				case 1:
						create_max_heap(arr, n_elements);
						print_heap(arr, n_elements);
				 
     				break;
				       
				case 2: 
						printf("Please input the element to add: ");
						scanf("%d", &element_to_add);
						flag = add_number_heap(arr, &n_elements, element_to_add, max_size);
						
						if(flag == 9999)
							printf("\n\tHeap is FULL\n");
						else{
							printf("\n\t%d is added to the heap\n", element_to_add);
							print_heap(arr, n_elements);
						}
   					break; 
				        
				case 3: 
						p_element = delete_high_priority(arr, &n_elements);
						if(p_element == 9999)
							printf("\n\tHeap is EMPTY\n");
						else{
							printf("\n\t%d is released from the heap\n", p_element);
							print_heap(arr, n_elements);
						}
      				break; 
				       
		  		case 4:
		  					print_heap(arr, n_elements);
		  	     	break;
		  	     	
		  		case 5:
		  					if(n_elements > 0){
		  						printf("Heap element sorted in descending order: \n\t");
		  						heap_sort(arr, n_elements, max_size); 
							  }
		  	     	break;
		  	     	
				case 6:
		  					printf("\n\tBye\n\t");
		  	     	break;
					   	          
				default: printf("\n\tInvalid Choice!\n");  
		    } // End of switch
		}while(choice!=6);		
}


void menu(void){
  printf("\n\t----------- Menu--------------\n");
  printf("\n\t1. Create max heap\n");
  printf("\n\t2. Add an element to the heap\n");
  printf("\n\t3. Print the content of the heap\n");
  printf("\n\t4. Heap sort\n");
  printf("\n\t5. Quit\n");
  printf("\n\tYour choice:");
}


//Load data from the file
int load_numbers(char* file_name, int* arr, int* status){
	
	FILE* infp;
	int i=0;
	char ch;
	
	infp = fopen(file_name, "r");
	if(infp == NULL){
		printf("\n\tFailure to Open the File!\n");
		*status = 0;
	}
	else{
		*status = 1;
		do{
			fscanf(infp, "%d", &arr[i]);
			i++;
			ch = getc(infp);
		}while(ch != EOF);
	}
	fclose(infp);
	return(i);
}


//Print the content
void print_heap(int* arr, int n_elements){

	int i;
	//check first if the heap has some elements
	if(n_elements == 0)
		printf("\n\tHeaps is EMPTY");
	else{
		printf("\n\tThis is the content of the array:\n\t");
		for(i = 0; i<n_elements; i++)
			printf("%d", arr[i]);
		printf("\n");
	}	
}


//Create max heap
void create_max_heap(int* arr, int n_elements){

	int i, last_index = n_elements-1;
	
	for(i = ((last_index+1)/2)-1; i >= 0; i--)
	heapify(arr, i, last_index);
}


//Heapify
void heapify(int* arr, int parent_index, int last_index){

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
			largest = find_max_element_index(arr, parent_index, left_child_index);
		//Case parents had two kids
		else{
			largest = find_max_element_index(arr, parent_index, left_child_index);
			largest = find_max_element_index(arr, largest, right_child_index);
		}
		if(largest != parent_index){
			swap(&arr[largest] , &arr[parent_index]);
			heapify(arr, largest, last_index);
		}
	}	
}


int find_max_element_index(int* arr, int index1, int index2){
	
	if(arr[index1] > arr[index2])
		return(index1);
	else
		return(index2);	
}


void swap(int* X, int*Y){
	
	int temp;
	
	temp = *X;
	*X = *Y;
	*Y = temp;
}



int add_number_heap(int* arr, int* n_elements, int value, int size){
		
	int i;
	
	if(*n_elements == size)
		return 9999;
	else{
		i = (*n_elements)++;
		arr[i] = value;
		while(i >= 1 && arr[i] > arr[(i-1)/2]){
			swap(&arr[i], &arr[(i-1)/2]);
			i = (i-1)/2;
		}
		return value;
	}	
}


int delete_high_priority(int* arr, int* n_elements){
	
	int high_priority, child_index, root_index=0, last_index;
	
	if(*n_elements == 0)
	high_priority = 9999;
	else{
		high_priority = arr[root_index];
		arr[root_index] = arr[--(*n_elements)];
		last_index = *n_elements-1;
		child_index = (2*root_index)+1;
		
		while(child_index <=last_index){
			if(arr[child_index] < arr[child_index+1])
			child_index++;
			if(arr[child_index] > arr[root_index]){
				swap(&arr[child_index], &arr[root_index]);
				root_index = child_index;
				child_index = (2*root_index)+1;
			}
			else
				break;
		}
	}
	return(high_priority);
}


void heap_sort(int* arr, int n_elements, int size){

	int temp[size], i, back_up = n_elements;
	
	for(i=0; i<n_elements; i++)
		temp[i] = arr[i];
	
	while(back_up != 0)
		printf("%d", delete_high_priority(temp, &back_up));
	printf("\n");		
}
