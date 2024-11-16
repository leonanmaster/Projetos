#include "Lst.h"

typedef struct lista2 Lista2; // Struct da lista duplamente encadeada:
struct lista2 { 
    int info;
    Lista2* ant;
    Lista2* prox;
};

// Listas circulares:

void print_circ_lst(Lista* lista){
    Lista* p = lista;
    if (p){
        printf("%d\n", p->info);
        p = p->prox;
        while(p != lista){
            printf("%d\n", p->info);
            p = p->prox;
        }
    }
}
/* versão da professora, mas a minha também funciona
{
    Lista* p = lst; 
    if (p) do {
        printf("%d\n", p->info); 
        p = p->prox; 
    } while (p != lst);
}
*/


// Listas duplamente encadeadas:

Lista2* insert_beg_lst(Lista2* lista, int val){ //insere no inicio
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = val;
    novo->prox = lista;
    novo->ant = NULL;
    if (lista != NULL){
        lista->ant = novo;
    }
    return novo;
}

Lista2* search_lst(Lista2* lista, int val){
    Lista2* p;
    for(p = lista; p != NULL; p = p->prox){
        if(p->info == val){
            return p;
        }
    }
    return NULL;
}

Lista2* del_elem_lst(Lista2* lista, int val){
    Lista2* p = lista;
    while(p != NULL){
        if(p->info == val){
            Lista2* del = p;
            if(p->ant == NULL){
                lista = p->prox;
                if(p->prox != NULL){
                    p->prox->ant = NULL;
                }
            }else if(p->prox == NULL){
                p->ant->prox = NULL;
            }else{
                p->prox->ant = p->ant;
                p->ant->prox = p->prox;
            }
            p = p->prox;
            free(del);
            printf("Elemento excluído.\n");
        }else{
            p = p->prox;
        }
    }
    return lista;
}
/* versão da professora, mas a minha também funciona
{
    Lista2* p = busca(lst,val);

    if (p == NULL)
    return lst;


    if (lst == p) 
        lst = p->prox;
    else
        p->ant->prox = p->prox;
    if (p->prox != NULL)
        p->prox->ant = p->ant;

    free(p);

    return lst;
}
*/