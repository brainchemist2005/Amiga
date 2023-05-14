typedef struct tag{
	char student_name[20];
	double student_gpa;
	struct tag* left;
	struct tag* right;
}node;
	
		
			
node* create_tree(node* root, char* file_name){
	node* tree_node;
	int i, count=0;
	FILE* infp;
	char ch;
	strcat(file_name,".txt");
	infp = fopen(file_name, "r");
	if(infp == NULL)
	printf("Failure to open the file");
	else{
		do{
			//count number of students
			ch = getc(infp);
			if(ch == '\n' || ch == EOF)
			count++;
		}while(ch != EOF);
		fseek(infp, 0, 0);
		for(i=0; i<count; i++){
			//Allocating memory
			tree_node = (node*)malloc(sizeof(node));
			fscanf(infp,, "%lf", &tree_node->student_gpa);
			tree_node->left = NULL;
			tree_node->right = NULL;
			//Add node to the tree
			root = add_student(root, tree_node);
		}
		fclose(infp);
	}
	return(root);
}
