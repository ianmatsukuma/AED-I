#include <stdio.h>
#include <string.h>

int reverse_int(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int A, int B) {
    const int MAX = 10000; /* estados válidos: 0..9999 */
    static int q[20000];
    static int dist[10000];
    for (int i = 0; i < MAX; ++i) dist[i] = -1;

    int ini = 0, fim = 0;
    q[fim++] = A;
    dist[A] = 0;

    while (ini < fim) {
        int u = q[ini++];
        if (u == B) return dist[u];

        int v1 = u + 1;
        if (v1 < MAX && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            q[fim++] = v1;
        }

        int v2 = reverse_int(u);
        if (v2 < MAX && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            q[fim++] = v2;
        }
    }
    return -1; 
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}
