#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool key_check(string key);
void cypher(string text, string key);

int main(int argc, string argv[])
{
    bool c = false;
    // check if there is a key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        c = true;
        return 1;
    }
    // if there is a key
    if (c != true)
    {
        // check if the key is up to standard
        bool c2 = key_check(argv[1]);
        // if not
        if (c2 == true)
        {
            return 1;
        }
        // if it is
        else
        {
            // get the text
            string text = get_string("Text: ");
            // cypher the text
            cypher(text, argv[1]);
        }
    }
    return 0;
}

bool key_check(string key)
{
    bool c = false;
    int d = strlen(key);
    // check lenght of the key
    if (d == 26)
    {
        for (int a = 0; a < d; a++)
        {
            // check if the character of the key is in the alphabet and if no other character has
            // been detected as not in the alphabet
            if ((!(isalpha(tolower(key[a]))) && (c != true)))
            {
                c = true;
            }
            // if it is a charater in the alphabet and no other character has been detected as not
            // in the alphabet
            else if ((isalpha(tolower(key[a])) && (c != true)))
            {
                // check if the character has any duplicates in the rest of the key
                for (int e = a + 1; e < d; e++)
                {
                    if (tolower(key[a]) == tolower(key[e]))
                    {
                        c = true;
                    }
                }
            }
        }
        if (c == true)
        {
            printf("Usage: ./substitution key\n");
        }
    }
    // if the key is not 26 charaters long
    else
    {
        printf("Key must contain 26 characters.\n");
        c = true;
    }
    return c;
}

void cypher(string text, string key)
{
    int d = strlen(text);
    string cypherd = text;
    // replace the letter to the corresponding alphabet one of the key
    for (int a = 0; a < d; a++)
    {
        int ascii = tolower(text[a]);

        if ((islower(text[a])) && (isalpha(text[a])))
        {
            cypherd[a] = tolower(key[ascii - 97]);
        }
        if ((isupper(text[a])) && (isalpha(text[a])))
        {
            cypherd[a] = toupper(key[ascii - 97]);
        }
    }
    printf("ciphertext: %s\n", cypherd);
}
