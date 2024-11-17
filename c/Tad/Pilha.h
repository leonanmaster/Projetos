#include <stdlib.h>
typedef struct elemento Elemento;
struct elemento{
    char info;
    Elemento* prox;
};

typedef struct pilha Pilha;
struct pilha{
    Elemento* prim;
};

void pilha_libera(Pilha* p);
void pilha_push(Pilha* p, char dado);
char pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
Pilha * pilha_cria();

int pilha_vazia(Pilha* p){
    if(p->prim == NULL){
        return 1;
    }
    return 0;
}
void pilha_libera(Pilha* p){
    Elemento* x = p->prim;
    Elemento* y;
    while(x != NULL){
        y = x->prox;
        free(x);
        x = y;
    }
    free(p);
}

void pilha_push(Pilha* p, char dado){
    Elemento* novo_topo = (Elemento*) malloc(sizeof(Elemento));
    novo_topo->info = dado;
    novo_topo->prox = p->prim;
    p->prim = novo_topo;
}

char pilha_pop(Pilha* p){
    
    Elemento* excluindo;
    char valor_excluido;
    
    if (pilha_vazia(p)){
        return -1;
    }
    
    excluindo = p->prim;
    valor_excluido = excluindo->info; 
    p->prim = excluindo->prox;
    
    free(excluindo);        //tirando valor da pilha.
    
    return valor_excluido; //retorna valor tirado da pilha.
}

Pilha* pilha_cria(){
    
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}