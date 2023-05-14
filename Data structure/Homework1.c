#include<stdio.h>

void Menu(void){

printf("\n\t\t------------- Menu TO Use -----------------\n"); 
printf("\n\t\t 1.Fill Arrays\n");
printf("\n\t\t 2.Display Arrays Content\n");
printf("\n\t\t 3.Search For a Student Number of Vaccines\n");
printf("\n\t\t 4.Sorting\n");
printf("\n\t\t 5.Quit\n");
printf("\n\t\t Your choice please:");
}
void fill_arrays(int arr_IDs[30],int arr_Vaccine[30], int N){
int i;
for(int i=0;i<N;i++){
    printf("\n\t\tInput students ID:");
    scanf("%d",&arr_IDs[i]);
    printf("\n\t\tInput students number of vaccines:");
    scanf("%d",&arr_Vaccine[i]);
}
}
void display_arrays_content(int arr_IDs[30],int arr_Vaccine[30],int N){
    int i;
    for(i =0;i<N;i++){
        printf("\n\t\t%d got %d vaccinations\n",arr_IDs[i],arr_Vaccine[i]);
        printf("\n\t\t-----------------------\n");
    }
}
int search_student_number_vaccines(int arr_IDs[30],int arr_Vaccine[30],int N,int ID){
    for(int p=0;p<N;++p){
    if(arr_IDs[p]==ID){
        return p;
    }
    }
}

int main(void){
    int flag =0;
    int arr_IDs[30];
    int arr_Vaccine[30]; 
    int ID,j;
    int choice,n_students;   
    int p;
do{
    
    Menu();
    scanf("%d",&choice);
    
    switch(choice){

    case 1: printf("Enter the number of students:\n");
    scanf("%d",&n_students);
    fill_arrays(arr_IDs,arr_Vaccine,n_students);
    flag = 1;
	    break;
    case 2: if(flag==0)
        printf("\n\t\tFILL ARRAYS FIRST!\n");
        else 
        display_arrays_content(arr_IDs,arr_Vaccine,n_students);
	    break;
    case 3: 
    printf("\n\t\tEnter an ID: ");
    scanf("%d",&ID);
    if(flag==0)
    printf("\n\t\tFILL ARRAYS FIRST!\n");
    else {
    p=search_student_number_vaccines(arr_IDs,arr_Vaccine,n_students,ID);
    printf("\n\t\t%d got %d",arr_IDs[p],arr_Vaccine[p]);
    }
	    break;
    case 4: 
	    break;
    case 5:printf("\n\t\tDone!\n\n\t"); 
	    break;
    default:printf("\n\t\tSORRY! That was a WRONG choice!\n");
    }
}while(choice!=5);

return(0);
}