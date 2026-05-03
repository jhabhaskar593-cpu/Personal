#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    int a;
    int b;
    int f = 0;
    int g = 0;
    int e = 0;
    int c = 0;
    int m = 0;
    do
    {
        n = get_int("What's the number? ");
    }while (n <= 0);
    do
    {
        a = get_int("What's the number? ");
    }while (a <= 0);
    do
    {
        b = get_int("What's the number? ");
    }while (b <= 0);

    for (int i = 1 ; i <= n ; i++)
    {
        f = i % a;
        g = i % b;
        if ((f == 0 || g == 0) && !(f == 0 && g == 0))
        {
    e += i ;
        printf("%d , " , i);
        c++;
        }
        else
        {
            m++;
        }
}
printf("\n");
printf(" %d\n " , e);
printf(" %d\n " , m);
printf(" %d\n " , c);

}
