#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int l;
    int r;
    int power= 0;
    int prevpower = 0;
    int peakpw = 0;
    int ssum = 0;
    int longest = 0;
    int total = 0;
    int actualpeak = 0;
    int momen = 0;
    int prevmomen = 0;
    int length = 0;
    do
    {
        l = get_int("First No.: ");
        r = get_int("Second No.: ");
    }
    while(l > r);
    for(int i = l ; i <= r ; i++)
    {
        int temp = i;
        int temp2 = i;
        int sum = 0;
        int prod = 1;
        if(i < 0)
        {
            temp = -temp;
            temp2 = -temp2;
        }
        do
        {
            int n = temp % 10;
            temp = temp / 10;
            sum += n;
        }
        while(temp > 0);
        do
        {
            int m = temp2 % 10;
            temp2 = temp2/10;
            prod = prod * m;
        }
        while(temp2 > 0);
        if(sum != 0 && i % sum == 0 && prod % sum != 0)
        {
            power = prod - sum;
            momen = power - prevpower;
            if(momen > prevmomen)
            {
                ssum += i;
                if(power > peakpw || length == 0)
                {
                    peakpw = power;
                }
                length++;
            }
            else
            {
                length = 1;
                ssum = i;
                peakpw = power;
            }
            if(longest <= length)
            {
                longest = length;
                total = ssum;
                actualpeak = peakpw;
            }
            prevpower = power;
            prevmomen = momen;
        }
    }
    printf("Longest: %d\n" , longest);
    printf("Total: %d\n" , total);
    printf("Peak Power: %d\n" , actualpeak);
}
