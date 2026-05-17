#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int non_alpha_checker(string K);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vinegere KEY\n");
        return 1;
    }
    string keyy = argv[1];
    if (non_alpha_checker(keyy))
    {
        printf("Characters must be alphabet.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    int key = strlen(keyy);
    int m = strlen(plaintext);
    int key_in = 0;
    char cipher;
    printf("ciphertext: ");
    for (int i = 0; i < m; i++)
    {
        if(isalpha(plaintext[i]))
        {
        if(key_in > 0 && (key_in % key == 0))
        {
            key_in = 0;
        }
        int indexkey = toupper(keyy[key_in]) - 'A';
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            cipher = ((index + indexkey) % 26) + 'A';
        }
        else
        {
            int index = plaintext[i] - 'a';
            cipher = ((index + indexkey) % 26) + 'a';
        }
        key_in++;
        }
        else
        {
            cipher = plaintext[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
    return 0;
}

int non_alpha_checker(string K)
{
    int m = strlen(K);
    int safe = 0;
    for (int i = 0; i < m; i++)
    {
        if (!isalpha(K[i]))
        {
            safe = 1;
            break;
        }
    }
    return safe;
}
