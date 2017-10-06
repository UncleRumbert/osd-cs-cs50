#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int value(char c)
{
    return tolower(c) - 97;
}

char shift(char c, string s, int place)
{
     if (c >= 'A' && c <= 'Z')
    {
        while (true)
        {
            if (place <= strlen(s) - 1)
            {
                if (c + value(s[place]) <= 'Z' && c + value(s[place]) >= 'A')
                {
                    return c + value(s[place]);
                }
                else
                {
                    c -= ('Z' - 'A') + 1;
                }
            }
            else
            {
                place = 0;
            }
        }
    }
    else if (c >= 'a' && c <= 'z')
    {
        while (true)
        {
            if (place <= strlen(s) - 1)
            {
                if (c + value(s[place]) <= 'z' && c + value(s[place]) >= 'a')
                {
                    return c + value(s[place]);
                }
                else
                {
                    c -= ('z' - 'a') + 1;
                }
            }
            else
            {
                place = 0;
            }
        }
    }
    else
    {
        return c;
    }
}

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i <= strlen(argv[1]) - 1; i++)
        {
            if (!((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
            {
                printf ("Usage: ./vigenere k");
                return 1;
            }
        }
        printf("plaintext: ");
        string plaintext = get_string();
        string key = argv[1];
        int s_place = 0;

        for (int i = 0; i <= strlen(plaintext) - 1; i++)
        {
            if (s_place <= strlen(key) - 1)
            {
                plaintext[i] = shift(plaintext[i], key, s_place);
                s_place++;
            }
            else
            {
                s_place = 0;
                plaintext[i] = shift(plaintext[i], key, s_place);
                s_place++;
            }
        }

        printf("ciphertext: %s\n", plaintext);
    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}