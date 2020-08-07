#include <stdio.h>
#include <stdlib.h>

void make_array(int *arr, int n);

int main(void){
    int n;
    int *a;
    scanf("%d", &n);    
    for (int i=0; i<n; i++){
        printf("%d\n", *a);
    }
    // printf("\n");
    make_array(a, n);
    // for (int i=0; i<n; i++){
    //     printf("%d\n", *a);
    // }

    return 0;
}

void make_array(int *arr, int n){
    for (int i=0; i<n; i++){
        // printf("%d\n", arr);        
        *arr = 2*i;
        arr++;
    }
}