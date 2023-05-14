#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



int push(char*stack,int*top,char ToPush,int size){

  if(*top==size)
  {
    return(0);
  }
  else{
    stack[++(*top)]=ToPush;
    return(1);
  }
}
char pop(char*stack,int*top){

  if(*top==-1)
  return('$'); 
  else{
    
  return(stack[(*top)--]);  
  }
}
int check_balanced_expression(char*stack,int top,int size,char*expression){

int flag=0, i=0;
char popped_char;
int length_expression=strlen(expression);

  do{
  if(expression[i]=='(' || expression[i]=='[')
    push(stack,&top,expression[i],size);
  else if(expression[i]==')' || expression[i]==']'){
    popped_char=pop(stack,&top);
    if((expression[i]==')' && popped_char!='(') ||(expression[i]==']' && popped_char!='[')){
	  flag=1;
	  break;
	}
  }  
  i++;
  }while(i!=length_expression);

if(top==-1 && flag==0)
  return(1);//Balanced Expression
else 
  return(0);
}
void Load_Expression_File_Array(FILE*infp, char*expression){
int i=0;
char ch; 
fseek(infp,0,0);

  while(!feof(infp))
  {
    fscanf(infp,"%c",&expression[i]);
    i++;
  }
  strtok(expression,"\n");

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
  printf("\n\t\t--------------------------------------------\n");
  printf("\n\t\tYour choice please:");
}
char check_top_stack(char*stack,int top){
  if(top==-1)
    return('@');//Means stack has no element
  else
    return(stack[top]); 
}
int priority(char ch){

  if(ch=='*' || ch=='/')
    return(2);
  else if(ch=='+' || ch=='-')
    return(1);
  else if(ch == '(' || ch == ')')
    return(0);
}
void convert_infix_postfix_no_parentheses(char*infix_expression,char*postfix_expression,char*stack,int top,int stack_size){
  
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

void convert_infix_postfix_parentheses(char*infix_expression,char*postfix_expression,char*stack,int top,int stack_size)
{
  char ch,c,popped,char_top;
  int i,j=0,m;
  for(i=0 ; i<strlen(infix_expression) ; i++)
  {
    ch = infix_expression[i];

    if(isalpha(ch) == 0)
    {
      if(top == -1 || ch == '(')
        push(stack,&top,ch,stack_size);

      else if(ch != ')')
      {
        char_top = check_top_stack(stack,top);
      while(priority(char_top) >= priority(ch) && top != -1)
      {
        popped = pop(stack,&top);
        postfix_expression[j++] = popped;
        char_top = check_top_stack(stack,top); 
      }
      push(stack,&top,ch,stack_size);
    
      }
      else
        {
          c = pop(stack,&top);
          while(top != -1 && c != ')')
          {
            if(c == '(')
            break;
            postfix_expression[j++] = c;
            c = pop(stack,&top);
          }
        }
    }
    else 
    {
      postfix_expression[j++] = ch;
    }

  }

  while(top != -1)
  {
    c = pop(stack,&top);
    if(c != '(')
    postfix_expression[j++] = c;
  }

  postfix_expression[j] = '\0';

}
int push1(double *stack1,double topush,int *top,int size)
{
  if(*top == size)
    return -1;

  else
    {
      stack1[++(*top)] = topush;
      return 1;
    }
}

double pop1(double*stack,int *top)
{
  if(*top == -1)
    return -1;

  else
    return stack[(*top)--];
}

double evaluate(char*postfix_expression,double*stack,int top,int size)
{
  int i,j=0;
  double value,A,B;
  char ch;

  for(i=0 ; i<strlen(postfix_expression) ; i++)
  {
    ch = postfix_expression[i];
    if(isalpha(ch) != 0)
    {
      printf("\n\t\tEnter the value of %c: ",ch);
      scanf("%lf",&value);
      push1(stack,value,&top,size);
    }
    else
    {
      B = pop1(stack,&top);
      A = pop1(stack,&top);
      if(ch == '+')
        value = A + B;
      else if(ch == '-')
        value = A - B;

      else if(ch == '*')
        value = A * B;
      
      else 
        value = A / B;

      push1(stack,value,&top,size);

    }
  }

  return pop1(stack,&top);
}


int main (void)
{
  char*stack,*infix_expression,*postfix_expression;
  FILE*infp; 
  int stack_size,infix_size,status,choice,top=-1;
  double result,*stack1;

  infp=fopen("Expression.txt","r");

  if(infp==NULL)
  printf("\n\t\tCould NOT open the FILE!\n");
  else{
  infix_size=Compute_Size_Infix(infp);
  infix_expression = (char*)calloc(infix_size,sizeof(char));
  Load_Expression_File_Array(infp,infix_expression);
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
          	return 0;		   
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
  case 3:
    stack_size=Compute_Size_Stack1(infix_expression);
    stack= (char*)calloc(stack_size,sizeof(char)); 
    postfix_expression=(char*)calloc(infix_size,sizeof(char));
    convert_infix_postfix_parentheses(infix_expression,postfix_expression,stack,top,stack_size);
    printf("\n\t\t%s",postfix_expression);
        break;
  case 4:
        //Here you need to call a function that 
         //evaluate the postfix expression: found in the array: postfix_expression
         //Not that the stack used in this case should hold numbers: double!
         //a different push and pop functions are needed
         //BEST of LUCK
      stack1 = (double*)calloc(stack_size,sizeof(double));
      result = evaluate(postfix_expression,stack1,top,stack_size);

      printf("\n\t\tThe result is %.2lf",result);

        break;
  case 5: printf("\n\t\tYou are Quitting....\n\t\tBye");
          break;
  default:printf("\n\t\tWrong CHOICE!\n");
}//Close of Switch
}while(choice!=5);
}
  return 0;
}
