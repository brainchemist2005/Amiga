#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student_info{
	int ID;
	char name[30];
	char courses[8][14];
}student_info;
typedef struct grades{
	char grade[7][4];
}grades;

void courseinfo(struct grades p2[6],int index,struct student_info p1[6]){
	int m=3,l=0,temp1,temp2;
	int codes[7][5];
	char temp[5];
	double PCP[7],GPA;
	for(int r=0;r<index+4;r++){
	for(int i=3;i<=6;i++){
	temp[l]=p1[index].courses[r][i];
	l++;
	}
	temp1= atoi(temp);
	codes[r][0]=(temp1/1000);
	temp2=temp1/100;
	codes[r][1]=(temp2%10);
	temp2=temp1/10;
	codes[r][2]=(temp2%10);
	codes[r][3]=(temp1%10);
	}
	printf("\n%d",codes);
	
	/*for(int z=0;z<index+4;z++){
	if(strcmp(p2[index].grade[z],"A+\n")==0||strcmp(p2[index].grade[z],"A\n")==0){
		PCP[]=code[z][1]*4;
	}
	else if(strcmp(p2[index].grade[z],"A-\n")==0){
		PCP[]=code[z][1]*3.67;
	}
	}*/
}

int searching(char names[20], student_info p1[6]){
	int flag=0;
	int j;
	for(j=0;j<4;j++){
		if(strcmp(p1[j].name,names)==0){
			printf("\n\t\tThe name exists");
			printf("\n\t\tFull name:%s ID:%d",p1[j].name,p1[j].ID);
			for(int z=0;z<j+4;z++){
				printf("\n\t\tCourse:%s",p1[j].courses[z]);
				flag=1;
			}
		}
	}
	if(flag==0){
		printf("\n\t\tNot found");
	}
	j=j-4;
	return j;
}
void menu(void){
    printf("\n\t\t-------- Menu TO Use--------\n"); 
    printf("\n\t\t1. View the content of the file\n");
	printf("\n\t\t2. Load the file data to an array\n"); 
	printf("\n\t\t3. Check if a student is in the array or not\n");
	printf("\n\t\t4. Compute the GPA for a student X\n");
	printf("\n\t\t5. QUIT\n");
	printf("\n\t\t---------------------------\n");
	printf("\n\t\tYour choice:");
}
int main(void){
	int index=0,i=0,choice,j,k=0;
	struct grades p2[4];
	struct student_info p1[6];
	char code[4][5],names[20],ch[17],a;
	FILE *fp=fopen("Data_student.txt","r");
	do{
    menu(); 
    scanf("%d",&choice); 
    switch(choice){
	case 1:
	for(int i=0;i<4;i++){
			printf("\n\t\t%s",p1[i].name);
			printf("\n\t\t%d",p1[i].ID);
			for(int z=0;z<i+4;z++){
			printf("\n\t\t%s %s",p1[i].courses[z],p2[i].grade[z]);
	}
	printf("\n\t\t%s",ch);
	}
	    break;
    case 2:
    	if(fp==NULL){
			printf("\n\t\tCouldn't read the file");
		}
		else{
			while(!feof(fp)){
			fscanf(fp,"%[^\n]\n",p1[i].name);
			fscanf(fp,"%d\n",&p1[i].ID);
			for(int z=0;z<i+4;z++){
			fscanf(fp,"%s",p1[i].courses[z]);
			a=fgetc(fp);
			fscanf(fp,"%s\n",p2[i].grade[z]);
			}
			fscanf(fp,"%[^\n]\n",ch);
			i++;
			}
		}
	fclose(fp);
    break;
    case 3:
	getchar();
	printf("\n\t\tEnter a name: ");
	gets(names);
	searching(names,p1);
    break;
	case 4:
	printf("\n\t\tEnter a name: ");
	getchar();
	gets(names);
	j=searching(names,p1);
	courseinfo(p2,j,p1);
    break;
	case 5:
	printf("\n\t\tTake care!\n\n\t\t");
    break;
    default: printf("\n\t\tSorry That was an INVALID Choice!\n");
	}
}while(choice!=5);
}