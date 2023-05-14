										/*

                                            Data Structures 1st Project

                                                ---> Sahl El Khamkhami

                                                ---> Imane Jalal

                                        */

#include<stdio.h>
#include<string.h>
typedef struct{
    char status;
    char check_in_date[10];
    char client_name [30];
    char CIN [10];
    int room_nb;
    int nb_of_night;
}single_room;
typedef struct{
    char status;
    char check_in_date[10];
    char client_name_1 [30];
    char client_name_2 [30];
    char CIN_1 [10];
    char CIN_2 [10];
    int room_nb;
    int kid_status;
    int nb_of_night;
}double_room;
typedef struct{
    char status;
    char check_in_date[10];
    char client_name_1 [30];
    char client_name_2 [30];
    char CIN_1 [10];
    char CIN_2 [10];
    int room_nb;
    int nb_of_kids;
    int nb_of_night;
}studio_room;
void Menu (void);
void setting_room_status_to_empty(single_room*,double_room*,studio_room*);
void assigning_room_number(single_room*,double_room*,studio_room*);
void check_availability(single_room*,double_room*,studio_room*,char*);
void check_in(single_room*,double_room*,studio_room*,char*,FILE*);
int check_out(single_room*,double_room*,studio_room*,char*);
int hotel_earning(single_room*,double_room*,studio_room*,FILE*);
int main(){
    single_room single_r[5];
    double_room double_r[10];
    studio_room studio_r[3];
    char room_to_search[10];
    char name_to_search[30];
    FILE* outfp;
    char temp;
    int choice;
    int earnings=0;
    int flag;
    outfp=fopen("history.txt","a");
    setting_room_status_to_empty(single_r,double_r,studio_r); //when the program is run again, it clears all rooms and does not read                                                                
															//history.txt as input to make sure which rooms were full
    assigning_room_number(single_r,double_r,studio_r);
    do{
    Menu();
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("Enter the room type to check availability of: (Single / Double / Studio)\n");
            scanf("%s", room_to_search);
            check_availability(single_r,double_r,studio_r,room_to_search);
            break;
        case 2:
            printf("Enter the room type to check in: (Single / Double / Studio)\n");
            scanf("%s", room_to_search);
            outfp=fopen("history.txt","a");
            check_in(single_r,double_r,studio_r,room_to_search,outfp);
            break;
        case 3:
            printf("Enter the client name you want to check out: \n(For Double or Studio rooms please enter only the first client's name) \n");
            scanf("%c",&temp);
            gets(name_to_search);
            flag=check_out(single_r,double_r,studio_r,name_to_search);
            if (flag==0)
                printf("The name you entered is not found\n");
            else{
                printf("The bill is produced, check the file.\n");
                printf("The room is free now!\n");
            }
            break;
        case 4:
            earnings=hotel_earning(single_r,double_r,studio_r,outfp);
            printf("The total Hotel earnings are: %d\n",earnings);
            break;
        case 5:
            fclose(outfp);
            printf("Thank you for using our hotel database\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    }while (choice!=5);
}
void setting_room_status_to_empty(single_room* single_r,double_room* double_r,studio_room* studio_r){
    int i;
    for(i=0;i<5;i++)
        single_r[i].status='E';
    i=0;
    for(i=0;i<10;i++)
        double_r[i].status='E';
    i=0;
    for(i=0;i<3;i++)
        studio_r[i].status='E';
}
void assigning_room_number(single_room* single_r,double_room* double_r,studio_room* studio_r){
    single_r[0].room_nb=1;
    single_r[1].room_nb=3;
    single_r[2].room_nb=5;
    single_r[3].room_nb=7;
    single_r[4].room_nb=9;
    double_r[0].room_nb=2;
    double_r[1].room_nb=4;
    double_r[2].room_nb=6;
    double_r[3].room_nb=8;
    double_r[4].room_nb=10;
    double_r[5].room_nb=12;
    double_r[6].room_nb=14;
    double_r[7].room_nb=16;
    double_r[8].room_nb=18;
    double_r[9].room_nb=20;
    studio_r[0].room_nb=33;
    studio_r[1].room_nb=44;
    studio_r[2].room_nb=55;
}
// Definition of check availability function:
void Menu (void){
    printf("\n\t----------------------Menu------------------------\n");
    printf("\n\t1.Check Availability of a Room Type\n");
    printf("\n\t2.Check In\n");
    printf("\n\t3.Check Out\n");
    printf("\n\t4.Hotel Earning\n");
    printf("\n\t5.Quit\n");
    printf("\n\tPlease make your choice\n");
}
void check_availability(single_room* single_r,double_room* double_r,studio_room* studio_r,char* room_search){
    int i;
    if(strcmp(room_search,"Single")==0){
        printf("Rooms available for Single type are:\n");
        for(i=0;i<5;i++){
            if(single_r[i].status=='E')
            printf("\n-->%d\n",single_r[i].room_nb);
        }
        if(studio_r[4].status=='F')
        printf("\tNone\n");
    }
    else if (strcmp(room_search,"Double")==0){
        printf("Rooms available for Double type are:\n");
        for(i=0;i<10;i++){
            if(double_r[i].status=='E')
                printf("\n-->%d\n",double_r[i].room_nb);
        }
        if(studio_r[9].status=='F')
        printf("\tNone\n");
    }
    else if (strcmp(room_search,"Studio")==0){
        printf("Rooms available for Studio type are:\n");
        for(i=0;i<3;i++){
            if(studio_r[i].status=='E')
                printf("\n-->%d\n",studio_r[i].room_nb);
        }
        if(studio_r[2].status=='F')
        printf("\tNone\n");
    }
    else
        printf("Invalid Room Type\n");
}
// Definition of Check-In function:
void check_in(single_room* single_r,double_room* double_r,studio_room* studio_r,char* room_search,FILE* outfp){
    int i;
    char temp;
    if(strcmp(room_search,"Single")==0){
        for(i=0;i<5;i++){
            if(single_r[i].status=='E'){
                single_r[i].status='F';
                break;
            }
        }
        if(i!=5){
            scanf("%c",&temp);
            printf("Enter the check in date:\n");
            gets(single_r->check_in_date);
            printf("Enter the Client Name:\n");
            gets(single_r->client_name);
            printf("Enter the CIN:\n");
            gets(single_r->CIN);
            printf("Enter the number of nights :\n");
            scanf("%d",&single_r->nb_of_night);
            //Printing in the Output File:
            fprintf(outfp,"Client Name: \n%s\n",single_r->client_name);
            fprintf(outfp,"Partner: \nNone\n");
            fprintf(outfp,"Room Type: \nSingle\n");
            fprintf(outfp,"Number of Kids: \n0\n");
            fprintf(outfp,"Number of Nights: \n%d\n   ",single_r->nb_of_night);
            fprintf(outfp,"-----------------------\n");
            }
        else{
            printf("all the single rooms are full\n");
        }
    }
    else if(strcmp(room_search,"Double")==0){
        for(i=0;i<10;i++){
            if(double_r[i].status=='E'){
                double_r[i].status='F';
                break;
            }
        }
        if(i!=10){
            scanf("%c",&temp);
            printf("Enter the check in date:\n");
            gets(double_r->check_in_date);
            printf("Enter the First Client Name:\n");
            gets(double_r->client_name_1);
            printf("Enter the Second Client Name:\n");
            gets(double_r->client_name_2);
            printf("Enter the First Client's CIN:\n");
            gets(double_r->CIN_1);
            printf("Enter the Second Client's CIN:\n");
            gets(double_r->CIN_2);
            printf("Is there a kid or no? (1 for Yes, 0 for No\n)");
            scanf("%d",&double_r->kid_status);
            printf("Enter the number of nights :\n");
            scanf("%d",&double_r->nb_of_night);
            //Printing in the Output File:
            fprintf(outfp,"Client Name: \n%s\n",double_r->client_name_1);
            fprintf(outfp,"Partner: \n%s\n",double_r->client_name_2);
            fprintf(outfp,"Room Type: \nDouble\n");
            if(double_r->kid_status==1)
                fprintf(outfp,"Number of Kids: \n1\n");
            else
                fprintf(outfp,"Number of Kids: \n0\n");
            fprintf(outfp,"Number of Nights: \n%d\n",double_r->nb_of_night);
            fprintf(outfp,"-----------------------\n");
            }

        else

            printf("all the double rooms are full\n");

        }

    else if(strcmp(room_search,"Studio")==0){

        for(i=0;i<3;i++){

            if(studio_r[i].status=='E'){

                studio_r[i].status='F';

                break;

            }

        }

        if(i!=3){

        scanf("%c",&temp);

        printf("Enter the check in date:\n");

        gets(studio_r->check_in_date);

        printf("Enter the First Client Name:\n");

        gets(studio_r->client_name_1);

        printf("Enter the Second Client Name:\n");

        gets(studio_r->client_name_2);

        printf("Enter the First Client's CIN:\n");

        gets(studio_r->CIN_1);

        printf("Enter the Second Client's CIN:\n");

        gets(studio_r->CIN_2);

        printf("Enter the number of kids(Maximum of 3 kids):\n)");

        scanf("%d",&studio_r->nb_of_kids);

        printf("Enter the number of nights :\n");

        scanf("%d",&studio_r->nb_of_night);

        //Printing in the Output File:

        fprintf(outfp,"Client Name: \n%s\n",studio_r->client_name_1);

        fprintf(outfp,"Partner: \n%s\n",studio_r->client_name_2);

        fprintf(outfp,"Room Type: \nStudio\n");

        fprintf(outfp,"Number of kids:\n%d\n",studio_r->nb_of_kids);

        fprintf(outfp,"Number of Nights: \n%d\n",studio_r->nb_of_night);

        fprintf(outfp,"-----------------------\n");

        }

        else

            printf("all the studio rooms are full\n");

    }

    fclose(outfp);

}

// End of Check In function definition


// Definition of Check-Out function:

int check_out(single_room* single_r,double_room* double_r,studio_room* studio_r,char*name_search){

    int i,j;

    int flag=0, flag_2=0; //flag_2 is used for handling the found or not found case

    FILE* outfp;

    char filename[50];

    memset(filename,'\0',sizeof(filename));  // This is to remove the garbage data from the filename

    for(i=0;i<5;i++){

        if(strcmp(single_r[i].client_name,name_search)==0){

            for(j=0;j<strlen(name_search);j++){

                if(name_search[j]!=' '){

                    filename[j]=name_search[j];

                }

                else

                    filename[j]='_';

            }

            strcat(filename,"_");

            strcat(filename, single_r[i].CIN);

            strcat(filename,".txt");

            outfp=fopen(filename,"w");

            fprintf(outfp,"Check in Date: %s\n",single_r[i].check_in_date);

            fprintf(outfp,"Client Name: %s\n",single_r[i].client_name);

            fprintf(outfp,"Room Type: Single\n");

            fprintf(outfp,"Number of Kids: 0\n");

            fprintf(outfp,"Number of Nights: %d\n",single_r[i].nb_of_night);

            fprintf(outfp,"Total to pay: %d MAD\n",350*single_r[i].nb_of_night);

            fprintf(outfp,"Thanks for your visit!\n");

            fprintf(outfp,"-----------------------\n");

            single_r[i].status='E';

            flag_2=1;

            flag=1;

            fclose(outfp);

            break;

        }

    }

    if(flag==0){
        for(i=0;i<10;i++){
            if(strcmp(double_r[i].client_name_1,name_search)==0){
                for(j=0;j<strlen(name_search);j++){
                    if(name_search[j]!=' '){
                        filename[j]=name_search[j];
                    }
                    else
                        filename[j]='_';
                }
            strcat(filename,"_");
            strcat(filename, double_r[i].CIN_1);
            strcat(filename,".txt");
            outfp=fopen(filename,"w");
            fprintf(outfp,"Check in Date: %s\n",double_r[i].check_in_date);
            fprintf(outfp,"Client Name: %s\n",double_r[i].client_name_1);
            fprintf(outfp,"Partner Name: %s\n",double_r[i].client_name_2);
            fprintf(outfp,"Room Type: Double\n");
            if(double_r->kid_status==1){
                fprintf(outfp,"Number of Kids: 1\n");
                fprintf(outfp,"Number of Nights: %d\n",double_r[i].nb_of_night);
                fprintf(outfp,"Total to pay: %d MAD\n",(500+50)*double_r[i].nb_of_night);
            }
            else{
                fprintf(outfp,"Number of Kids: 0\n");
                fprintf(outfp,"Number of Nights: %d\n",double_r[i].nb_of_night);
                fprintf(outfp,"Total to pay: %d MAD\n",(500)*double_r[i].nb_of_night);
            }
            fprintf(outfp,"Thanks for your visit!\n");
            fprintf(outfp,"-----------------------\n");
            double_r[i].status='E';
            flag_2=1;
            flag=1;
            fclose(outfp);
            break;
            }
        }
    }
    if(flag==0){
        for(i=0;i<3;i++){
            if(strcmp(studio_r[i].client_name_1,name_search)==0){
               for(j=0;j<strlen(name_search);j++){
                   if(name_search[j]!=' '){
                       filename[j]=name_search[j];
                   }
                   else
                       filename[j]='_';
               }
            strcat(filename,"_");
            strcat(filename, studio_r[i].CIN_1);
            strcat(filename,".txt");
            outfp=fopen(filename,"w");
            fprintf(outfp,"Check in Date: %s\n",studio_r[i].check_in_date);
            fprintf(outfp,"Client Name: %s\n",studio_r[i].client_name_1);
            fprintf(outfp,"Partner Name: %s\n",studio_r[i].client_name_2);
            fprintf(outfp,"Room Type: Studio\n");
            if(studio_r[i].nb_of_kids==1){
                fprintf(outfp,"Number of Kids: 1\n");
                fprintf(outfp,"Number of Nights: %d\n",studio_r[i].nb_of_night);
                fprintf(outfp,"Total to pay: %d MAD\n",(700+50)*studio_r[i].nb_of_night);
            }
            else if (studio_r[i].nb_of_kids==2){
                fprintf(outfp,"Number of Kids: 2\n");
                fprintf(outfp,"Number of Nights: %d\n",studio_r[i].nb_of_night);
                fprintf(outfp,"Total to pay: %d MAD\n",(700+50*2)*studio_r[i].nb_of_night);
                }
            else{
                fprintf(outfp,"Number of Kids: 3\n");
                fprintf(outfp,"Number of Nights: %d\n",studio_r[i].nb_of_night);
                fprintf(outfp,"Total to pay: %d MAD\n",(700+50*3)*studio_r[i].nb_of_night);
            }
                fprintf(outfp,"Thanks for your visit!\n");
                fprintf(outfp,"-----------------------\n");
                studio_r[i].status='E';
                flag_2=1;
                flag=1;
                fclose(outfp);
                break;
            }
        }
    }
    return flag_2;
}
 // End of Check Out function definition


 // Definition of Hotel Earning function:

int hotel_earning(single_room* single_r,double_room* double_r,studio_room* studio_r,FILE* infp){
    char line[50],room_type[10];
    int nb_kids, nb_nights,counter=0,sum=0,i;
    fclose(infp);
    infp=fopen("history.txt", "r");
    while(!feof(infp)){
        for(i=0;i<5;i++){
            fgets(line,50,infp);
        }
    fscanf(infp,"%s\n",room_type);
    fgets(line,50,infp);
    fscanf(infp,"%d\n",&nb_kids);
    fgets(line,50,infp);
    fscanf(infp,"%d\n",&nb_nights);
    if(strcmp(room_type,"Single")==0)
        counter=350*nb_nights;
    else if (strcmp(room_type,"Double")==0)
        counter=(500+50*nb_kids)*nb_nights;
    else if (strcmp(room_type,"Studio")==0)
        counter=(700+50*nb_kids)*nb_nights;
    fgets(line,50,infp);
    sum+=counter;
    }
    //sum=sum/2;
    fclose(infp);
    return sum;
}

