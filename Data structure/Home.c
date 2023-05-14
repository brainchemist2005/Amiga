#include<stdio.h>
#include<string.h>

typedef struct{
int Year; 
int Month; 
int Day;
char zodiac_sign[20];
}birthday_info;

typedef struct{
    char name[20]; 
    birthday_info b_date;  
}user_info;

void zodiac(user_info arr[28],int n_users){
    for(int i=0;i<n_users;i++){
        if((arr[i].b_date.Day>=23) || (arr[i].b_date.Day<=23) ){
            if(arr[i].b_date.Month==3 || arr[i].b_date.Month==4)
            strcpy(arr[i].b_date.zodiac_sign,"Arries");
        }
        if((arr[i].b_date.Day>=21) || (arr[i].b_date.Day<=20)){
            if(arr[i].b_date.Month==11 || arr[i].b_date.Month==12)
            strcpy(arr[i].b_date.zodiac_sign,"Gemini");
        }
        if(arr[i].b_date.Day>=23  || arr[i].b_date.Day<=22 ){
            if(arr[i].b_date.Month==7||arr[i].b_date.Month==8)
            strcpy(arr[i].b_date.zodiac_sign,"Leo");
            else if(arr[i].b_date.Month==9||arr[i].b_date.Month==10)
            strcpy(arr[i].b_date.zodiac_sign,"Libra");
            else if(arr[i].b_date.Month==8||arr[i].b_date.Month==9)
            strcpy(arr[i].b_date.zodiac_sign,"Virgo");
        }
        if((arr[i].b_date.Day>=22 ) || (arr[i].b_date.Day<=11) ){
            if(arr[i].b_date.Month==11 || arr[i].b_date.Month==12)
            strcpy(arr[i].b_date.zodiac_sign,"Sagittarius");
        }
        if((arr[i].b_date.Day>=20) || (arr[i].b_date.Day<=18)){
            if(arr[i].b_date.Month==1 || arr[i].b_date.Month==2)
            strcpy(arr[i].b_date.zodiac_sign,"Aquarius");
        }
        if((arr[i].b_date.Day>=20) || (arr[i].b_date.Day<=20) ){
            if(arr[i].b_date.Month==4 || arr[i].b_date.Month==5)
            strcpy(arr[i].b_date.zodiac_sign,"Taurus");
        }
        if((arr[i].b_date.Day>=21 ) || (arr[i].b_date.Day<=22 ) ){
            if(arr[i].b_date.Month==6 || arr[i].b_date.Month==7)
            strcpy(arr[i].b_date.zodiac_sign,"Cancer");
        }
        if(arr[i].b_date.Day>=23 || arr[i].b_date.Day<=21 ){
            if(arr[i].b_date.Month==10 || arr[i].b_date.Month==11)
            strcpy(arr[i].b_date.zodiac_sign,"Scorpio");
        }
        if((arr[i].b_date.Day>=22 ) || (arr[i].b_date.Day<=19 ) ){
            if(arr[i].b_date.Month==12 || arr[i].b_date.Month==1)
            strcpy(arr[i].b_date.zodiac_sign,"Capricorn");
        }
        if(arr[i].b_date.Day>=19 || arr[i].b_date.Day<=20 ){
            if(arr[i].b_date.Month==2 || arr[i].b_date.Month==3)
            strcpy(arr[i].b_date.zodiac_sign,"Pisces");
        }
    }
}
void Menu(void){

    printf("\n\t\t------------- Menu TO Use -----------------\n"); 
    printf("\n\t\t 1.Fill Array\n");
    printf("\n\t\t 2.Display Array Content\n");
    printf("\n\t\t 3.Get the birthday of a person\n");
    printf("\n\t\t 4.Same Zodiac Sign\n");
    printf("\n\t\t 5.Quit\n");
    printf("\n\t\t Your choice please:");
}
void filling(user_info arr[28], int n_users){
    int i;
    for(i=0;i<n_users;i++)
    {
        getchar();
        printf("\n\t\tInput the name of the user: ");
        gets(arr[i].name);
        printf("\n\t\tInput the day of the birth: ");
        scanf("%d",&arr[i].b_date.Day);
        printf("\n\t\tInput the month of the birth: ");
        scanf("%d",&arr[i].b_date.Month);
        printf("\n\t\tInput the year of the birth: ");
        scanf("%d",&arr[i].b_date.Year);
        zodiac(arr,n_users);
    }
}
void displaying(user_info arr[28], int n_users){
    for(int i=0;i<n_users;i++){
    printf("\n\t\t%s\t%d/%d/%d",arr[i].name,arr[i].b_date.Day,arr[i].b_date.Month,arr[i].b_date.Year);
    }
}
void searching(user_info arr[28],int n_users,char ToSearch[30]){
    int flag=0;
    for(int i=0;i<n_users;i++){
        if(strcmp(ToSearch,arr[i].name)==0){
            flag=1;
        printf("\n\t\t%s\t%d/%d/%d",arr[i].name,arr[i].b_date.Day,arr[i].b_date.Month,arr[i].b_date.Year);
        break;
        }
    }
    if(flag == 0 ){ 
        printf("\n\t\tUser not found! ");
    }
}
void classification(user_info arr[28],int n_users){
    for(int i=0;i<n_users;i++){
        for(int j=i+1;j<n_users;j++){
        if(strcmp(arr[i].b_date.zodiac_sign,arr[j].b_date.zodiac_sign)==0){
            printf("\n\t\t%s and %s are %s",arr[i].name,arr[j].name,arr[j].b_date.zodiac_sign);
        }
        }
    }
}
int main(void){

user_info arr[28];
int choice,n_users,flag;
char ToSearch[30];

do{
    
    Menu();
    scanf("%d",&choice);
    
    switch(choice){
    
    case 1:printf("\n\t\tInput tne number of users: ");
    scanf("%d",&n_users);
        filling(arr,n_users);
	    break;
    case 2:displaying(arr,n_users);
	    break;
    case 3:getchar();
    printf("\n\t\tInput the name of the user  you are searching for: ");
    gets(ToSearch);
    searching(arr,n_users,ToSearch);
    if(flag == 1){
                printf("\n\t\tNot found");
    }
	    break;
    case 4: classification(arr,n_users);
	    break;
    case 5:printf("\n\t\tDone!\n\n\t"); 
	    break;
    default:printf("\n\t\tSORRY! That was a WRONG choice!\n");
    }
}while(choice!=5);

return(0); 
}
#include<stdio.h>
#include<string.h>

typedef struct{
int Year; 
int Month; 
int Day;
}birthday_info;

typedef struct{
    char name[20]; 
    birthday_info b_date;  
}user_info;


void Menu(void){

    printf("\n\t\t------------- Menu TO Use -----------------\n"); 
    printf("\n\t\t 1.Fill Array\n");
    printf("\n\t\t 2.Display Array Content\n");
    printf("\n\t\t 3.Get the birthday of a person\n");
    printf("\n\t\t 4.To Discuss\n");
    printf("\n\t\t 5.Quit\n");
    printf("\n\t\t Your choice please:");
}
void filling(user_info arr[28], int n_users){
    int i;
    for(i=0;i<n_users;i++)
    {
        getchar();
        printf("\n\t\tInput the name of the user: ");
        gets(arr[i].name);
        printf("\n\t\tInput the day of the birth: ");
        scanf("%d",&arr[i].b_date.Day);
        printf("\n\t\tInput the month of the birth: ");
        scanf("%d",&arr[i].b_date.Month);
        printf("\n\t\tInput the year of the birth: ");
        scanf("%d",&arr[i].b_date.Year);
    }
}
void displaying(user_info arr[28], int n_users){
    for(int i=0;i<n_users;i++){
    printf("\n\t\t%s\t%d/%d/%d",arr[i].name,arr[i].b_date.Day,arr[i].b_date.Month,arr[i].b_date.Year);
    }
}
void searching(user_info arr[28],int n_users,char ToSearch[30]){
    int flag=0;
    for(int i=0;i<n_users;i++){
        if(strcmp(ToSearch,arr[i].name)==0){
            flag=1;
        printf("\n\t\t%s\t%d/%d/%d",arr[i].name,arr[i].b_date.Day,arr[i].b_date.Month,arr[i].b_date.Year);
        break;
        }
    }
    if(flag == 0 ){ 
        printf("\n\t\tUser not found! ");
    }
}
int main(void){

user_info arr[28];
int choice,n_users,flag;
char ToSearch[30];

do{
    
    Menu();
    scanf("%d",&choice);
    
    switch(choice){
    
    case 1:printf("\n\t\tInput tne number of users: ");
    scanf("%d",&n_users);
        filling(arr,n_users);
	    break;
    case 2:displaying(arr,n_users);
	    break;
    case 3:getchar();
    printf("\n\t\tInput the name of the user  you are searching for: ");
    gets(ToSearch);
    searching(arr,n_users,ToSearch);
    if(flag == 1){
                printf("\n\t\tNot found");
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
