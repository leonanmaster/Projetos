#include <stdio.h>
#include <stdlib.h>

typedef struct elem Elem;
struct elem{
    int info;
    Elem* prox;
};

typedef struct pilha_rpn Prpn;
struct pilha_rpn{
    Elem* prim;
};

Prpn* cria(){
    
    Prpn* p = (Prpn*) malloc(sizeof(Prpn));
    p->prim = NULL;
    return p;
}

void push(Prpn* p, int dado){
    Elem* novo_topo = (Elem*) malloc(sizeof(Elem));
    novo_topo->info = dado;
    novo_topo->prox = p->prim;
    p->prim = novo_topo;
}

int pop(Prpn* p){
    
    Elem* excluindo;
    char valor_excluido;
    
    if (p == NULL){
        return -1;
    }
    
    excluindo = p->prim;
    valor_excluido = excluindo->info; 
    p->prim = excluindo->prox;
    
    free(excluindo);        //tirando valor da pilha.
    
    return valor_excluido; //retorna valor tirado da pilha.
}

int op(char c, int n1, int n2){
    switch (c){
        case '+':
            return n1 + n2;
        case '-':
            return n2 - n1;
        case '*':
            return n1 * n2;
        case '/':
            return n2 / n1;
        
    }
}

void main(){
    int verificador = 0;
    char vet[100], num[3] = {'\0','\0','\0'};
    int n, x1 = 0, x2 = 0, result;
    Prpn* pilha = cria();

    fgets(vet, 99, stdin);
    
    int i = 0;
    int j = 0;

    for (i = 0; vet[i] != '\0'; i++){

        if(vet[i] <= '9' && vet[i] >= '0'){
            num[j++] = vet[i];
            if(vet[i+1] <= '9' && vet[i+1] >= '0' && vet[i+1] != '\0'){
                continue;
            }
            n = atoi(num);
            push(pilha, n);
            num[0] = '\0';
            num[1] = '\0';
            num[2] = '\0';
            j = 0;
        }
        
        if (vet[i] == '-' || vet[i] == '+' || vet[i] == '*' || vet[i] == '/'){
            x1 = pop(pilha);
            x2 = pop(pilha);
            result = op(vet[i], x1, x2);
            push(pilha, result);
        }
        
    }
    printf ("\n %d \n", pop(pilha));
}