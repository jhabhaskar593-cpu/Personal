#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int digit_checker(string K);
int repeat_checker(string K);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage:./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (digit_checker(argv[1]) == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (repeat_checker(argv[1]) == 1)
    {
        printf("Characters mustn't be repeated.\n");
        return 1;
    }

    string pt = get_string("plaintext: ");
    string key = argv[1];
    int m = strlen(pt);
    printf("ciphertext: ");
    for (int i = 0; i < m; i++)
    {
        int index = 0;
        if (isupper(pt[i]))
        {
            index = pt[i] - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(pt[i]))
        {
            index = pt[i] - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}

int digit_checker(string K)
{
    int safe = 0;
    int length = strlen(K);
    for (int i = 0; i < length && safe == 0; i++)
    {
        char c = K[i];
        if (isdigit(c))
        {
            safe = 1;
            break;
        }
        else if (!isalpha(c))
        {
            safe = 1;
            break;
        }
    }
    return safe;
}

int repeat_checker(string M)
{
    int safe1 = 0;
    int length1 = strlen(M);
    for (int i1 = 0; i1 < length1 && safe1 == 0; i1++)
    {
        char c = toupper(M[i1]);
        for (int j = 0; i1 >= 1 && j < i1; j++)
        {
            char c1 = toupper(M[j]);
            if (c == c1)
            {
                safe1 = 1;
                break;
            }
        }
    }
    return safe1;
}
