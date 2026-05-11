#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char y;
    //inputs
    do
    {
    int l;
    int r;
    int k;
    int c1 = 0;
    int c2 = 0;
    int n = 0;
    int sum2 = 0;
    int min = 0;
    int max = 0;

    do
    {
        l = get_int("What's the first number?: ");
        r = get_int("What's the second number?: ");
    }
    while(l > r);
    do
    {
        k = get_int("What's the divisor?: ");
    }
    while(k == 0);
    //for for numbers
    for(int i = l ; i <= r ; i++)
    {
        int q = 1;
        c2 = i - l + 1;
        int sum = 1;
        //if i is divisible by k
        if( (i % k) == 0 )
        {
            //digit prod of i for non zero and divisible by 3
            if(i % 10 != 0)
            {
            int temp = i;
            if(temp < 0)
            {
                temp = -(temp);
            }

            do
            {
                n = temp % 10;
                temp = temp / 10;
                sum = sum * n ;
            }while(temp > 0);

            if(sum != 0 )
            {
                if(sum % 3 == 0){
                if(c2 > 1){
                for(int p = 2; p * p <= c2 && q > 0 ; p++)
                {
                    int m = c2 % p;
                    if(m == 0)
                    {
                        q = 0;
                    }
                }}
                else
                {
                    q = 1;
                }
                if(q > 0)
            {
                c1++;
                sum2 += i;
                if(c1 == 1)
                {
                    min = i;
                    max = i;
                }
                else
                {
                    if(min > i)
                    {
                        min = i;
                    }
                    if(max < i)
                    {
                        max = i;
                    }
                }
            }
            }

        }}}}

        if(c1 != 0){
    printf("The sum is : %d \n" , sum2);
    printf("The no. of valid answers are: %d \n" , c1);
    printf("The minimum valid answer is: %d \n" , min);
    printf("The maximum value is: %d \n" , max);
    }
    else
    {
        printf("No valid numbers found.\n");
    }
    y = get_char("Continue?(y/n): ");
    }while(y == 'Y' || y == 'y');


}



