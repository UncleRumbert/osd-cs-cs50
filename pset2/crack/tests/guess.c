#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const int alphabetSize = sizeof(alphabet) - 1;

static string toCrack;

void bruteImpl(char* str, int index, int maxDepth)
{

    for (int i = 0; i < alphabetSize; ++i)
    {
        str[index] = alphabet[i];

        if (index == maxDepth - 1)
        {
            if (!strcmp(toCrack, crypt(str, "50")))
            {
                printf("%s\n", str);
                break;
            }
        }
        else bruteImpl(str, index + 1, maxDepth);
    }
}

void bruteSequential(int maxLen)
{
    char* buf = malloc(maxLen + 1);

    for (int i = 1; i <= maxLen; ++i)
    {
        memset(buf, 0, maxLen + 1);
        bruteImpl(buf, 0, i);
    }

    free(buf);
}

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        toCrack = argv[1];
        printf("%s\n", bruteSequential(4));
        return 0;
    }
    else
    {
        printf("Usage: ./guess <hash>\n");
        return 1;
    }
}