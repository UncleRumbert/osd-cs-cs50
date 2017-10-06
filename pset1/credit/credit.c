#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool checksum(long long cc)
{
    int checksum_1 = 0;
    int checksum_2 = 0;
    long long value = 0;
    bool other = false;

    for (long long i = 10; i <= cc * 10; i = i * 10)
    {
        value = ((cc % i) - (cc % (i / 10))) / (i / 10);

        if (other)
        {
            if (value * 2 < 10)
            {
                checksum_1 += value * 2;
                other = false;
            }
            else
            {
                checksum_1 += (value * 2) % 10;
                checksum_1++;
                other = false;
            }
        }
        else
        {
            checksum_2 += value;
            other = true;
        }
    }

    return ((checksum_1 + checksum_2) % 10 ==
            0); // Will return whether or not the credit card is valid.
}

int first_two_digits(long long cc)
{
    long long value = 0;
    long long last_value = 0;

    for (long long i = 1000; i <= cc * 10; i = i * 10)
    {
        last_value = value;
        value = ((cc % i) - (cc % (i / 10))) / (i / 10);
    }

    return (value * 10) + last_value; // Returns the first two digits of a number.
}

int first_digit(long long cc)
{
    long long value = 0;

    for (long long i = 1000; i <= cc * 10; i = i * 10)
    {
        value = ((cc % i) - (cc % (i / 10))) / (i / 10);
    }

    return value; // Returns the first digit of a number.
}

int main(void)
{
    long long credit_card = -1;

    while (credit_card <= 0)
    {
        printf("Input CC#: ");
        credit_card = get_long_long();
    }

    if (checksum(credit_card)) // Does it mathimatically check out as a card number?
    {
        if ((credit_card > 99999999999999 && credit_card <= 999999999999999) // Is it 15 digits long?
            && (first_two_digits(credit_card) == 34
                || first_two_digits(credit_card) == 37)) // Does it begin with either 34 or 37?
        {
            printf("AMEX\n");
        }
        else if ((credit_card > 999999999999999 && credit_card <= 9999999999999999) // Is it 16 digits long?
                 && (first_two_digits(credit_card) >= 51
                     && first_two_digits(credit_card) <= 55)) // Does it begin with any of 51 - 55, inclusive?
        {
            printf("MASTERCARD\n");
        }
        else if (((credit_card > 999999999999 && credit_card <= 9999999999999) // Is it 13 digits long?
                  || (credit_card > 999999999999999 && credit_card <= 9999999999999999)) // Is it 16 digits long?
                 && (first_digit(credit_card) == 4)) // Does it begin with 4?
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}