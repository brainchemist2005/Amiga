//Enqueue using an array 
int enqueue(char** clients, int size, int* rear, char* name){
	if((*rear) == size)
	return(0);
	else{
		strcpy(clients[(*rear)], name);
		return(1);
	}
}


////Enqueue using a linked list
void enqueue_client(q_node** head, q_node* toEnqueue){
	q_node* walker;
	if(*head == NULL)
	*head = toEnqueue;
	else{
		walker = *head;
		while(walker->next != NULL)
		walker = walker->next;
		walker->next = toEnqueue;
	}
}
