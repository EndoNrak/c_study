#include <stdio.h>

struct human1{
    int height;
    int weight;
    int age;
    char *name;
    char *sex;  
};

typedef struct {
    char *name;
    char *sex;
    int age;
    int height;
    int weight;
} human2;

human2 init(char *name, char *sex, int age, int height, int weight) {
    human2 p2;
    p2.name = name;
    p2.sex = sex;
    p2.age = age;
    p2.height = height;
    p2.weight = weight;
    return p2;
}

int main(void){
    struct human1 tanaka;
    tanaka.name = "T.Tanaka";
    tanaka.age = 30;
    tanaka.weight = 92;
    tanaka.height = 198;
    tanaka.sex = "Male";
    printf("%d\n", tanaka.weight);

    human2 sato;
    human2 kobayashi = {"K.Kobayashi", "female", 12, 125, 36};
    human2 *p_sato = &sato, *p_kobayashi = &kobayashi;
    printf("%s\n", p_sato->name);
    sato = init("S.Sato", "Female", 65, 154, 57);
    printf("%s\n", p_sato->name);
    // printf("%s, %s", sato.sex, kobayashi.name);
    return 0;
}