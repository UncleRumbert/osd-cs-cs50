#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initializing variables.
    int flow = 192; // Assuming low flow showerhead at 1.5 gal or 192 oz.
    int bottle = 16; // Assuming 16oz bottles.
    int time = 0;

    // Get user's time in the shower in minutes.
    printf("Minutes: ");
    time = get_int();
    printf("Bottles: %d\n", (flow * time) / bottle);
}