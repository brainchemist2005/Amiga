printf("input the size of your array");
scanf("%d", &stack_size);
stack = (int*)calloc(stack_size, sizeof(int));








//File cases :(
FILE* infp;
infp = fopen(".txt","r");
if(infp == NULL)
printf("Could not open the File");
else{
	printf("Ur math exp is: ");
	do{
		ch = getc(infp);
		printf("%c", ch);
		if
		size++;
	}while(ch != EOF);
	fseek(infp,0,0);
	stack = (char*)calloc(size, sizeof(char));
}
