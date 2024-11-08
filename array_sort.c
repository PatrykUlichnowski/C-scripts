#include <stdio.h>


void swap(float *x, float *y)
{
    float temp = *y;
    *y = *x;
    *x = temp;
}

int index_of_min_val_in_array(float *t, int size, int start) 
{
    int min_val = start;
    for (int i = start + 1; i < size; i++)
    {
        if (t[i] < t[min_val])
        {
            min_val = i;
        }
    }
    return min_val;
}

void sort_array(float *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minval = index_of_min_val_in_array(tab, size, i);
        if (tab[minval] < tab[i])
        {
            swap(&tab[minval], &tab[i]);
        }
    } 
}

int main() 
{
    float tab1[5] = {2.5, 7.4, 11.1, 0.54, 0.1};
    // float lowest = min_val_in_array(tab1, (sizeof(tab1)/sizeof(tab1[0])));
    // printf("lowest value in the array is: %f\n", lowest);
    sort_array(tab1, (sizeof(tab1) / sizeof(*tab1)));
    for (int i = 0; i < (sizeof(tab1) / sizeof(*tab1)); i++)
    {
        printf("index %d = %f\n", i, tab1[i]);
    }
    return 0;
}