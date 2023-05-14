#include<stdio.h>
int main(){
    int Midterm,Final,average,counter,section,count,counter1=0,counter2=0,counter3=0,counter4=0,counter5=0;
    double sum,average1;
    for(section=1;section<=5;section++){
        counter=0;
        Midterm=0;
        Final=0;
        count=0;
        sum=0;
        while(Midterm >= 0){
        printf("enter a the midterm grade:");
        scanf("%d",&Midterm);
        printf("enter a the final grade:");
        scanf("%d",&Final);
        average = (Midterm + Final)/2 ;
        printf("The average is %d\n",average);
        sum+=average;
        count++;
        if(average > 70){
            counter++;
            if(section == 1){
                counter1= counter++;
            }
            else if(section == 2){
                counter2 = counter++;
            }
            else if(section == 3){
                counter3 = counter++;
            }
            else if(section == 4){
                counter4 == counter++;
            }
            else if(section == 5){
                counter5 == counter++;
            }
        }
    }
    average1 = sum/count ;
    printf("the averge of this section is %2.lf\n",average1);
    printf("the number of passing students in the section %d is %d\n",section,counter);
    }
    if(counter1 >= counter2 && counter2 >= counter3 && counter3 >= counter4 && counter4 >= counter5){
        printf("the section with the highest number of student is section 1\n ");
        }
        else if(counter2 >= counter1 && counter1 >= counter3 && counter3 >= counter4 && counter4 >= counter5){
        printf("the section with the highest number of student is section 2\n ");
        }
        else if(counter3 >= counter2 && counter2 >= counter1 && counter1 >= counter4 && counter4 >= counter5){
        printf("the section with the highest number of student is section 3\n ");
        }
        else if(counter4 >= counter2 && counter2 >= counter3 && counter3 >= counter1 && counter1 >= counter5){
        printf("the section with the highest number of student is section 4\n ");
        }
        else if(counter5 >= counter2 && counter2 >= counter3 && counter3 >= counter4 && counter4 >= counter1){
        printf("the section with the highest number of student is section 5\n ");


    }
    
    return 0;
}

