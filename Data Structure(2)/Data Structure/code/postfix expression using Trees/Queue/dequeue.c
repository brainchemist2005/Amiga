//Dequeue using an array
char* dequeue(char** clients, int front, int* rear){
	char ToReturn[20];
	int i;
	if((*rear) == 0)
	strcpy(ToReturn, "none");
	else{
		stcpy(ToReturn, clients[front]);
		//shifting elements backward
		for(i=front+1; i<(*rear); i++)
		strcpy(clients[i-1], clients[i]);
		(*rear)--; //reduce size by 1
	}
}


////Dequeue using a linked list
q_node* dequeue_client(q_node** head){
	q_node* temp;
	if(*head == NULL)
	temp = NULL;
	else{
		temp = *head;
		*head = (*head)->next;
	}
	return(temp);    //you need to free the temp in this case in the main // free(the variable you assigned lfunction here);
}
