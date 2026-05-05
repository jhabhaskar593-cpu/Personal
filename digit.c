#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char y;
    do
    {
        int l;
        int r;
        int k;
        int pos;
        int sum = 0;
        int count = 0;
        int min = 0;
        int max = 0;

        do
        {
            l = get_int("What's the first number?: ");
            r = get_int("What's the second number?: ");
        }
        while (l > r);

        do
        {
            k = get_int("What's the divisor?: ");
        }
        while (k == 0);

        for (int i = l; i <= r; i++)
        {
            int digprod = 1;
            int q = 1;
            pos = i - l + 1;

            if (i % k == 0)
            {

                int temp = i;

                if (temp < 0)
                {
                    temp = -(temp);
                }

                do
                {
                    int n = temp % 10;
                    temp = temp / 10;
                    digprod = digprod * n;
                }
                while (temp > 0);

                if (digprod > 0 && digprod % 5 > 0)
                {
                    if (pos > 1)
                    {
                        for (int p = 2; p * p <= pos; p++)
                        {
                            if ((pos % p) == 0)
                            {
                                q = 0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        q = 0;
                    }
                    for (float m = 1; m * m <= pos; m++)
                    {
                        if (pos / m == m)
                        {
                            q = 1;
                            break;
                        }
                    }

                    if (q == 1)
                    {
                        count++;
                        sum += i;

                        if (count == 1)
                        {
                            min = i;
                            max = i;
                        }
                        else
                        {
                            if (min > i)
                            {
                                min = i;
                            }

                            if (max < i)
                            {
                                max = i;
                            }
                        }
                    }
                }
            }
        }
        if (count > 0)
        {
            printf("The sum is: %d \n", sum);
            printf("The no. of valid answers are: %d \n", count);
            printf("The minimum value is: %d \n", min);
            printf("The maximum value is: %d \n", max);
        }
        else if (count == 0)
        {
            printf("No valid answers.\n");
        }

        y = get_char("Continue?: ");
    }
    while (y == 'y' || y == 'Y');
}
