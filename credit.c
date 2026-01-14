#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int verification = 1;
    int total = 0;
    int flip = 1;
    string input = get_string("Number: ");
    int half = 0;

    do
    {
        if (verification == 0)
        {
            input = get_string("Number: ");
        }
        for (int test = 0; test < strlen(input); test++)
        {
            if ((!(input[test] == '0') && !(input[test] == '1') && !(input[test] == '2') &&
                 !(input[test] == '3') && !(input[test] == '4') && !(input[test] == '5') &&
                 !(input[test] == '6') && !(input[test] == '7') && !(input[test] == '8') &&
                 !(input[test] == '9')))
            {
                verification = 0;
            }
            else
            {
                verification = 1;
            }
        }
    }
    while (verification == 0);

    for (int every_other = strlen(input) - 1; every_other >= 0; every_other--)
    {
        if (flip == 0)
        {
            int number = ((input[every_other]) - '0') * 2;
            if (number >= 10)
            {
                half = half + 1;
                half = half + (number - 10);
            }
            else
            {
                half = half + number;
            }
            flip = 1;
        }
        else
        {
            total = total + ((input[every_other]) - '0');
            flip = 0;
        }
    }
    total = total + half;

    if (!((total % 10) == 0) || (strlen(input) < 13))
    {
        printf("INVALID\n");
    }
    else
    {
        if (input[0] == '4' && ((strlen(input) == 13) || (strlen(input) == 16)))
        {
            printf("VISA\n");
        }
        else if ((input[0] == '5') &&
                 ((input[1] == '1') || (input[1] == '2') || (input[1] == '3') ||
                  (input[1] == '4') || (input[1] == '5')) &&
                 (strlen(input) == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((input[0] == '3') && ((input[1] == '4') || (input[1] == '7')) &&
                 (strlen(input) == 15))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
