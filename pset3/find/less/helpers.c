/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 0) return false;

    for (int i = 0; i < n; i++)
    {
        if (value == values[i]) return true;
    }
    // END OF ANSWER
    return false;
}
chec
/**
 * Sorts array of n values.
 */
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
