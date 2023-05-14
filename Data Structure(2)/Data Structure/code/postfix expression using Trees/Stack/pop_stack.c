//Pop stack element using an array
int pop_element_stack(int* stack, int* top){
	int value;
	if((*top)==-1)
	return(-1);
	else{
		value = stack[(*top)--];
		return(value);
	}
}

////Pop stack element using a linked list
stack_node* pop_element_stack(stack_node** top){
	stack_node* temp;
	if((*top) == NULL)
	return(NULL);
	else{
		temp = *top;
		*top = (*top)->next;
		return(temp);
	}
}
