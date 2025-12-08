#include <stdio.h>
#include <stdlib.h>

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // ordena em ordem decrescente
}

int main() {
    int N; // número de casos
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        int original[M];
        int ordenado[M];

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i]; // copia para ordenar
        }

        // Ordena o vetor em ordem decrescente
        qsort(ordenado, M, sizeof(int), compare_desc);

        int cont = 0;
        // Compara posições
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i])
                cont++;
        }

        printf("%d\n", cont);
    }

    return 0;
}
