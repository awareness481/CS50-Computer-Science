/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
 
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (value == values[mid]) {
            return true;
        } else if(value < values[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;

}

/**
 * Sorts array of n values.
 */

void sort(int values[], int n) {
    if (n < 2) {
        printf("Error\n");
        return;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    
   
    for (int i = 0; i < n; i++) {
        count[values[i]]++;
    }
    
    for (int i = 1; i <= max + 1; i++) {
        count[i] = count[i] + count[i-1];
    }
    
    int temp[n];
    for (int i = n-1; i >= 0; i--) {
        temp[count[values[i]]-1] = values[i];
        count[values[i]] = count[values[i]] - 1;
    }

    memcpy(values, temp, sizeof temp); //Should I should memmove?

}
