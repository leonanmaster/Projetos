#include <stdio.h>
#include <stdlib.h>

struct lista {
    char* str;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* retira(Lista* lst, char* c){
    Lista* ant = NULL;
    Lista* p = lst;
    while(p != NULL){
        if(strcmp(c, p->str) == 0){
            if(ant == NULL){ 
                lst = p->prox; 
                free(p); 
                p = lst;
            }else{
                ant->prox = p->prox;
                free(p);
                p = ant->prox;
            }
        }else{
            ant = p;
            p = p->prox;
        }
    }
    return lst;
}

Lista* insereSort(Lista* lst, char* c){
    Lista* ant = NULL;
    Lista* p = lst;
    while (p != NULL && strcmp(c, p->str) > 0){
        ant = p;
        p = p->prox;
    }
    
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->str = c;

    if(ant != NULL){
        ant->prox = novo;
        novo->prox = p;
    }else{
        novo->prox = p;
        lst = novo;
    }

    return lst;
}
