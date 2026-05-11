#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scrabble_checker(char A);

int main(void)
{
    // input
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    int points_p1 = 0;
    int points_p2 = 0;

    // Player 1 score
    for (int i = 0; i < strlen(p1); i++)
    {
        char char1 = toupper(p1[i]);
        points_p1 += scrabble_checker(char1);
    }
    // Player 2 score
    for (int i = 0; i < strlen(p2); i++)
    {
        char char2 = toupper(p2[i]);
        points_p2 += scrabble_checker(char2);
    }
    // Winning Possibilities
    if (points_p1 > points_p2)
    {
        printf("Player 1 wins!");
    }
    else if (points_p1 < points_p2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    printf("\n");
}

// Score calculator
int scrabble_checker(char A)
{
    int points = 0;
    if (A >= 'A' && A <= 'Z')
    {
        if (A == 'A' || A == 'E' || A == 'I' || A == 'L' || A == 'N' || A == 'O' || A == 'R' ||
            A == 'S' || A == 'T' || A == 'U')
        {
            points = points + 1;
        }
        if (A == 'B' || A == 'C' || A == 'M' || A == 'P')
        {
            points = points + 3;
        }
        if (A == 'D' || A == 'G')
        {
            points = points + 2;
        }
        if (A == 'F' || A == 'H' || A == 'V' || A == 'W' || A == 'Y')
        {
            points = points + 4;
        }
        if (A == 'J' || A == 'X')
        {
            points = points + 8;
        }
        if (A == 'K')
        {
            points = points + 5;
        }
        if (A == 'Q' || A == 'Z')
        {
            points = points + 10;
        }
    }
    return points;
}
