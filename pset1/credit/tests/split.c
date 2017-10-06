#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long number = get_long_long();

    printf("%lld", ((number % 1000) - (number % 100))/100);
}