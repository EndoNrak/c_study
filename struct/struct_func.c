#include <stdio.h>


typedef struct {
    char *sex;
    char *name;
    int age;
    int height;
    int weight;
    char *child_name;
    char *father_name;
    char *mother_name;
} human;

typedef struct{
    human mother;
    human father;
    human *children; 
}family;

void show_family(family *family, int children_num);
human mkchild(char *name, char *sex, int age, human father, human mother);
human init(char *name, char *sex, int age, int height, int weight);


human init(char *name, char *sex, int age, int height, int weight) {
    human p2;
    p2.name = name;
    p2.sex = sex;
    p2.age = age;
    p2.height = height;
    p2.weight = weight;
    return p2;
}

human mkchild(char *name, char *sex, int age, human father, human mother){
    human child;
    int height = (father.height + mother.height)/2;
    int weight = (father.weight + mother.weight)/2;
    child = init(name, sex, age, height, weight);
    father.child_name = name;
    mother.child_name = name;
    child.father_name = father.name;
    child.mother_name = mother.name;
    return child;
}

void show_family(family *family, int children_num){
    // int family_size = sizeof(family)/sizeof(human);
    // for(int i=0; i<family_size; i++){
    //     printf("%s\n", family[i].name);
    //     printf("%d\n%d\n\n", family[i].weight, family[i].height);
    // }
    
    printf("mum is %s\n", family->mother.name);
    printf("dad is %s\n", family->father.sex);
    
    // printf("they have %d children", sizeof(*(family->children))/sizeof(human)); // this line doesn't work as intended
    printf("they have %d children\n", children_num);
    human *p_child = family->children;
    for(int i=0; i<children_num; i++)printf("%s\n", (p_child+i)->name);
    // for(int i=0; i<children_num; i++)printf("%s\n", family->children[i].name);

    // printf("the first child is %s\n", family->children->name);
    // printf("the second child is %s\n", family->children[1].name);
    // pritnf("%s\n", family->children.name);

    // printf("%d\n", sizeof(human));
    // printf("%d\n", family);
    // printf("%s\n", family[0].name);
    // printf("%d\n", *(family+1));
    // printf("%s\n", );
    // printf("%d\n", &family);
    // printf("%d\n", &(family[0].height));
    // printf("%d\n\n", family[1]);   
}

int main(void){
    human kobayashi = {"K.Kobayashi", "Female", 24, 155, 48};
    human sato = init("S.Sato", "Male", 65, 164, 75);

    human wang = mkchild("Y. Wang", "Male", 3, sato, kobayashi);
    human xii = mkchild("C. Xii", "Male", 1, sato, kobayashi);
    human samuel = mkchild("C. Samuel", "Male", 1, sato, kobayashi);
    // family[2] = wang;
    human children[] = {wang, xii, samuel};
    // printf("%d\n", sizeof(children));
    // printf("%d\n", sizeof(human));
    family family1 = {sato, kobayashi, children};
    show_family(&family1, sizeof(children)/sizeof(human));
    return 0;
}