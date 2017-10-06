#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long number = get_long_long();

    for (int i = 10; i <= number * 10; i = i * 10)
    {
        printf("%lld\n", ((number % i) - (number % (i/10))) / (i/10));
    }
}