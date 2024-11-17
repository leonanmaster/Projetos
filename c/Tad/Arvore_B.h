#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;
struct arv{
    char info;
    Arv* esq;
    Arv* dir;
};

Arv* create_emp_arv();
Arv* create_arv(char dado, Arv* lef, Arv* rig);
Arv* free_arv(Arv* arv);
int empty_arv(Arv* arv);
int search_arv(Arv* arv, char dado);
void print_arv(Arv* arv);

Arv* create_emp_arv(){
    return NULL;
}

Arv* create_arv(char dado, Arv* lef, Arv* rig){
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    arv->info = dado;
    arv->esq = lef;
    arv->dir = rig;
    return arv;
}

int empty_arv(Arv* arv){
    return arv == NULL;
}

Arv* free_arv(Arv* arv){
    if (!empty_arv(arv)){
        free_arv(arv->esq);
        free_arv(arv->dir);
        free(arv);
    }
    return NULL;
}

int search_arv(Arv* arv, char dado){
    if(empty_arv(arv)){
        return 0;
    }else if (arv->info == dado){
        return 1;
    }else{
        return search_arv(arv->esq, dado) || search_arv(arv->dir, dado);
    }
}

void print_arv(Arv* arv){
    printf("<");
    if(!empty_arv(arv)){
        printf("%c ", arv->info);
        print_arv(arv->esq);
        print_arv(arv->dir);
    }
    printf(">");
}