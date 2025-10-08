#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSAO 1001


int verifica_parenteses(const char *expressao) {
    char pilha[MAX_EXPRESSAO];
    int topo = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha[topo++] = '(';
        } else if (expressao[i] == ')') {
            if (topo == 0) {
                return 0; 
            }
            topo--; 
        }
    }

    return topo == 0; 
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
