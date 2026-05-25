#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main(void)
{
    char ask;
    printf("Layout:\n");
    printf("    A    B    C    D      \n");
    char alphaB[] = "ABCDABCDABCDABCDABCD";
    int j = 0;
    int k = 4;
    for (int i = 0; i < 5; i++)
    {
        printf("%i", i+1);

        while (j < k)
        {
            printf("  [%c]", alphaB[j]);
            j++;
        }
        k = k + 4;
        printf("\n");
    }

    int n = 0;
    string sold[20]= {0};

    do
    {
    string ticket = get_string("Which seat do you want?(Only upper): ");

    char seat = toupper(ticket[1]);
    bool status = true;
    int c = atoi(ticket);

    for (int i = 0; i < n && n > 0; i++)
    {
        if (strcmp(sold[i], ticket) == 0)
        {
            status = false;
            break;
        }
    }

    if (status)
    {
        j = 0;
        k = 4;
     for (int i = 0; i < 5;i++)
     {
        if (i == c - 1)
        {
            for (int m = 4 * (i); m < (4 * (i+1)); m++)
            {
                if (alphaB[m] == seat)
                {
                    alphaB[m] = 'X';
                    break;
                }
            }
        }
     }
        for (int i = 0; i < 5; i++)
    {
        printf("%i", i+1);

        while (j < k)
        {
            printf("  [%c]", alphaB[j]);
            j++;
        }
        k = k + 4;
        printf("\n");
    }
    }
    else
    {
        printf("Already Sold\n");
    }
    string prevtick = ticket;
    sold[n] = prevtick;
    n++;
    ask = get_char("Want another?(y/n): ");
} while (ask == 'y' || ask == 'Y');
}

