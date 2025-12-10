#include <stdio.h>
#include <stdlib.h>

int adj[26][26];
int vis[26];
int comp[26];

void dfs(int u, int V, int *cnt) {
    vis[u] = 1;
    comp[(*cnt)++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !vis[v]) dfs(v, V, cnt);
    }
}

int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int V, E;
        scanf("%d %d", &V, &E);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) adj[i][j] = 0;
            vis[i] = 0;
        }
        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int u = a - 'a', v = b - 'a';
            adj[u][v] = adj[v][u] = 1;
        }
        printf("Case #%d:\n", tc);
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                int cnt = 0;
                dfs(i, V, &cnt);
                qsort(comp, cnt, sizeof(int), cmp_int);
                for (int k = 0; k < cnt; k++) {
                    printf("%c,", (char)('a' + comp[k]));
                }
                printf("\n");
                components++;
            }
        }
        printf("%d connected components\n\n", components);
    }
    return 0;
}
