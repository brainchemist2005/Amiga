//Push stack element using an array
int push_element_stack(int* stack, int size, int element, int* top){
	if((*top) == size-1)
	return(0);
	else {
		stack[++(*top)] = element;
		return(1);
	}
}

////Push stack element using a linked list
void push_element_stack(stack_node** top, stack_node* new_node){
	new_node->next = *top;
	(*top) = new_node;
}
