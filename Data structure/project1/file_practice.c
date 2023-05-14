#include<stdio.h>
#include<string.h>


int main()
{
    char temp,word[6]; 
    int i = 0;

    scanf("%s",word);

    FILE*fp = fopen("C:\\Users\\DELL\\Desktop\\New Text Document.txt","w");

    fprintf(fp,"%s",word);

    fclose(fp);

    FILE*file = fopen("C:\\Users\\DELL\\Desktop\\New Text Document.txt","r");

    if(file == NULL)
    printf("Error");

    else
    {
        while(!feof(file))
        {
            fscanf(file,"%c",&temp);
            i++;
        }
    }

    printf("The size is %d Bytes",i);

    return 0;
}