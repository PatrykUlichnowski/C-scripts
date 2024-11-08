#include <stdio.h>

void swap(float *x, float *y){
    // float *temp = y;
    // y = &x;
    // x = &temp;
    float temp = *y;
    *y = *x;
    *x = temp;
}

int main(){
    float a = 5;
    float b = 10;
    printf("a = %f, b = %f\n", a, b);
    swap(&a, &b);
    printf("a = %f, b = %f\n", a, b);

    int tab[10] = { 2, 1, 5, 4, 2, 1, 8, 5, 8, 9};
    int *ptab = tab;
    for (int i = 0; i < (sizeof(tab)/sizeof(int)); i++)
    {
        printf("%d\n", ptab[i]);
    }
    
    return 0;
}