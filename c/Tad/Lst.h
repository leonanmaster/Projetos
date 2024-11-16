#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
struct lista {
    int info;
    Lista* prox;
};

Lista* create_lst(){
    return NULL;
}

Lista* insert_lst(Lista* lista, int val){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->prox = lista;
    novo->info = val;
    return novo;
}

Lista* del_elem(Lista* lista, int val){
    Lista* ant = NULL;
    Lista* p = lista;
    while (p != NULL && p->info != val){ 
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        printf("Não achou o elemento.\n");
        return lista;
    }
    if(ant == NULL){
        lista = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    printf("Elemento excluído.\n");
    return lista;
}

void del_lst(Lista* lista){
    Lista* p = lista;
    while (p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t; 
    }
}

void print_lst(Lista* lista){
    Lista* p = lista;
    while (p != NULL){
        printf("%d ", p->info);
        p = p->prox;
 
    }
}

Lista* search_lst(Lista* lista, int val){
    Lista* p;
    for(p = lista; p != NULL; p = p->prox){
        if(p->info == val){
            return p;
        }
    }
    return NULL;
}

Lista* lst_insert_sorted (Lista* lista, int val){
    Lista* p = lista;
    Lista* ant = NULL;
    while (p->info < val && p != NULL){
        ant = p;
        p = p->prox; 
    }
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
    if(ant == NULL){
        novo->prox = lista;
        lista = novo;
    } else{
        novo->prox = p;
        ant->prox = novo;
    }
    return lista;
}