#include <stdio.h>

#define INF 1000000000

int main() {
    int N, E;

    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        static int imp[501][501], dist[501][501];

        // inicializa matrizes
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                imp[i][j] = (i == j ? 0 : INF);

        // lê arestas impressas
        for (int i = 0; i < E; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            if (h < imp[x][y]) imp[x][y] = h;
        }

        // Floyd-Warshall para caminhos impressos
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                if (imp[i][k] < INF)
                    for (int j = 1; j <= N; j++)
                        if (imp[k][j] < INF &&
                            imp[i][j] > imp[i][k] + imp[k][j])
                            imp[i][j] = imp[i][k] + imp[k][j];

        // constrói dist com canais eletrônicos
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                if (imp[i][j] < INF && imp[j][i] < INF)
                    dist[i][j] = 0;       // mesmo país → instantâneo
                else
                    dist[i][j] = imp[i][j]; // senão usa caminho impresso
            }

        // Floyd-Warshall final
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                if (dist[i][k] < INF)
                    for (int j = 1; j <= N; j++)
                        if (dist[k][j] < INF &&
                            dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];

        int K;
        scanf("%d", &K);

        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);

            if (dist[O][D] >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[O][D]);
        }

        printf("\n");
    }

    return 0;
}
