#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

long int_maker(string A);
int repeat_checker(int A, string B[], int C);

int main(int argc, string argv[])
{
    float Balance = 0;
    char repeat;
    if (argc < 3 || argc % 2 == 0)
    {
        printf("Very few items , add more.\n");
        return 1;
    }

    if (repeat_checker(2, argv, argc) == 1)
    {
        printf("Repetition of items is not allowed.\n");
        return 1;
    }

    int stock[((argc - 1) / 2)];
    int j = 0;
    for (int i = 1; i < argc; i = i + 2)
    {
        stock[j] = 5;
        j++;
    }

    do
    {
    string purchase = get_string("What do you want? : ");
    double cost = get_double("How much do you have? : ");
    float change = 0;
    int status = 0;

    for (int j = 0 , k = 0; j < (argc - 1); j = j + 2, k++)
    {
    if (int_maker(purchase) == int_maker(argv[1 + j]) && cost >= atof(argv[2 + j]) && stock[k] > 0)
    {
        change = cost - atof(argv[2 + j]);
        Balance += atof(argv[2 + j]);
        stock[k]--;
        status = 1;
        break;
    }
    }

    if (status == 0)
    {
        printf("Invalid Price OR Invalid Name OR Out of Stock.\n We are extremely apologitic.\n");
    }
    else {
    printf("change: %f\n", change);
    printf("Balance: %f\n", Balance);
    }
    repeat = get_char("Would you continue(y/n): ");
    } while (repeat == 'y' || repeat == 'Y');
}

long int_maker(string A)
{
    int m = strlen(A);
    long sum = 0;
    for (int i = 0; i < m; i++)
    {
        char c = toupper(A[i]) - 'A';
        sum += (sum * 31) + c;
    }
    return sum;
}

int repeat_checker(int A, string B[], int C)
{
    int status = 0;
    int checker = 0;
    for (int i = 1; i < C; i = i + A)
    {
        for (int j = 1; j < C; j = j + A)
        {
            if(int_maker(B[i]) == int_maker(B[j]))
            {
                checker++;
            }
        }
    }
    if (checker > ((C - 1) / 2))
    {
        status = 1;
    }
    return status;
}
