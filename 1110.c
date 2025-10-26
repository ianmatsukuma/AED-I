#include <stdio.h>

int main() {
    int n;
    const int MAX = 100; // tamanho da fila (suficiente para n <= 50)

    while (scanf("%d", &n) == 1 && n != 0) {
        int q[MAX];
        int front = 0, back = 0;

        // insere as cartas de 1 até n
        for (int i = 1; i <= n; i++) {
            q[back] = i;
            back = (back + 1) % MAX;
        }

        int descartadas[100];
        int qtdDesc = 0;

        // função manual para contar quantos elementos estão na fila
        int count = (back - front + MAX) % MAX;

        while (count > 1) {
            // descarta a primeira carta
            descartadas[qtdDesc++] = q[front];
            front = (front + 1) % MAX;

            // move a próxima carta para o final
            q[back] = q[front];
            back = (back + 1) % MAX;
            front = (front + 1) % MAX;

            // atualiza contagem
            count = (back - front + MAX) % MAX;
        }

        // imprime as cartas descartadas
        printf("Discarded cards:");
        if (qtdDesc > 0) {
            printf(" ");
            for (int i = 0; i < qtdDesc; i++) {
                printf("%d", descartadas[i]);
                if (i < qtdDesc - 1) printf(", ");
            }
        }
        printf("\n");

        // imprime a carta restante
        printf("Remaining card: %d\n", q[front]);
    }

    return 0;
}
