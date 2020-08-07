#include <stdio.h>

void swap(int*x, int *y){
    int tmp;
    printf("in swap() before\n");
    printf("x=%d, y=%d\n", x, y);
    printf("x=%d, y=%d\n", *x, *y);
    printf("&x=%d, &y=%d\n\n", &x, &y);
    tmp = *x;
    printf("tmp=%d\n", tmp);
    printf("&tmp=%d\n\n", &tmp);
    *x = *y;
    *y = tmp;
    printf("in swap() after\n");
    printf("x=%d, y=%d\n", x, y);
    printf("x=%d, y=%d\n", *x, *y);
    printf("&x=%d, &y=%d\n\n", &x, &y);
}

int main(void){
    int x, y;
    x=1;y=2;
    int *a=&x, *b=&y;

    printf("in main() before\n");
    printf("x=%d, y=%d\n", x, y);
    // printf("x=%d, y=%d\n", *x, *y);
    printf("&x=%d, &y=%d\n\n", &x, &y);
    // swap(&x, &y);
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("in main() after\n");
    printf("x=%d, y=%d\n", x, y);
    // printf("x=%d, y=%d\n", *x, *y);
    printf("&x=%d, &y=%d\n\n", &x, &y);
    return 0;
}