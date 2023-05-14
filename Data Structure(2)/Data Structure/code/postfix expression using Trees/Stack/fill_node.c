typedef struct node{
	int element;
	struct node* next;
}stack_node;


stack_node* fill_node(){
	stack_node* new_node;
	new_node = (stack_node*)malloc(sizeof(stack_node));
	printf("input the node number: ");
	scanf("%d", &new_node->element);
	new_node->next = NULL;
	return(new_node);
}
