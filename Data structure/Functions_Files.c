#include<stdio.h>
#include<string.h>

typedef struct student_info{
int ID; 
char Name[50];
char Major[100];
}student_info;


void menu(void){

       printf("\n\t\t-------- Menu TO Use--------\n"); 
       printf("\n\t\t1. Fill Array\n");
	printf("\n\t\t2. View Array Content\n"); 
	printf("\n\t\t3. Sort Students by Major\n");
	printf("\n\t\t4. Print Computer Science students\n");
	printf("\n\t\t5. QUIT\n");
	printf("\n\t\t----------------------------\n");
	printf("\n\t\tYour choice:");
}
int filling(student_info student_array[30]){
       FILE *fptr;
       char ch;
       int i=0;
       char line[30];
       fptr=fopen("Students_data.txt","r");
       if(fptr==NULL){
       printf("Couldn't read file");
       }
       else{
              while(!feof(fptr)){
                     fscanf(fptr,"%d",&student_array[i].ID);
                     ch=getc(fptr);
                     fgets(student_array[i].Name,50,fptr);
                     fgets(student_array[i].Major,100,fptr);
                     fscanf(fptr,"%s",line);
                     i++;
              }
       }
       fclose(fptr);
       return i;
}
int printing(int i,student_info student_array[30]){
       for(int j=0;j<i;j++){
              printf("\n\t\t %d\n%s \n%s",student_array[j].ID,student_array[j].Name,student_array[j].Major);
       }
       return 0;
}
void sort(int i,student_info student_array[30],student_info temp[1]){
       int index_max,index_min,j=0;
       for(j=0;j<i;j++){
       index_max=j;
       index_min=index_max;
              for(int z=i;z<i;z++){
                     if(student_array[j].Major[0]>student_array[index_max].Major[0])
                     index_max=j;
              }
       if(index_max!=index_min){
              temp[0]=student_array[j];
              student_array[j]=student_array[index_max];
              student_array[index_max]=temp[0];
       }
       }
       //temp[0]='\0';
}
void display(int i,student_info student_array[30]){
       FILE *file=fopen("Computer Science.txt","a");
       for(int j=0;j<i;j++){
              if(strcmp("Computer Science\n",student_array[j].Major)==0)
                     fprintf(file,"%d\n%s%s----------------------------\n",student_array[j].ID,student_array[j].Name,student_array[j].Major);
              
       }
       fclose(file);
}
int main(void){
int i;
int choice; 
student_info student_array[30],temp[1];
       do{
       menu(); 
       scanf("%d",&choice); 
       switch(choice){
	case 1:
              i=filling(student_array);
	       break;
       case 2:
              printing(i,student_array);
       break;
       case 3:
              sort(i,student_array,temp);
       break;
	case 4:
       display(i,student_array);
       break;
	case 5:printf("\n\t\tTake care!\n\n\t\t");
       break;
       default: printf("\n\t\tSorry That was an INVALID Choice!\n");
	}
}while(choice!=5);
}

//Call a function that will 
//produce files Named by major
//example "Computer Science.txt" 
//will contain only students Names(also IDs)
//majoring in Computer Science