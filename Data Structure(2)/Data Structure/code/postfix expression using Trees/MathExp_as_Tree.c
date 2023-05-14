#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
<
>
typedef struct nd{
	char element; 
    struct nd* left_ptr;
    struct nd* right_ptr; 
}node;


typedef struct tag{
    node* element; 
    struct tag*next;
}stack_node;


stack_node* PUSH(stack_node*, stack_node*);
node* POP(stack_node**);
node* create_tree(FILE*,node*);
void menu(void);
void pre_order(node*);
void in_order(node*);


main(){
 
   node*root = NULL; 
   int choice, tree_created_or_not = 0; 
			FILE*infp; 
			infp = fopen("postfix.txt","r"); 
			if(infp==NULL)
			  printf("\n\t\t Could not open the file!\n"); 
	        else{
	        	do{
	        		menu();
					scanf("%d",&choice);
					
					switch(choice){
						case 1: 
								root=create_tree(infp,root);
					       		printf("\n\t\tTree is contstructed!");
					       	 	tree_created_or_not=1;
                        break;
                        
						case 2: 
								if (tree_created_or_not==0)
					            printf("\n\t\tWARNING!! Build the tree first!\n");
		           				else{
		           					printf("\n\t\tInfix Expression is:");
      	 							in_order(root);
		           				}
			            break;
			            
						case 3: 
								if (tree_created_or_not==0)
					            printf("\n\t\tWARNING!! Build the tree first!\n");
		                        else{
		                        	printf("\n\t\tPrefix Expression is:");
					            	pre_order(root);
					      	    }
						break;
						
					    case 4: 
								printf("\n\t\tYou are done!\n\n\t\t");
					    break;
					    
					    default:printf("\n\t\tSorry, that was a wrong choice!!\n");			
					}
			    }while(choice!=4);
            } 
}
	
	
void menu(void){
	printf("\n\n\t\t-------------Math Exp as a Binary Tree-----------\n");
    printf("\n\t\t Choose an option:\n"); 
    printf("\n\t\t1. Build a Tree\n");
    printf("\n\t\t2. Traverse the tree InOrder (infix expression)\n");  
 	printf("\n\t\t3. Traverse the tree PreOrder (Prefix expression)\n");
    printf("\n\t\t4. Done!\n");
 	printf("\n\t\tYour choice:");
}


void pre_order(node*root){
  if (root == NULL)
    return; 
  else{
  	printf("%c", root->element); 
    pre_order(root->left_ptr); 
    pre_order(root->right_ptr); 
  }
}


void in_order(node* root){ 
  if(root == NULL)
    return; 
  else{
  	in_order(root->left_ptr); 
    printf("%c", root->element); 
	in_order(root->right_ptr); 
  }
}


stack_node* PUSH(stack_node* TOP, stack_node* ToPush){
    if(TOP == NULL)
    TOP=ToPush; 
    else{
    	ToPush->next = TOP; 
        TOP = ToPush; 
    }
    return(TOP);
}


node* POP(stack_node** TOP){
   node* popped_element;
   stack_node* toFree; 
   
   if(*TOP == NULL)
	return(NULL); 
   else{
	popped_element = (*TOP)->element; 
	toFree = *TOP;
	*TOP = (*TOP)->next;		
	free(toFree);		
	return(popped_element);				
  }
}


node* create_tree(FILE* infp, node* root){
    char ch;
	node* new_tree_node; 
	stack_node* TOP = NULL;
	stack_node* new_stack_node;
	
	while(!feof(infp)){
		ch=getc(infp);
		if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			
			new_tree_node = (node*)malloc(sizeof(node));
			new_tree_node->element = ch; 
			new_tree_node->right_ptr = POP(&TOP);
			new_tree_node->left_ptr = POP(&TOP);
			
			new_stack_node = (stack_node*)malloc(sizeof(stack_node)); 
			new_stack_node->element = new_tree_node; 
			new_stack_node->next = NULL; 
			
			TOP = PUSH(TOP,new_stack_node);
		}
		else if (isalpha(ch)){
			
			new_tree_node = (node*)malloc(sizeof(node));
			new_tree_node->element = ch;
			new_tree_node->left_ptr = NULL; 
			new_tree_node->right_ptr = NULL;
			
			new_stack_node = (stack_node*)malloc(sizeof(stack_node)); 
			new_stack_node->element = new_tree_node; 
			new_stack_node->next = NULL; 
			
			TOP = PUSH(TOP,new_stack_node);		
		}
		else
		break;
    }
	root = TOP->element; 
	return(root);			
}
