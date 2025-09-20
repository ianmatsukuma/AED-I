#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 9

int linha_valida(int **matriz, int linha) {
    int vistos[TAMANHO + 1] = {0};
    for (int coluna = 0; coluna < TAMANHO; coluna++) {
        int valor = matriz[linha][coluna];
        if (valor < 1 || valor > 9 || vistos[valor]) return 0;
        vistos[valor] = 1;
    }
    return 1;
}

int coluna_valida(int **matriz, int coluna) {
    int vistos[TAMANHO + 1] = {0};
    for (int linha = 0; linha < TAMANHO; linha++) {
        int valor = matriz[linha][coluna];
        if (valor < 1 || valor > 9 || vistos[valor]) return 0;
        vistos[valor] = 1;
    }
    return 1;
}

int bloco_valido(int **matriz, int linha_inicial, int coluna_inicial) {
    int vistos[TAMANHO + 1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor = matriz[linha_inicial + i][coluna_inicial + j];
            if (valor < 1 || valor > 9 || vistos[valor]) return 0;
            vistos[valor] = 1;
        }
    }
    return 1;
}

int matriz_valida(int **matriz) {
    for (int i = 0; i < TAMANHO; i++) {
        if (!linha_valida(matriz, i) || !coluna_valida(matriz, i)) return 0;
    }
    for (int i = 0; i < TAMANHO; i += 3) {
        for (int j = 0; j < TAMANHO; j += 3) {
            if (!bloco_valido(matriz, i, j)) return 0;
        }
    }
    return 1;
}

int main() {
    int quantidade;
    scanf("%d", &quantidade);

    for (int instancia = 1; instancia <= quantidade; instancia++) {
        // Alocação dinâmica da matriz
        int **matriz = (int **)malloc(TAMANHO * sizeof(int *));
        for (int i = 0; i < TAMANHO; i++) {
            matriz[i] = (int *)malloc(TAMANHO * sizeof(int));
        }

        // Leitura dos valores da matriz
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // Verificação e saída
        printf("Instancia %d\n", instancia);
        if (matriz_valida(matriz)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        // Liberação da memória
        for (int i = 0; i < TAMANHO; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }

    return 0;
}
