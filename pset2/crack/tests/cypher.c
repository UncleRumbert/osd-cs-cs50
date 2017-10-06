#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        printf("Encrypting string '%s' into a cypher.\n", argv[1]);
        printf("%s\n", crypt(argv[1], "50"));
    }
    else
    {
        printf("Usage: ./cypher password");
        return 1;
    }
}