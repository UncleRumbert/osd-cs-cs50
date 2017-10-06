#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change_return = -1.00;
    int change = 0;
    int coins = 0;

    while (change_return < 0)
    {
        printf("Change to return: $");
        change_return = get_float(); // Get non-negative input.
    }

    change = round(change_return * 100);

    while (change >= 25) // Quarters
    {
        change += -25;
        coins++;
    }

    while (change >= 10) // Dimes
    {
        change += -10;
        coins++;
    }

    while (change >= 5) // Nickels.
    {
        change += -5;
        coins++;
    }

    while (change >= 1) // Pennies
    {
        change += -1;
        coins++;
    }

    printf("%i\n", coins);
}