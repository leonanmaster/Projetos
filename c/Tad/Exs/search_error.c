#include "../Pilha.h"

char fecho(char c) {
    if(c == '}') return '{';
    if(c == ']') return '[';
    if(c == ')') return '(';

}

void main(){
    int verificador = 0;
    char vet[100];
    Pilha* pilha = pilha_cria();

    scanf("%s", vet);
    
    for (int i = 0; vet[i] != '\0'; i++){
        if(vet[i] == '{' || vet[i] == '[' || vet[i] == '('){
            pilha_push(pilha, vet[i]);
        }else if(vet[i] == '}' || vet[i] == ']' || vet[i] == ')'){
            if (pilha_vazia(pilha)) {
                verificador++;  
                break;          
            } else if (pilha_pop(pilha) != fecho(vet[i])) {
                verificador++;  
                break;
            }
        }
    }
    
    if (!pilha_vazia(pilha)) {
        verificador++;
    }

    printf("Sua expressão apresenta %d erros de continuidade.", verificador);
    pilha_libera(pilha);
}