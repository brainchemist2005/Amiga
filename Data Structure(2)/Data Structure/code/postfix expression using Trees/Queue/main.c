>
<

//intialize rear and front to 0 in the main
rear = 0;
front = 0;


//Ask for the queue size
printf("input the size of the queue: ");
scanf("%d", &size);


//Allocate memory for the array
clients_names = (char**)calloc(size, sizeof(char*));
for(i=0; i<size; i++)
clients_names[i] = (char*)calloc(20, sizeof(char));
