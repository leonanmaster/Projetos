#include "Lst.h"

typedef struct fila Fila;
struct fila{
    Lista* ini;
    Lista* fim;
};

Fila* create_fila();
void insert_fila(Fila* fila, int val);
int del_elem_fila(Fila* fila);
int empty_fila(Fila* fila);
void free_fila(Fila* fila);

Fila* create_fila(){
    Fila* fl = (Fila*) malloc(sizeof(Fila)); 
    fl->fim = NULL;
    fl->ini = NULL;
    return fl;
}

void insert_fila(Fila* fila, int val){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = val;
    n->prox = NULL;
    if(fila->ini == NULL){
        fila->ini = n;
    }else{
        fila->fim->prox = n;
    }
    fila->fim = n;

}

int empty_fila(Fila* fila){
    if (fila->ini == NULL){
        return 1;
    }else{
        return 0;
    }
}

int del_elem_fila(Fila* fila){
    if(empty_fila(fila)){
        exit(1);
    }

    Lista* del = fila->ini;
    int dado = fila->ini->info;
    
    fila->ini = fila->ini->prox; 

    if(fila->ini == NULL){
        fila->fim = NULL;
    }

    free(del);
    return dado;
}

void free_fila(Fila* fila){
    Lista* x = fila->ini; 
    while(x != NULL){
        Lista* y = x->prox;
        free(x);
        x = y;
    }
    free(fila);
}