#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string First = get_string("First word: ");
    string Second = get_string("Second word: ");

    int seen[26] = {0};
    int m = strlen(Second);
    int n = strlen(First);

    if(m != n)
    {
        printf("Not anagam\n");
        return 1;
    }

    for(int i = 0; i < m; i++)
    {
        if(isalpha(First[i]) && isalpha(Second[i]))
        {
        int index = toupper(First[i]) - 'A';
        seen[index]++;
        int index2 = toupper(Second[i]) - 'A';
        seen[index2]--;
        }
    }
    int safe = 0;
    for (int j = 0; j < 26 && safe == 0; j++)
    {
        if(seen[j] != 0)
        {
            safe = 1;
            break;
        }
    }
    if(safe == 0)
    {
        printf("Anagam\n");
    }
    else
    {
        printf("Not anagam\n");
    }
}
