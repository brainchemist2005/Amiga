#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int push(char*stack,int*top,char ToPush,int size){

  if(*top==size-1)
    return(0);
  else{
    stack[++(*top)]=ToPush;
    return(1);
  }
}
char pop(char*stack,int*top){

  if(*top==-1)
    return('$'); 
  else
  {
    
  return(stack[(*top)--]);  
  }
}
int check_balanced_expression(char*stack,int top,int size,char*expression)
{
  char c,ch;
  int i =0;

  while(c != '\0')
  {
    c = expression[i];
    if(c == '(' || c == '{' || c == '[')
    push(stack,&top,c,size);

    else if(c == ')' || c == '}' || c == ']')
    ch = pop(stack,&top);

    if(ch == '$')
    return 0;

    else if(c == ')' && ch != '(')
    return 0;

    else if(c == ']' && ch != '[')
    return 0;

    else if(c == '}' && ch != '{')
    return 0;

  }
  return 1;
}
void Load_Expression_File_Array(FILE*infp, char*expression){
  
  //This function will be used to load the expression 
  //in the file to the expression array

}
int Compute_Size_Infix(FILE*infp){
  int cnt=0;
  char ch;
  
  do{
    ch=getc(infp);
    cnt++;
  }while(ch!=EOF);
  
  return(cnt);
}
int Compute_Size_Stack1(char*infix_expression){
  int i=0,cnt=0; 
  char ch;
  while(infix_expression[i]!='\0')
  {
    ch=infix_expression[i++];	
    if(ch=='(' || ch=='[')
    cnt++;
  }
  return(cnt); 
}
int Compute_Size_Stack2(char*infix_expression){
  int i=0,cnt=0; 
  char ch;
  while(infix_expression[i]!='\0')
  {
  ch=infix_expression[i++];	
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    cnt++;
  }
  return(cnt); 
}
void Menu(void){
  
  printf("\n\t\t------------------- MENU-------------------\n");
  printf("\n\t\t1.Check if a Math Expression is Balanced\n");
  printf("\n\t\t2.Convert infix to postfix (expression without()[])\n");
  printf("\n\t\t3.Convert infix to postfix (expression with()[])\n");
  printf("\n\t\t4.Execute Postfix Expression\n");
  printf("\n\t\t5.QUIT\n");
  rintf("\n\t\t--------------------------------------------\n");
  printf("\n\t\tYour choice please:");
}char check_top_stack(char*stack,int top){

   //This function should return the character
   //on the top of the stack
   //You should not pop it
   //Warnnig:stack can be empty

}
int priority(char ch){

  if(ch=='*' || ch=='/')
    return(2);
  else if(ch=='+' || ch=='-')
    return(1);
  else
    return(0);
}
void convert_infix_postfix_no_parentheses(char*infix_expression,char*postfix_expression,char*stack,int top,int stack_size){
// This is the first algorithm we discussed in class
  
    int i,j=0; 
    char ch, char_top_stack, popped_char;

    for(i=0;i<strlen(infix_expression);i++)
    {
      ch=infix_expression[i];	
	  if(ch=='+' || ch=='-' || ch=='/' || ch=='*' )
	    { 
		if(top==-1)
	      push(stack,&top,ch,stack_size);
        else{
          char_top_stack=check_top_stack(stack,top);        	
		  while ((priority(char_top_stack)>= priority(ch)) && top!=-1)
		    {
            popped_char= pop(stack,&top);
	          postfix_expression[j++]=popped_char;
			      char_top_stack=check_top_stack(stack,top);			
			}
			push(stack,&top,ch,stack_size);		
		  }			
	    }
      else
	   	 postfix_expression[j++]=ch;
	}
    while(top!=-1)
    postfix_expression[j++]=pop(stack,&top);

    postfix_expression[j]='\0';
}
int main (void){

  char*stack,*infix_expression,*postfix_expression;
  FILE*infp; 
  int stack_size,infix_size,status,choice,top=-1;

  infp=fopen("expression.txt","r");

  if(infp==NULL)
  printf("\n\t\tCould NOT open the FILE!\n\n\t\t");
  else{
  infix_size=Compute_Size_Infix(infp);
  infix_expression = (char*)calloc(infix_size,sizeof(char));
  Load_Expression_File_Array(infp,infix_expression); //Define the function up
  printf("\n\t\tYour file has the following expression:%s\n",infix_expression);
  do{
  Menu();
  scanf("%d",&choice);
  switch(choice){
  
  case 1:stack_size=Compute_Size_Stack1(infix_expression);
        stack = (char*)calloc(stack_size,sizeof(char));
        status=check_balanced_expression(stack,top,stack_size,infix_expression);
        if(status==0)
        {
          	printf("\n\t\t%s is not a Balanced Expression!\n",infix_expression);
          	printf("\n\t\tSORRY, Your program will TERMINATE NOW!\n\n\t\t");
            	return;		   
	      }
        else{
		    printf("\n\t\t%s is a Balanced Expression!\n",infix_expression);
		    free(stack);
			break;
		  }
  case 2:stack_size=Compute_Size_Stack2(infix_expression);
        stack= (char*)calloc(stack_size,sizeof(char)); 
        postfix_expression=(char*)calloc(infix_size,sizeof(char));
		convert_infix_postfix_no_parentheses(infix_expression,postfix_expression,stack,top,stack_size);
        printf("\n\t\t%s converted to postfix:%s\n",infix_expression, postfix_expression);		 
		free(stack);         
        break;
  case 3://Here you need to call a function that 
         //Implements the second algorithm we discussed in class
         //The algorithm is the following: 
        /*
		Read character by character:
		If it is a operand then write it to postfix
		If it is a left parenthesis then push it on stack
		If it is an operator:
			If the top of the stack is an operator of �lower� priority OR the stack is empty then push the operator on the stack
			Else, as long as the stack is not empty, pop all operators from the stack � till encountering an operator of lower priority (strictly less) OR till a left parenthesis is encountered / this later should not be popped - and write them to postfix; then push the read operator onto stack 
			NB: The parenthesis is of less priority than operators
		Else if it is a right parenthesis:
			Pop all operators till a left parenthesis is popped and write them to the output� Do not write parentheses to postfix
		When all characters are read, pop the remaining operators and write them to postfix
		 */
        break;
  case 4://Here you need to call a function that 
         //evaluate the postfix expression: found in the array: postfix_expression
         //Not that the stack used in this case should hold numbers: double!
         //a different push and pop functions are needed
        /*The algorihtm to use is the following:
		Use the postfix expression: character by character
		IF a number then push it on stack
		Else if an operator
		Pop 2 numbers from stack
		Apply the operator to the 2 numbers 
		Push the result in the stack
		 */
         //BEST of LUCK
        break;
  case 5: printf("\n\t\tYou are Quitting....\n\t\tBye");
          break;
  default:printf("\n\t\tWrong CHOICE!\n");
}//Close of Switch
}while(choice!=5);
}
return(0);
}
