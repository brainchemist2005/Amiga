//initialize head to NULL in the main // head=NULL;

typedef struct{
	char name[20];
	int ID;
}client_data;

typedef struct node{
	client_data c_d;
	struct node* next;
}q_node;


q_node* fill_queue_node(){
	q_node* node1;
	node1 = (q_node*)malloc(sizeof(q_node));
	printf("Client name?");
	scanf("%s", node1->c_d.name);
	printf("Client ID?");
	scanf("%d", &node1->c_d.ID);
	node1->next = NULL;
	return(node1);
}
