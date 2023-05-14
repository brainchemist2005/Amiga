#include<stdio.h>
#include<string.h>

int count(char * word)
{
    int n = 0;

    while(word[n] != '\0')
    {
        n++;
    }

    return n;
}


int main()
{
    FILE*fp = fopen("C:\\Users\\DELL\\Desktop\\New Text Document.txt","r");
    FILE*file = fopen("Output.txt","w");

    int i;
    char word[100];

    if(fp == NULL)
    {
    printf("Error");
    return 0;
    }


    while(!feof(fp))
    {
        i = 0;
        fscanf(fp,"%s",word);
        if(strcmp(word," ") != 0 || strcmp(word,"\n") != 0 || strcmp(word,".") != 0, strcmp(word,",") != 0 || strcmp(word,";") != 0)
        {
            i = count(word);
            fprintf(file,"%s: %d\n",word,i);
        }
    }

    fclose(fp);
    fclose(file);

    printf("DONE");

    return 0;

}