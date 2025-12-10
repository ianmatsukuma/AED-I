#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Edge;

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int parent[200005], rankUF[200005];

void uf_init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankUF[i] = 0;
    }
}

int uf_find(int x) {
    if (parent[x] != x)
        parent[x] = uf_find(parent[x]);
    return parent[x];
}

void uf_union(int a, int b) {
    a = uf_find(a);
    b = uf_find(b);
    if (a == b) return;

    if (rankUF[a] < rankUF[b]) parent[a] = b;
    else if (rankUF[b] < rankUF[a]) parent[b] = a;
    else {
        parent[b] = a;
        rankUF[a]++;
    }
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) == 2 && (m || n)) {

        Edge *edges = malloc(sizeof(Edge) * n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }

        qsort(edges, n, sizeof(Edge), cmp);

        uf_init(m);

        long long mst_cost = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if (uf_find(u) != uf_find(v)) {
                uf_union(u, v);
                mst_cost += edges[i].w;
                count++;
                if (count == m - 1) break;
            }
        }

        printf("%lld\n", total - mst_cost);

        free(edges);
    }

    return 0;
}
