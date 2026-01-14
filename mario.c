#include <cs50.h>
#include <stdio.h>

int main()
{
    int amount = 1;
    int height = 0;
    int check;
    do
    {
        height = get_int("Height: ");
    }
    while ((height <= 0) || (height >= 9));

    int space = height - 1;
    for (int row = 0; row < height; row++)
    {
        for (int spacing = 0; spacing < space; spacing++)
        {
            printf(" ");
        }
        space--;
        for (int side = 0; side < amount; side++)
        {
            printf("#");
        }
        printf("  ");
        for (int side = 0; side < amount; side++)
        {
            printf("#");
        }
        amount++;
        printf("\n");
    }
}
