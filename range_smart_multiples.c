#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char y;
    do
    {
        int l;
        int r;
        int a;
        int b;
        int c = 0;
        int i = 0;
        int n = 0;
        int min;
        int max;
        int sum = 0;
        int sum2 = 0;


        do
        {
            l = get_int("What's the first number?: ");
            r = get_int("What's the second number?: ");
        }
        while(l > r);

        do
        {
            a = get_int("What's the first divisor?: ");
            b = get_int("What's the second divisor?: ");
        }
        while(a <= 0 || b <= 0);

        for(int q = l ; q <= r ; q++)
        {
            if( ((q % a) == 0 || (q % b) == 0) && !((q % a) == 0 && (q % b) == 0))
            {
                sum = 0;
                int temp = q;
                if(temp < 0)
                {
                    temp = -(temp);
                }
                do
                {
                    n = temp % 10;
                    temp = temp / 10;
                    sum += n;
                }
                while(temp != 0);
                if((sum % 2) == 0)
                {
                    sum2 = sum2 + q;
                    if(c == 0)
                    {
                        min = q;
                        max = q;
                    }
                    else
                    {
                        if(min > q)
                        {
                            min = q;
                        }
                        if(max < q)
                        {
                            max = q;
                        }
                    }
                    c++;
                }

            }
        }

        printf("%d\n", sum2);
        printf("%d\n", c);
        printf("%d\n", min);
        printf("%d\n", max);
        y = get_char("CONTINUE?(y/n)");

        }while(y == 'Y' || y == 'y');

    }



