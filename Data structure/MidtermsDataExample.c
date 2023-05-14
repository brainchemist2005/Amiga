#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//Define structure
typedef struct tag{
char name[20];
int age;
struct tag*next;
}node;



//User defined Functions
void traverseLL(node*head){
node*walker;
printf("\nThis is the content of LL:\n");
//Print LL
walker=head;
while(walker!=NULL){
printf("%s %d\n",walker->name,walker->age);
walker=walker->next;
}
}

node* Add_Node_LL(node*head,node*ToAdd){
node*walker;
//LL is EMPTY
if(head==NULL)
head=ToAdd;
else// LL must have at least a node
{
walker=head;
while(walker->next!=NULL)
walker=walker->next;
walker->next=ToAdd;
}
return(head);
}
node* create_fill_node(void){
node*newNode;
//Allocate Memory
newNode=(node*)malloc(sizeof(node));
//Fill the elements
printf("Input student name:");
scanf("%s",newNode->name);
printf("Input student age:");
scanf("%d",&newNode->age);
newNode->next=NULL;
// return the created node
return(newNode);
}
int main(void){

node*head,*newNode;
char answer;

//Step1
head=NULL;

do{
//Step2
newNode= create_fill_node();
//Step3
head=Add_Node_LL(head,newNode);
printf("Add another node? Y/N:");
scanf(" %c",&answer);
}while(answer!='N');
traverseLL(head);
return(0);
}