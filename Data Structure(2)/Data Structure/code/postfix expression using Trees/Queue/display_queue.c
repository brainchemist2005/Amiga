//Display queue using an array
void print_clients_queue(char** clients, int front){
	int i;
	if(rear == 0)
	printf("Queue is EMPTY");
	else{
		printf("Your waiting list are: or Your queue contains the following: ");
		for(i=front; i<rear; i++)
		printf("%s", clients[i]);
	}
}


//Display queue using a linked list
void print_clients_queue(q_node* head){
	q_node* walker;
	walker = head;
	if(walker == NULL)
	printf("Queue is EMPTY");
	else{
		printf("Clients in the queue:\n");
		printf("Client Name   \t   ID ");
		while(walker != NULL){
			printf("%s %d", walker->c_d.name, walker->c_d.ID);
			walker = walker->next;
		}
	}
}
