#include <cs50.h>
#include <stdio.h>
#include <string.h>

char shift(char c, int key)
{
    if (c >= 'A' && c <= 'Z')
    {
        while (true)
        {
            if (c + key <= 'Z'&& c + key >= 'A')
            {
                return c + key;
            }
            else
            {
                c -= ('Z' - 'A');
            }
        }
    }
    else if (c >= 'a' && c <= 'z')
    {
        while (true)
        {
            if (c + key <= 'z' && c + key >= 'a')
            {
                return c + key;
            }
            else
            {
                c -= ('z' - 'a') + 1;
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
        printf("plaintext: ");
        string plaintext = get_string();
        int shift_num = atoi(argv[1]);

        for (int i = 0; i <= strlen(plaintext) - 1; i++)
        {
            plaintext[i] = shift(plaintext[i], shift_num);
        }

        printf("ciphertext: %s\n", plaintext);
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}