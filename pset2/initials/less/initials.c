#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    bool new_word = true;

    string name = get_string();

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