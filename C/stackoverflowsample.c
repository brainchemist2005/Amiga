#include <stdio.h>
// lol i corrected this code XD !

int sum(int a, int b)
{
    int answer;
    answer = a+b;
    return answer;
}

int main()
    {
        int var_a,  var_b;
        int result;

        printf (" first number \n");
        scanf ("%i",&var_a);
        printf ("second number \n");
        scanf ("%i",&var_b);
            result = sum(var_a,var_b);

        printf(" The sum is %i", result);

        return 0;       
    } 