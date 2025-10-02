#include <stdio.h>
#include <string.h>

#define MAX 1000

int conta_diamantes(char *linha) {
    int pilha[MAX];
    int topo = -1;
    int diamantes = 0;

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            pilha[++topo] = '<';  // empilha
        } else if (linha[i] == '>') {
            if (topo >= 0) {
                topo--;           // desempilha
                diamantes++;      // encontrou um diamante
            }
        }
    }

    return diamantes;
}

int main() {
    int N;
    char linha[MAX];

    scanf("%d", &N);
    getchar();  // consome o \n após o número

    for (int i = 0; i < N; i++) {
        fgets(linha, MAX, stdin);
        linha[strcspn(linha, "\n")] = '\0';  // remove o \n
        printf("%d\n", conta_diamantes(linha));
    }

    return 0;
}
