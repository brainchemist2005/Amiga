#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tag{
  int id; 
  char name[20]; 
  double gpa;
  struct tag*next;
  struct tag*previous;
}node;

node* create_fill_node(void){

node* new_node; 

  new_node= (node*)malloc(sizeof(node));
  getchar();
  printf("\n\t\tInput student name:"); 
  gets(new_node->name); 
  printf("\n\t\tInput %s'ID:", new_node->name); 
  scanf("%d",&new_node->id); 
  printf("\n\t\tInput %s'GPA:", new_node->name); 
  scanf("%lf",&new_node->gpa); 
  new_node->next=NULL; 
  new_node->previous=NULL; 
  return(new_node);
}
node* add_node(node*head, node*ToAdd){
  node* walker;
  if(head==NULL)
    head=ToAdd; 
  else if(ToAdd->gpa > head->gpa)
  { ToAdd->next= head; 
    head->previous = ToAdd; 
	head=ToAdd;   
  }
  else{
  walker=head;
	while(walker->next!=NULL){   
      if((walker->gpa >= ToAdd->gpa) && (walker->next->gpa < ToAdd->gpa))
      {  ToAdd->next=walker->next; 
        ToAdd->previous=walker;
        walker->next = ToAdd; 
        ToAdd->next->previous=ToAdd;
        break;	  
	  }
	  else
	    walker=walker->next; 
      }//End of loop
	  if (walker->next == NULL){
	    walker->next=ToAdd;  
	    ToAdd->previous=walker;
	  }
  }
return(head);}

void menu(void){

  printf("\n\t\t----------------- Linked List Menu -------------------\n");
  printf("\n\t\t|\t 1. Add a new student            		|\n");
  printf("\n\t\t|\t 2. Delete a student             		|\n");
  printf("\n\t\t|\t 3. Traverse Linked List Backward or Forward	|\n");
  printf("\n\t\t|\t 4. Store LL content to a FILE                  |\n");
  printf("\n\t\t|\t 5. Quit                         		|\n");
  printf("\n\t\t--------------------------------------------------------\n");
  printf("\n\t\tPlease make your choice:");
}
//---> you need to change this function
//The user can choose to traverse the 
//linked list Backward or Forward
void traverse_linked_list(node*head,int choice){

  node*walker=head; 
  
  if(walker==NULL)
    printf("\n\t\tLinked List is Currently EMPTY!\n"); 
  else{
  	printf("\n\t\tLinked List contain node(s):\n");
  if(choice==2){
    
    while(walker!=NULL)
    {
    printf("\n\t\tName: %s\n",walker->name);
    printf("\n\t\tID: %d\n",walker->id);
    printf("\n\t\tGPA: %.2f\n",walker->gpa);
    printf("\n\t\t/*/*/*/*/*/*/*/*/*//*/*/*/*/*/\n");
     //Move the walker to the next node if any
	walker = walker->next;    	
	}
  }
  else if(choice==1){
    while(walker->next!=NULL){
      walker=walker->next;
    }
    while(walker!=NULL){
      printf("\n\t\tName: %s\n",walker->name);
      printf("\n\t\tID: %d\n",walker->id);
      printf("\n\t\tGPA: %.2f\n",walker->gpa);
      printf("\n\t\t/*/*/*/*/*/*/*/*/*//*/*/*/*/*/\n");
      walker=walker->previous;
    }
  }
  }
}

void delete(int n){
  
  struct Node* temp1 = head;
    if(n ==1){
    head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 0;i<n-2;i++)
        temp1 = temp1->next;
        
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);

}

int main(void)
{
    int choice,n;
   node*head=NULL, *new_node; 
  int choice_traversal; 
    
  do{
    
    menu();
    scanf("%d",&choice);
    
    switch(choice){
case 1:new_node = create_fill_node(); 
	        head= add_node(head,new_node);
	        break;
    case 2: 
    printf("Enter the ID you want to delete: ");
    scanf("%d",&n);
    delete(n);
            break;
    case 3:printf("\n\t\tBackward (1) or Forward (2)");
	        scanf("%d",&choice_traversal);
			//Change the function arguments 
	        traverse_linked_list(head,choice_traversal);
            break;
     case 4: //You need to implement a 
             //function that will copy the 
             //LL content to a file
             //Destroy the LL once done
            break;
	case 5: printf("\n\t\t Decided to Quit.....\n\n\t\t BYE\n\n\t\t");
            break;
    default:printf("\n\t\t SORRY! WRONG CHOICE!\n");
	}
  
  }while(choice!=5);     

return(0);
}