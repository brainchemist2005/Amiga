//Display stack element using an array
int display_stack_elements(int* stack, int top){
	int i;
	if(top == -1)
	return(0);
	else{
		printf("The stack contains the following numbers: ");
		for(i=top; i>=0; i++)
		printf("%d", stack[i]);
	}
}

//Display stack element using a linked list
int display_stack_element(stack_node* top){
	stack_node* walker;
	if(top == NULL)
	return(0);
	else{
		printf("The stack contains the following numbers: ");
		walker = top;
		while(walker != NULL){
			printf("%d", walker->element);
			walker = walker->next;
		}
	}
}
