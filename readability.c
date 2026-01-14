#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string text, int length);
int words(string text, int length);
int sentences(string text, int length);

int main(void)
{
    string text = get_string("Text: ");

    int length = strlen(text);

    // Gets the amount of letters in the text

    int letter_count = letters(text, length);

    // Gets the amount of words in the text

    int word_count = words(text, length);

    // Gets the amount of sentences in the text

    int sentence_count = sentences(text, length);

    float A = ((float) letter_count / word_count) * 100;

    float B = ((float) sentence_count / word_count) * 100;
    int index = round(0.0588 * A - 0.296 * B - 15.8);

    // Grade

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
        printf("Grade %d\n", index);
    }
}

int letters(string text, int length)
{
    int letter_count = 0;
    for (int a = 0; a < length; a++)
    {
        if (isalpha(tolower(text[a])))
        {
            letter_count++;
        }
    }

    return letter_count;
}
int words(string text, int length)
{
    int word_count = 1;
    for (int a = 0; a < length; a++)
    {
        if (text[a] == ' ')
            word_count++;
    }
    return word_count;
}

int sentences(string text, int length)
{
    int sentence_count = 0;
    for (int a = 0; a < length; a++)
    {
        if (text[a] == '.' || text[a] == '!' || text[a] == '?')
        {
            sentence_count++;
        }
    }

    return sentence_count;
}
