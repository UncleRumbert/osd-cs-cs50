#include <cs50.h>
#include <stdio.h>

// Prints a row of the pyramid.
void pyramid_row(int l, int h)
{
    for (int i = 1; i < h - l; i++)
    {
        printf(" ");
    }
    for (int i = 0; i <= l + 1; i++)
    {
        printf("#"); // The character that makes up the row.
    }
    printf("\n");
}

int main(void)
{
    int height = -1;

    while (height < 0 || height > 23)
    {
        printf("Height: ");
        height = get_int(); // User input.
    }

    for (int i = 0; i < height; i++)
    {
        pyramid_row(i, height);
    }
}