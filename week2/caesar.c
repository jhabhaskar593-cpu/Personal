#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checker(string K);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        bool safe = checker(key);
        if (safe == true)
        {
            int keyy = atoi(key);
            string plaintext = get_string("plaintext: ");
            int length = strlen(plaintext);
            for (int j = 0; j < length; j++)
            {
                char cipher = plaintext[j];
                int index = 0;
                if (isalpha(cipher))
                {
                    if (islower(cipher))
                    {
                        index = cipher - 'a';
                        cipher = ((index + keyy) % 26) + 'a';
                    }
                    else if (isupper(cipher))
                    {
                        index = cipher - 'A';
                        cipher = ((index + keyy) % 26) + 'A';
                    }
                }
                if (j == 0)
                {
                    printf("ciphertext: %c", cipher);
                }
                else
                {
                    printf("%c", cipher);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool checker(string K)
{
    bool s = true;
    int m = strlen(K);
    for (int i = 0; i < m; i++)
    {
        char n = K[i];
        if (isdigit(n))
        {
        }
        else
        {
            s = false;
            break;
        }
    }
    return s;
}
