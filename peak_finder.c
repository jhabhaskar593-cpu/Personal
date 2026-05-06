#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Permanent Variables
    int l = get_int("Give a number! : ");
    int u = get_int("Give a number! : ");
    int lower;
    int upper;
    int max = 0;
    int longest = 0;
    int total = 0;
    int peak = 0;
    int length  = 0;
    int segsum = 0;

    //Length comparision to find upper and lower bounds
    if(l > u)
    {
        lower = u;
        upper = l;
    }
    else
    {
        lower = l;
        upper = u;
    }
    //Loop for checking
    for(int i = lower ; i <= upper ; i++)
    {   //Temporary Variables
        int temp = i;
        int temp2 = i;
        int temp3 = i;
        int digsum = 0;
        int prod = 1;
        int prev = 0;
        //Removal of negatives
        if(i < 0)
        {
            temp  = -(temp);
            temp2  = -(temp2);
            temp3  = -(temp3);
        }
        //Digitsum
        do
        {
            int n = temp % 10;
            temp = temp / 10;
            digsum += n;
        }
        while(temp > 0);
        //Digit Product
        do
        {
            int m = temp2 % 10;
            temp2 = temp2 / 10;
            prod = prod * m;
        }
        while(temp2 > 0);
        //Harshad Test
        if(i % digsum == 0 && prod % digsum != 0)
        {   //Streak conditions and memory
            if(prod >= prev)
            {
                length++;
                segsum += i;
            }
            else
            {
                length = 1;
                segsum = i;
            }
            prev = prod;
            //Decision of Outputs
            if(longest <= length)
            {
                longest = length;
                total = segsum;
                if(prod > peak)
                {
                peak = prod;
                }
            }
        }
    }
    //Outputs
    printf("The maximum days of business were: %d\n" , longest);
    printf("valution during that period: %d\n" , total);
    printf("The PEAK: %d\n" , peak);
}
