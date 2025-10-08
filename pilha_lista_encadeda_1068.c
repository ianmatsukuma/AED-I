#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSAO 1001


typedef struct No {
    char valor;
    struct No *prox;
} No;


void empilhar(No **topo, char valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}


int desempilhar(No **topo) {
    if (*topo == NULL) {
        return 0; 
    }
    No *temp = *topo;
    *topo = (*topo)->prox;
    free(temp);
    return 1;
}


int pilha_vazia(No *topo) {
    return topo == NULL;
}


int verifica_parenteses(const char *expressao) {
    No *pilha = NULL;

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (!desempilhar(&pilha)) {
                return 0; 
            }
        }
    }

    int resultado = pilha_vazia(pilha);

    
    while (pilha != NULL) {
        desempilhar(&pilha);
    }

    return resultado;
}

int main() {
    int N;
    char expressao[MAX_EXPRESSAO];

    if (scanf("%d", &N) != 1) return 1;
    getchar();

    for (int i = 0; i < N; i++) {
        if (fgets(expressao, MAX_EXPRESSAO, stdin) == NULL) break;

        size_t len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }

        if (verifica_parenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
