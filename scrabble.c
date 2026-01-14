#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points funccion
int Point(char letter)
{
    int point = 0;
    if (isupper(letter))
    {
        letter = tolower(letter);
    }
    if (letter == 'a')
    {
        point = 1;
    }
    else if (letter == 'b')
    {
        point = 3;
    }
    else if (letter == 'c')
    {
        point = 3;
    }
    else if (letter == 'd')
    {
        point = 2;
    }
    else if (letter == 'e')
    {
        point = 1;
    }
    else if (letter == 'f')
    {
        point = 4;
    }
    else if (letter == 'g')
    {
        point = 2;
    }
    else if (letter == 'h')
    {
        point = 4;
    }
    else if (letter == 'i')
    {
        point = 1;
    }
    else if (letter == 'j')
    {
        point = 8;
    }
    else if (letter == 'k')
    {
        point = 5;
    }
    else if (letter == 'l')
    {
        point = 1;
    }
    else if (letter == 'm')
    {
        point = 3;
    }
    else if (letter == 'n')
    {
        point = 1;
    }
    else if (letter == 'o')
    {
        point = 1;
    }
    else if (letter == 'p')
    {
        point = 3;
    }
    else if (letter == 'q')
    {
        point = 10;
    }
    else if (letter == 'r')
    {
        point = 1;
    }
    else if (letter == 's')
    {
        point = 1;
    }
    else if (letter == 't')
    {
        point = 1;
    }
    else if (letter == 'u')
    {
        point = 1;
    }
    else if (letter == 'v')
    {
        point = 4;
    }
    else if (letter == 'w')
    {
        point = 4;
    }
    else if (letter == 'x')
    {
        point = 8;
    }
    else if (letter == 'y')
    {
        point = 4;
    }
    else if (letter == 'z')
    {
        point = 10;
    }
    else
    {
        point = 0;
    }
    return point;
}

int main(void)
{
    // User input
    string user1 = get_string("Player 1: ");
    string user2 = get_string("Player 2: ");
    int score[2];
    score[0] = 0;
    score[1] = 0;

    for (int a = 0, d = strlen(user1); a < d; a++)
    {
        score[0] = score[0] + Point(user1[a]);
        printf("%d\n", score[0]);
    }
    printf("\n");
    for (int a = 0, d = strlen(user2); a < d; a++)
    {
        score[1] = score[1] + Point(user2[a]);
        printf("%d\n", score[1]);
    }
    printf("\n");
    if (score[0] > score[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (score[0] < score[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
