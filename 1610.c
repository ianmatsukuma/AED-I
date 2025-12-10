#include <stdio.h>
#include <string.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN], to[MAXM], next[MAXM];
int state[MAXN];
int edge_count;
int has_cycle;

void add_edge(int u, int v) {
    to[edge_count] = v;
    next[edge_count] = head[u];
    head[u] = edge_count++;
}

void dfs(int u) {
    state[u] = 1; // visitando
    for (int e = head[u]; e != -1; e = next[e]) {
        int v = to[e];
        if (state[v] == 1) { // ciclo
            has_cycle = 1;
            return;
        }
        if (state[v] == 0)
            dfs(v);
        if (has_cycle)
            return;
    }
    state[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {

        int N, M;
        scanf("%d %d", &N, &M);

        // inicializa estruturas
        memset(head, -1, sizeof(int) * (N + 1));
        memset(state, 0, sizeof(int) * (N + 1));
        edge_count = 0;

        // leitura das dependências
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        has_cycle = 0;

        // DFS para detectar ciclos
        for (int i = 1; i <= N && !has_cycle; i++) {
            if (state[i] == 0)
                dfs(i);
        }

        if (has_cycle)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
