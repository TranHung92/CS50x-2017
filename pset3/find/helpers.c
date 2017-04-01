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
    int end = n-1;
    int start = 0;
    while(end >= start)
    {
        int mid = (start + end) / 2;
        if(values[mid] == value)
        {
            return true;
        }
        else if (values[mid] > value)
        {
            end = mid - 1;
        }
        else 
        {
            start = mid + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int j=0; j<n-1; j++)
    {
        int iMin = j;
        for(int i=j+1; i<n; i++)
        {
            if(values[i] < values[iMin])
            {
                iMin = i;
            }
        }
        if(iMin != j)
        {
            int tmp = values[j];
            values[j] = values[iMin];
            values[iMin] = tmp;
        }
    }
    return;
}
