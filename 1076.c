#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int u, v;
    struct Pair *next;
} Pair;

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int start;
        scanf("%d", &start);
        int V, A;
        scanf("%d %d", &V, &A);

        
        int maxV = V > 50 ? V : 50; 
        Pair **buckets = (Pair**) calloc(maxV, sizeof(Pair*));

        
        int cap = A + 5;
        int *eu = (int*) malloc(sizeof(int) * cap);
        int *ev = (int*) malloc(sizeof(int) * cap);
        int unique = 0;

        for (int i = 0; i < A; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            int x = a < b ? a : b;
            int y = a < b ? b : a;
         
            int found = 0;
            if (x < maxV) {
                for (Pair *p = buckets[x]; p != NULL; p = p->next) {
                    if (p->u == x && p->v == y) { found = 1; break; }
                }
            }
            if (!found) {
                Pair *pnew = (Pair*) malloc(sizeof(Pair));
                pnew->u = x; pnew->v = y;
                pnew->next = buckets[x];
                buckets[x] = pnew;
                if (unique >= cap) {
                    cap *= 2;
                    eu = (int*) realloc(eu, sizeof(int) * cap);
                    ev = (int*) realloc(ev, sizeof(int) * cap);
                }
                eu[unique] = x;
                ev[unique] = y;
                unique++;
            }
        }

        
        int *deg = (int*) calloc(V, sizeof(int));
        for (int i = 0; i < unique; i++) {
            deg[eu[i]]++;
            deg[ev[i]]++;
        }
        Pair **adj = (Pair**) malloc(sizeof(Pair*) * V);
        for (int i = 0; i < V; i++) adj[i] = NULL;
        for (int i = 0; i < unique; i++) {
            int x = eu[i], y = ev[i];
            Pair *p1 = (Pair*) malloc(sizeof(Pair)); p1->u = y; p1->v = -1; p1->next = adj[x]; adj[x] = p1;
            Pair *p2 = (Pair*) malloc(sizeof(Pair)); p2->u = x; p2->v = -1; p2->next = adj[y]; adj[y] = p2;
        }

      
        int *seen = (int*) calloc(V, sizeof(int));
        int *stack = (int*) malloc(sizeof(int) * V);
        int top = 0;
        if (start >= 0 && start < V) {
            stack[top++] = start;
            seen[start] = 1;
        }
        while (top > 0) {
            int u = stack[--top];
            for (Pair *p = adj[u]; p != NULL; p = p->next) {
                int w = p->u;
                if (!seen[w]) {
                    seen[w] = 1;
                    stack[top++] = w;
                }
            }
        }

       
        int cnt = 0;
        for (int i = 0; i < unique; i++) {
            if (eu[i] >= 0 && eu[i] < V && ev[i] >= 0 && ev[i] < V) {
                if (seen[eu[i]] && seen[ev[i]]) cnt++;
            }
        }

        printf("%d\n", 2 * cnt);

        
        for (int i = 0; i < maxV; i++) {
            Pair *p = buckets[i];
            while (p) {
                Pair *t = p; p = p->next; free(t);
            }
        }
        free(buckets);

        for (int i = 0; i < V; i++) {
            Pair *p = adj[i];
            while (p) { Pair *t = p; p = p->next; free(t); }
        }
        free(adj);
        free(eu); free(ev); free(deg); free(seen); free(stack);
    }
    return 0;
}
