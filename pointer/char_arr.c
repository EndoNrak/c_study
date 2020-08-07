#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revert(char char_arr[]){
    printf("%d\n", sizeof(char_arr));
    // char *tmp[sizeof(char_arr)];
    char *tmp;
    printf("char_arr\n%d\n", char_arr[0]);
    printf("%d\n", &char_arr);
    printf("%s\n\n", char_arr);
    strcpy(tmp, char_arr);
    printf("tmp\n%d\n", &tmp);
    printf("%d\n", tmp);
    printf("%s\n", tmp);
    for(int i=0; i<sizeof(char_arr); i++){
        printf("%d\n", char_arr[i]);
        char_arr[i]=tmp[sizeof(char_arr)-1-i];
    }
    // printf("tmp\n%d\n", tmp);
    printf("%d\n", &tmp);
    printf("%s\n", tmp);
    printf("%d\n", char_arr);
    printf("%d\n", &char_arr);
    printf("%s\n\n", char_arr);
}

int main(void){
    char a[]="abcd"; 
    // char *p=a;
    // char *p="abcd";
    // printf("p\n%d\n", &p);
    // printf("%d\n", p);
    // printf("%s\n", p);
    revert(a);
    printf("%s\n", a);
    // char tmp[5];
    // strcpy(tmp, a);
    // for(int i=0; i<4; i++){
    //     a[i]=tmp[3-i];
    // }
    
    // printf("%s", a);
    // printf("%d\n", &a);
    // printf("%c\n", *(p+3));
    return 0;
}
