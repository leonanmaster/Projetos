#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char* str;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* retira (Lista* l, char* n){
    Lista* ant = NULL;
    Lista* lst = l;
    
    while(lst->str != NULL){
        if(strcmp(n, lst->str) == 0){
            if(ant == NULL){ 
                l = lst->prox; 
                free(lst); 
                lst = l;
            }else{
                ant->prox = lst->prox;
                free(lst);
                lst = ant->prox;
            }
        }else{
            ant = lst;
            lst = lst->prox;
        }
    }
    
    return l;;
}