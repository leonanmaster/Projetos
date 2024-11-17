#include "Lst.h"

typedef struct arvn Arvn;
struct arvn{
    char info;
    Arvn* prim;
    Arvn* prox;
};

// DO NOT EXIST THE CONCEPT OF FREE ARVN, 
// SO WE WONT TAKE CARE OF THIS CASE

Arvn* create_arvn (char c);
void insert_arvn (Arvn* tree, Arvn* stree);
void print_arvn (Arvn* tree);
int search_arvn (Arvn* tree, char c);
void free_arvn (Arvn* tree);

Arvn* create_arvn (char c){
    Arvn* arv = (Arvn*) malloc(sizeof(Arvn));
    arv->info = c;
    arv->prox = NULL;
    arv->prim = NULL;
    return arv;
}

void insert_arvn (Arvn* tree, Arvn* stree){
    stree->prox = tree->prim; //trata o caso da arvore ja ter filhos;
    tree->prim = stree;
}

void print_arvn (Arvn* tree){
    printf("<%c ", tree->info);
    Arvn* p;
    for (p = tree->prim; p != NULL; p = p->prox){
        print_arvn (p);
    }
    printf(">");
}

int search_arvn (Arvn* tree, char c){
    Arvn* p;
    if(tree->info == c){
        return 1;
    }else{
        for (p = tree->prim; p != NULL; p = p->prox){
            if(search_arvn(p,c)){
                return 1;
            }
        }
        return 0;
    }
    
}

void free_arvn (Arvn* tree){
    Arvn* p = tree->prim;
    while (p != NULL){
        Arvn* t = p->prox;
        free_arvn(p);
        p = t;
    }
    free(tree);
}