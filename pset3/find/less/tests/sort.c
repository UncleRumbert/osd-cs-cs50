#include <cs50.h>
#include <stdio.h>

void sort(int values[], int n)
{
    int temp = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (values[i] > values[i + 1])
        {
            temp = values[i];
            values[i] = values[i + 1];
            values[i + 1] = temp;
            i = 0;
        }
    }

    return;
}

int main(void)
{
    int test[] = {18, 12, 14, 13, 17, 15, 16};
    sort(test, 7);

    for (int i = 0; i < 7; i++)
    {
        printf("%i\n", test[i]);
    }
}