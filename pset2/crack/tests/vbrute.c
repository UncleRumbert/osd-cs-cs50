#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

string findPass(string init, string hash, int pos);

string brute(string p)
{
    string password = findPass("AAAA", p, 3);

    if (password != NULL)
    {
        return password;
    }
    else
    {
        password = findPass("AAA", p, 2);
    }

    if (password != NULL)
    {
        return password;
    }
    else
    {
        password = findPass("AA", p, 1);
    }

    if (password != NULL)
    {
        return password;
    }
    else
    {
        password = findPass("A", p, 0);
    }

    return NULL;
}

string findPass(string p, string hash, int pos)
{
    if (pos < 0)
    {
        printf("%s", p);
        return NULL;
    }

    for (p[pos] = 'A'; p[pos] <= 'Z'; p[pos]++)
    {
        if (p[pos] == '[')
        {
            p[pos] = 'a';
        }

        printf(""); // The entire script breaks if this print statement is removed. Not sure why.
        if (!strcmp(hash, crypt(p, "50")))
        {
            string password = p;
            return password;
        }

        findPass(p, hash, pos - 1);
    }

    return NULL;
}

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        printf("Password is '%s'.\n", brute(argv[1]));
    }
    else
    {
        printf("Usage: ./vbrute hash");
        return 1;
    }
}
