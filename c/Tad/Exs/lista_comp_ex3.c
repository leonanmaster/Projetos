#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    char nome[50];
    char servico[50];
    struct Cliente* prox;
} Cliente;

typedef struct Fila {
    Cliente* ini;
    Cliente* fim;
} Fila;

Fila* criarFila(){
    Fila* fl = (Fila*) malloc(sizeof(Fila));
    fl->fim = NULL;
    fl->ini = NULL; 
    return fl;
}

int isEmpty(Fila* fila){
    return fila->ini == NULL;
}

void enqueue(Fila* fila, char* nome, char* servico){
    Cliente* novoc = (Cliente*) malloc(sizeof(Cliente));
    strcpy(nome, novoc->nome);
    strcpy(servico, novoc->servico);
    novoc->prox = NULL;
    if(fila->ini == NULL){
        fila->ini = novoc;
        fila->fim = novoc;
    }else{
        fila->fim->prox = novoc;
        fila->fim = novoc; 
    }
}

void dequeue(Fila* fila){
    if(isEmpty(fila)){
        return;
    }

    Cliente* p = fila->ini;
    if(fila->ini == fila->fim){
        fila->ini = NULL;
        fila->fim = NULL;
    }else{
        fila->ini = p->prox;
    }
    printf("Nome: %s ", p->nome);
    printf("| Serv: %s \n", p->servico);
    free(p);
}

void printQueue(Fila* fila){
    if(isEmpty(fila)){
        return;
    }

    Cliente* p = fila->ini;

    while(p != NULL){
        printf("Endereço do nó: %p\n", p);
        printf("Nome: %s ", p->nome);
        printf("| Serv: %s \n", p->servico);
        p = p->prox;
    }
}

void main(){
    Fila* fl = criarFila();
    
    int op;
    
    while(1){
        printf("(1) Adicionar um cliente à fila. \n");
        printf("(2) Atender o próximo cliente. \n");
        printf("(3) Exibir os clientes na fila. \n");
        printf("(4) Sair do programa. \n");

        scanf("%d", &op);

        switch(op){
            case 1:
                char nome1[50] = {'a'};
                char serv1[50] = {'a'};
                char nome2[50] = {'b'};
                char serv2[50] = {'b'};

                /*printf("Nome: ");
                scanf("%s", nome);
                nome[strcspn(nome, "\n")] = 0;
                
                printf("Serv: ");
                scanf("%s", serv);
                nome[strcspn(nome, "\n")] = 0;*/

                enqueue(fl, nome1, serv1);
                enqueue(fl, nome2, serv2);

                printf("\n");
                break;
            case 2:     
                dequeue(fl);
                break;
            case 3:
                printQueue(fl);
                break;
            case 4:
                while (!isEmpty(fl)) {
                    dequeue(fl); 
                }
                free(fl);
                exit(1);
                break;
        }
    }
}