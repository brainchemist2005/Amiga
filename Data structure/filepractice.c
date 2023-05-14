#include<stdio.h>
#include<string.h>
typedef struct info{
    char name[50];
    int birth;
    char sex[10];
    char status[20];
    int age;
}info;
int main(){
    info p1[100];
    char line[11];
    int i=0;
    FILE *fp=fopen("Deleteme.txt","r");
    if(fp==NULL){
        printf("Couldn't open the file");
    }
    else{
        while(!feof(fp)){
        fgets(p1[i].name,30,fp);
        fscanf(fp,"%d\n",&p1[i].birth);
        fgets(p1[i].sex,10,fp);
        fgets(p1[i].status,20,fp);
        fgets(line,10,fp);
        i++;
    }
    fclose(fp);
    for(int j=0;j<i-1;j++){
        p1[j].age=2022-p1[j].birth;
        printf("%s is %d years old ",p1[j].name,p1[j].age);
    }
    FILE *file=fopen("Deleteme.txt","w");
    for(int j=0;j<i-1;j++){
    fprintf(file,"%s\n%d\n%s\n%s\n%s\n---------------------------\n",p1[j].name,p1[j].age,p1[j].birth,p1[j].sex,p1[j].status);
    }
    fclose(file);
    }
    return 0;
}