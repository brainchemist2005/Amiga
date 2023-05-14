/*
***Homework1***
***Imane Jalal***
*/


#include<stdio.h>
#include<string.h>

//User defined data types

typedef struct
{
	char status;
	char check_in_date[11];
	char client_name[32];
	char identity_number[10];
	int room_number;
	int night_to_spend_number;

} Single_room;

typedef struct
{
	char status;
	char check_in_date[11];
	char client1_name[32];
	char client2_name[32];
	char identity_Client1_number[10];
	char identity_Client2_number[10];
	int room_number;
	int status_kid;
	int night_to_spend_number;

} Double_room;

typedef struct
{
	char status;
	char check_in_date[11];
	char client1_name[32];
	char client2_name[32];
	char identity_Client1_number[10];
	char identity_Client2_number[10];
	int room_number;
	int number_kids;        //Max 3
	int night_to_spend_number;

} Studio_room;




//Functions Prototypes

int Check_available_SR(Single_room SR[], int option);
int Check_available_DR(Double_room DR[], int option);
int Check_available_STR(Studio_room STR[], int option);
void menu(void);
void check_in_single(int index, Single_room SR[]);
int check_in_double(int empty_room, Double_room DR[]);
int check_in_studio(int empty_room, Studio_room STR[]);
void check_out_single(int index, Single_room SR[]);
void check_out_double(int index, Double_room DR[]);
void check_out_studio(int index, Studio_room STR[]);
int Hotel_Earnings();


//Main

int main()
{
    FILE * his;
    Single_room SR[5];
    Double_room DR[10];
    Studio_room STR[3];
    int N, i, index, d, empty_room, ans, kids, status;
	int choice, room_c;
    int earn;
	char ch;


	for(i = 1, index = 0; i <= 9; i+=2, index++){
        SR[index].room_number = i;
        SR[index].status = 'E';
	}
	for(i = 2, index = 0; i <= 20; i+=2, index++){
        DR[index].room_number = i;
        DR[index].status = 'E';
	}
    for(i = 33, index = 0; i <= 55; i+=11, index++){
        STR[index].room_number = i;
        STR[index].status = 'E';
	}
	printf("\t\t*       ------------------------------       *\n");
	printf("\t\t*            WELCOME TO AUI HOTEL            *\n");
	printf("\t\t*       ------------------------------       *\n");
	do{
        menu();
        scanf("%d",&choice);
        ans = 1;
        switch(choice){
        case 1:
            printf("Please enter the room type for which you want to know the availabilities (Choose a number):\n1- Single Room\n2- Double Room\n3- Studio Room\n==> ");
            scanf("%d", &N);
            if(N == 1){
                d = Check_available_SR(SR, 1);
            }
            else if(N == 2){
                d = Check_available_DR(DR, 1);
            }
            else if (N == 3){
                d = Check_available_STR(STR, 1);
            }
            else{
                printf("Invalid Inputs");
            }
            break;

        case 2:
            his = fopen("history.txt", "a");
            printf("Please enter the room type(Choose a number):\n1- Single Room\n2- Double Room\n3- Studio Room\n==> ");
            scanf("%d", &N);
            if(N == 1){
                empty_room = Check_available_SR(SR, 2);
                if(empty_room == -1){
                    printf("No available single rooms!\n");
                }
                else{
                    check_in_single(empty_room, SR);
                    fprintf(his, "Client Name: %s\nPartner: %s\nRoom Type: %s\nNumber of kids: %d\nNumber of Nights to spend: %d\nCheck in Date: %s\nPrice: %d %s\n", SR[empty_room].client_name, "None", "Single", 0, SR[empty_room].night_to_spend_number, SR[empty_room].check_in_date, 350 * SR[empty_room].night_to_spend_number, "MAD");
                    fprintf(his, "%s", "******************************************************************\n");
                }
            }
            else if(N == 2){
                empty_room = Check_available_DR(DR, 2);
                if(empty_room == -1){
                    printf("No available single rooms!\n");
                }
                else{
                    status = check_in_double(empty_room, DR);
                    if(status != 0){
                        fprintf(his, "Client Name: %s\nPartner: %s\nRoom Type: %s\nNumber of kids: %d\nNumber of Nights to spend: %d\nCheck in Date: %s\nPrice: %d %s\n", DR[empty_room].client1_name, DR[empty_room].client2_name, "Double", DR[empty_room].status_kid, DR[empty_room].night_to_spend_number, DR[empty_room].check_in_date, (500 + 50*DR[empty_room].status_kid)*DR[empty_room].night_to_spend_number, "MAD");
                        fprintf(his, "%s", "******************************************************************\n");
                    }
                }
            }
            else if (N == 3){
                empty_room = Check_available_STR(STR, 2);
                if(empty_room == -1){
                    printf("No available single rooms!\n");
                }
                else{
                    status = check_in_studio(empty_room, STR);
                    if(status != 0){
                        fprintf(his, "Client Name: %s\nPartner: %s\nRoom Type: %s\nNumber of kids: %d\nNumber of Nights to spend: %d\nCheck in Date: %s\nPrice: %d %s\n", STR[empty_room].client1_name, STR[empty_room].client2_name, "Studio", STR[empty_room].number_kids, STR[empty_room].night_to_spend_number, STR[empty_room].check_in_date, (700 + 50*STR[empty_room].number_kids)*STR[empty_room].night_to_spend_number, "MAD");
                        fprintf(his, "%s", "******************************************************************\n");
                    }
                }
            }
            else{
                printf("Invalid Inputs");
            }
            fclose(his);
            break;

        case 3:
            printf("What is the number of the room that will check out: ");
            scanf("%d", &N);
            if(N == 1 || N == 3 || N == 5 || N == 7 || N == 9){
                if(SR[N/2].status == 'E'){
                    printf("The room is already empty");
                }
                else{
                    check_out_single(N/2,SR);
                }
            }
            else if(N <= 20){
                for(i = 2; i <= 20; i += 2){
                    if(N == i){
                        if(DR[N/2-1].status == 'E'){
                            printf("The room is already empty");
                        }
                        check_out_double(N/2-1,DR);
                        break;
                    }
                }
            }
            else if(N == 33 || N == 44 || N == 55){
                if(STR[N-33/11].status == 'E'){
                    printf("The room is already empty");
                }
                check_out_studio(N-33/11, STR);
            }
            break;

        case 4:
            earn = Hotel_Earnings();
            printf("The current earning of the hotel are: %d", earn);
            break;
        case 5:
            break;
        default:
            printf("Incorrect Input");
        }
	}while(choice != 5);

	if (choice==5){
		printf("\n\n\t **THANK YOU**");
		printf("\n\t FOR TRUSTING OUR SERVICE");
    }
    fclose(his);
	return 0;
}

void menu(void){
	printf("\n----------Menu----------\n");
	printf("1. Check availability of a room type\n");
	printf("2. Check in\n");
    printf("3. Check out\n");
    printf("4. Hotel Earning\n");
    printf("5. Quit\n");
    printf("------------------------\n");
    printf("Please enter your choice from menu: ");
}

int Check_available_SR(Single_room SR[], int option){
    int i;
    int flag = 0;       //There are no rooms available
    if(option == 1){
        for(i = 0; i < 5; i++){
            if(SR[i].status == 'E'){
                printf("%d\n", SR[i].room_number);
                flag = 1;
            }
        }
        if(flag == 0){
            printf("There are no single rooms available\n");
        }
    }
    else if(option == 2){
        for(i = 0; i < 5; i++){
            if(SR[i].status == 'E'){
                return i;
            }
        }
        return -1;
    }

}

int Check_available_DR(Double_room DR[], int option){
    int i;
    int flag = 0;       //There are no rooms available
    if(option == 1){
        for(i = 0; i < 10; i++){
            if(DR[i].status == 'E'){
                printf("%d\n", DR[i].room_number);
                flag = 1;
            }
        }
        if(flag == 0){
            printf("There are no single rooms available\n");
        }
    }
    else if(option == 2){
        for(i = 0; i < 5; i++){
            if(DR[i].status == 'E'){
                return i;
            }
        }
        return -1;
    }
}
int Check_available_STR(Studio_room STR[], int option){
    int i;
    int flag = 0;       //There are no rooms available
    if(option == 1){
        for(i = 0; i < 3; i++){
            if(STR[i].status == 'E'){
                printf("%d\n", STR[i].room_number);
                flag = 1;
            }
        }
        if(flag == 0){
            printf("There are no single rooms available\n");
        }
    }
    else if(option == 2){
        for(i = 0; i < 5; i++){
            if(STR[i].status == 'E'){
                return i;
            }
        }
        return -1;
    }
}

void check_in_single(int index, Single_room SR[]){
    char ch;
    printf("Please fill in the following form\nClient Name:\n");
    ch = getchar();
    gets(SR[index].client_name);
    printf("Identity Number:\n");
    scanf("%s", SR[index].identity_number);
    printf("Partner:\nNone\n");
    printf("Room Type:\nSingle");
    printf("\nNumber of Kids:\n0\n");
    printf("Check in Date:\n");
    scanf("%s", SR[index].check_in_date);
    printf("Number of Nights to spend: \n");
    scanf("%d", &SR[index].night_to_spend_number);
    SR[index].status = 'F';
}

int check_in_double(int empty_room, Double_room DR[]){
    int ans = 1, kids;
    char ch;
    printf("Please fill in the following form\nClient Name:\n");
    ch = getchar();
    gets(DR[empty_room].client1_name);
    printf("Name of the Partner:\n");
    ch = getchar();
    gets(DR[empty_room].client2_name);
    printf("Client's Identity Number:\n");
    scanf("%s", DR[empty_room].identity_Client1_number);
    printf("Partner's Identity Number:\n");
    scanf("%s", DR[empty_room].identity_Client2_number);
    printf("Room Type:\nDouble");
    do{
        printf("\nHow many kids do you accompany (Max is 1 kid)\n");
        scanf("%d", &kids);
        if(kids != 1 && kids != 0){
            printf("You are only allowed to accompany one kid\nDo you still want to book a room\n1 - Yes\n0 - No:");
            scanf("%d", &ans);
        }
    }while(kids != 1 && kids != 0 && ans == 1);
    if(ans == 0){
        return 0;
    }
    DR[empty_room].status_kid = kids;
    printf("Check in Date:\n");
    scanf("%s", DR[empty_room].check_in_date);
    printf("Number of Nights to spend: \n");
    scanf("%d", &DR[empty_room].night_to_spend_number);
    DR[empty_room].status = 'F';
    return 1;
}
int check_in_studio(int empty_room, Studio_room STR[]){
    int ans = 1, kids;
    char ch;
    printf("Please fill in the following form\nClient Name:\n");
    ch = getchar();
    gets(STR[empty_room].client1_name);
    printf("Name of the Partner:\n");
    ch = getchar();
    gets(STR[empty_room].client2_name);
    printf("Client's Identity Number:\n");
    scanf("%s", STR[empty_room].identity_Client1_number);
    printf("Partner's Identity Number:\n");
    scanf("%s", STR[empty_room].identity_Client2_number);
    printf("Room Type:\nStudio");
    do{
        printf("\nHow many kids do you accompany (Max is 3 kids)\n");
        scanf("%d", &kids);
        if(kids > 3){
            printf("You are only allowed to accompany a maximum of 3 kids\nDo you still want to book a room\n1 - Yes\n0 - No:");
            scanf("%d", &ans);
        }
    }while((kids > 3) && ans == 1);
    if(ans == 0){
        return 0;
    }
    STR[empty_room].number_kids = kids;
    printf("Check in Date:\n");
    scanf("%s", STR[empty_room].check_in_date);
    printf("Number of Nights to spend: \n");
    scanf("%d", &STR[empty_room].night_to_spend_number);
    STR[empty_room].status = 'F';
    return 1;

}

void check_out_single(int index, Single_room SR[]){
    FILE * client;
    //Finding name of the file
    char first_name[15];
    char last_name[15];
    char fileName[35];
    strcpy(first_name,(strtok(SR[index].client_name, " ")));
    strcpy(last_name, (strtok(NULL, "")));
    strcpy(fileName, first_name);
    strcat(fileName, "_");
    strcpy(fileName, (strcat(fileName, last_name)));
    strcpy(fileName,(strcat(fileName, "_")));
    strcpy(fileName, (strcat(fileName, SR[index].identity_number)));
    strcpy(fileName, (strcat(fileName, ".txt")));
    client = fopen(fileName, "w");
    fprintf(client, "Information:\nCheck in Date: %s\nClient Name: %s\nRoom Type: %s\nNumber of Kids: %d\nNumber of Nights: %d\nTotal to Pay: %d%s\n%s", SR[index].check_in_date, SR[index].client_name, "Single", 0, 350 * SR[index].night_to_spend_number, "MAD", "Thanks For Your Visit!");
    SR[index].status = 'E';
    fclose(client);
}
void check_out_double(int index, Double_room DR[]){
    FILE * client;
    //Finding name of the file
    char first_name[15];
    char last_name[15];
    char fileName[35];
    strcpy(first_name,(strtok(DR[index].client1_name, " ")));
    strcpy(last_name, (strtok(NULL, "")));
    strcpy(fileName, first_name);
    strcat(fileName, "_");
    strcpy(fileName, (strcat(fileName, last_name)));
    strcpy(fileName,(strcat(fileName, "_")));
    strcpy(fileName, (strcat(fileName, DR[index].identity_Client1_number)));
    strcpy(fileName, (strcat(fileName, ".txt")));
    client = fopen(fileName, "w");
    fprintf(client, "Information:\nCheck in Date: %s\nClient Name: %s\nRoom Type: %s\nNumber of Kids: %d\nNumber of Nights: %d\nTotal to Pay: %d%s\n%s", DR[index].check_in_date, DR[index].client1_name, "Double", DR[index].status_kid, (500 + 50*DR[index].status_kid)*DR[index].night_to_spend_number, "MAD", "Thanks For Your Visit!");
    DR[index].status = 'E';
    fclose(client);
}
void check_out_studio(int index, Studio_room STR[]){
    FILE * client;
    //Finding name of the file
    char first_name[15];
    char last_name[15];
    char fileName[35];
    strcpy(first_name,(strtok(STR[index].client1_name, " ")));
    strcpy(last_name, (strtok(NULL, "")));
    strcpy(fileName, first_name);
    strcat(fileName, "_");
    strcpy(fileName, (strcat(fileName, last_name)));
    strcpy(fileName,(strcat(fileName, "_")));
    strcpy(fileName, (strcat(fileName, STR[index].identity_Client1_number)));
    strcpy(fileName, (strcat(fileName, ".txt")));
    client = fopen(fileName, "w");
    fprintf(client, "Information:\nCheck in Date: %s\nClient Name: %s\nRoom Type: %s\nNumber of Kids: %d\nNumber of Nights: %d\nTotal to Pay: %d%s\n%s", STR[index].check_in_date, STR[index].client1_name, "Studio", STR[index].number_kids, (700 + 50 * STR[index].number_kids)*STR[index].night_to_spend_number, "MAD" , "Thanks For Your Visit!");
    STR[index].status = 'E';
    fclose(client);
}

int Hotel_Earnings(){
    FILE * his = fopen("history.txt", "r");
    char ch[50], garbage[7];
    int i = 0;
    int count = 0;
    int total = 0;
    int earn;
    while(!feof(his)){
        while(count < (7 + i)){
            fgets(ch, 50, his);
            count++;
        }
        fscanf(his, "%s", garbage);
        fscanf(his, "%d", &earn);
        total += earn;
        i = i + 8;
    }
    fclose(his);
    return total;
}



