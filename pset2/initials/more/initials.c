#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string sanitise(string s)
{
    int length = strlen(s);

    while (s[0] == ' ')
    {
        for (int i = 0; i < strlen(s) - 1; i++)
        {
            s[i] = s[i+1];
        }

        length--;
        printf("BEGINNING %d\n", length);
    }

    for (int i = 0; i < length - 1; i++)
    {
        if (s[i] == ' ' && s[i+1] == ' ')
        {
            for (int n = i; n < strlen(s) - 1; n++)
            {
                s[n] = s[n+1];
            }

            length--;
            printf("char %d in name activated MIDDLE %d\n", i,length);

            i = 0;
        }
    }

    if (s[length - 1] == ' ')
    {
        length--;
        printf("END %d\n", length);
    }

    for (int i = 0; i < strlen(s) - 1; i++)
    {
        if (i < length - 1)
        {
            s[i] = s[i];
        }
        else
        {
            s[i] = '\0';
        }
    }

    return s;
}

int main(void)
{
    bool new_word = true;

    string name = get_string();

    name = sanitise(name);

    if (name != NULL)
    {
        for (int i = 0; i <= strlen(name); i++)
        {
            if (new_word)
            {
                printf("%c", toupper(name[i]));
                new_word = false;
            }
            if (name[i] == ' ')
            {
                new_word = true;
            }
        }
    }

    printf("\n");
}