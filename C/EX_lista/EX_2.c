#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char nome[81];
    float nota;
    struct lista *prox;
};
typedef struct lista Lista;

int aprovados (Lista* l){
    int ap = 0, alunos = 0;
    Lista* lst = l;
    while (lst != NULL){
        if(lst->nota >= 5.0){
            ap++;
            alunos++;
            lst = lst->prox;
        }else{
            alunos++;
            lst = lst->prox;
        }
    }
    if(alunos == 0){
        return 0;
    }
    return ap;
}