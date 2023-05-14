#include<Stdio.h>

void hanoi(int n,char s,char t,char d)
{
    if(n == 1)
        printf("%c to %c\n",s,d);

    else
    {
        hanoi(n-1,s,d,t);
        printf("%c to %c\n",s,d);
        hanoi(n-1,t,s,d);
    }
}



int main()
{

    int n;
    char s,t,d;

    s = 'A';
    t = 'B';
    d = 'C';

    printf("How many disks do you want to have ? ");
    scanf("%d",&n);

    hanoi(n,s,t,d);

    return 0;
}