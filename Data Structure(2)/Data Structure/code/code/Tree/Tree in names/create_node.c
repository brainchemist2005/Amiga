//To Create a Node
node* create_node(){
    node* n;
    char ch;
    scanf("%c",&ch);
    n = (node*)malloc(sizeof(node));
    printf("input student name: ");
    gets(n->student_name);
    printf("input student gpa: ");
    scanf("%lf", &n->student_gpa);
    n->left=NULL;
    n->right=NULL;
    return(n);
}
