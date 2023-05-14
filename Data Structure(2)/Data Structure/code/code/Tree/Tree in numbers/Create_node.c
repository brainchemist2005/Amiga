//To Create a Node
node* create_node(){
    node* n;
    n = (node*)malloc(sizeof(node));
    n->left=NULL;
    n->right=NULL;
    return(n);
}
