#include "../Pilha.h"

int main() {
    Pilha* p = pilha_cria();
    pilha_push(p, 2);
    pilha_push(p, 3);
    pilha_push(p, 4);
    pilha_pop(p);
    pilha_push(p, 2);
    int a = pilha_pop(p) + pilha_pop(p);
    pilha_push(p, a);
    a += a;
    printf("%d", a);
    return 0;
}