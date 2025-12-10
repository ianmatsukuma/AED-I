#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
    int w;
} Edge;

int parent[40000];
int rankUF[40000];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rankUF[a] < rankUF[b])
            parent[a] = b;
        else if (rankUF[a] > rankUF[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rankUF[a]++;
        }
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int M, N;

    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        Edge *edges = malloc(N * sizeof(Edge));

        for (int i = 0; i < M; i++) {
            parent[i] = i;
            rankUF[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].w);
        }

        qsort(edges, N, sizeof(Edge), cmp);

        long long mst_sum = 0;
        int edges_used = 0;

        for (int i = 0; i < N && edges_used < M - 1; i++) {
            int a = find(edges[i].x);
            int b = find(edges[i].y);
            if (a != b) {
                unite(a, b);
                mst_sum += edges[i].w;
                edges_used++;
            }
        }

        printf("%lld\n", mst_sum);
        free(edges);
    }

    return 0;
}
