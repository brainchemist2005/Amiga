#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Node declaration
typedef struct _node{
    char key;
    struct _node* next;
                     }node;


//Functions Declaration
void menu(void);
char* from_file_to_array(FILE* fptr, char * infix_arr);
char* reverse_array(char* infix_arr); 
node* create_fill_node(char);
node* pushtop(node* top, node* newNode);
char poptop(node** top);
char* infix_prefix(char* infix_arr, char* prefix_arr);
int priority(char);

//Main
int main(){

    int choice;
    int flag = 0;
    char *infix_arr, *prefix_arr;
    node *top=NULL;
    FILE *fptr;

    fptr = fopen("infix.txt", "r");
    if(fptr == NULL){
        printf("\n\nERROR: Failure to open the file! \n\n");
        return 0;
    }
    do{
        menu();
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
	        flag = 1;
	        infix_arr = from_file_to_array(fptr, infix_arr);
          printf("The array is now filled with the content of your file!\n");
            break;
        case 2:
            if(flag == 0){
                printf("\n\nERROR: Please choose option 1 first! \n\n");
                break;
            }
            flag = 2;
            infix_arr = reverse_array(infix_arr);
            printf("Your reversed infix expression is %s", infix_arr);
            break;

        case 3:
            if(flag != 2){
                printf("\n\nERROR: Choices 1 and 2 must be chosen before choice 3! \n\n");
                break;
            }
            prefix_arr = infix_prefix(infix_arr, prefix_arr);
            //Print the prefix expression
            printf("\n\tYour prefix expression is : %s", prefix_arr);
            break;
        case 4:
            printf("Thanks for using our program!\n");
            break;
        default:
            printf("Invalid choice! ");
        }
    }while(choice != 4);
    fclose(fptr);
}

void menu(void){
	printf("\n\n\t\t\t****************MENU****************\t\t\t\n");
    printf("\n\t\t\t1. Load infix expression to an array\n\t\t\t2. Reverse infix\n\t\t\t3. Convert infix to prefix\n\t\t\t4. Quit\n");
    printf("\n\t\t\t************************************\t\t\t\n\n");
}

char* from_file_to_array(FILE* fptr, char *infix_arr){
    char ch;
    int size = 0;

    //To find the size of the expression
    while(!feof(fptr)){
        ch = getc(fptr);
        size++;
    }
    //To put the cursor at the beginning of the file again in order to scan the expression
    fseek(fptr, 0, 0);
    //Allocating memory
    infix_arr = (char*) calloc(size, sizeof(char));
    fgets(infix_arr, size, fptr);

    return infix_arr;
}
node* pushtop(node* top, node* newNode){
    newNode->next = top;
    top = newNode;
    return top;
}

char poptop(node** top){
    char key;
    node* temp;
    key = (*top)->key;
    temp = *top;
    *top = (*top)->next;
    free(temp);
    return key;
}

char* reverse_array(char* infix_arr){
    node* top,*newNode;
    int i;
    //Creating the stack
    top = (node*) malloc(sizeof(node));
    top->key = infix_arr[0];
    top->next = NULL;
    for(i = 1; i < strlen(infix_arr); i++){
        newNode = (node*)malloc(sizeof(node));
        newNode->key = infix_arr[i];
        top = pushtop(top, newNode);
    }
    //Reversing the content of the array
    for(i = 0; i < strlen(infix_arr); i++){
        infix_arr[i] = poptop(&top);
    }
    return infix_arr;
}

node* create_fill_node(char ch){
	node* NewNode;
	
	NewNode=(node*)malloc(sizeof(node));
	NewNode->key=ch;
	NewNode->next=NULL;
	return(NewNode);
}


char* infix_prefix(char* infix_arr, char* prefix_arr){
	int prefix_arr_size = 0, i, j = 0;
	char popped_char, ch;
	node* top=NULL, *NewNode;

    //to calculate the size of the prefix_arr
	for(i = 0; i < strlen(infix_arr); i++){
        if(infix_arr[i] != ')' && infix_arr[i] != '(' && infix_arr[i] != ']' && infix_arr[i] != '['){
            prefix_arr_size ++;
        }
	}

	//Allocating memory for prefix_arr
	prefix_arr = (char*)calloc(prefix_arr_size, sizeof(char));


	for(i = 0; i < strlen(infix_arr); i++){
		ch = infix_arr[i];
		if(isalpha(ch) != 0){
            prefix_arr[j++] = ch;
        }

		else if(ch == ')'){
			      NewNode=create_fill_node(ch);
            top=pushtop(top,NewNode);
		}

		else if (ch == '('){
			popped_char = poptop(&top);
			while (popped_char != ')'){
				prefix_arr[j++] = popped_char;
				popped_char = poptop(&top);
			}
	   	}
		else{
			if(top == NULL || priority(top->key) < priority(ch)){
               NewNode=create_fill_node(ch);
               top=pushtop(top,NewNode);
			}
			else{
				while (top != NULL){
					if(priority(top->key)<priority(ch) || top->key ==')'){
                        break;
					}
					else{
                        prefix_arr[j++] = poptop(&top);
					}

				}
				 NewNode=create_fill_node(ch);
                 top=pushtop(top,NewNode);
		    }
      	 }
	}
    //Last pop all remaining characters in the stack
    while(top != NULL){
        prefix_arr[j++] = poptop(&top);
    }
    prefix_arr[j] = '\0';
    prefix_arr = reverse_array(prefix_arr);
    return prefix_arr;
}




int priority(char value){
	if(value== ')' || value== '(')
	return(0);

	else if(value== '+' || value== '-')
	return(1);

	else if(value== '*' || value== '/')
	return(2);
}
