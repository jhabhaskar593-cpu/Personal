#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    float letters = 0;
    float words = 1;
    float sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sentences++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (isalpha(text[i]))
        {
            letters++;
        }
    }
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
    float a = (0.0588 * L);
    float b = -(0.296 * S);
    float index = a + b - 15.8;
    if (index >= (int) index + 0.5)
    {
        index = index + 0.5;
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) index);
    }
}
