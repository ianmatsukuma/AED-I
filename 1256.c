#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {

        int M, C;
        scanf("%d %d", &M, &C);

        Node* table[M];
        for (int i = 0; i < M; i++)
            table[i] = NULL;

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);

            int h = x % M;

            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = x;
            newNode->next = NULL;

            if (table[h] == NULL) {
                table[h] = newNode;
            } else {
                Node* cur = table[h];
                while (cur->next != NULL)
                    cur = cur->next;
                cur->next = newNode;
            }
        }

        // Impressão
        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            Node* cur = table[i];
            while (cur != NULL) {
                printf("%d -> ", cur->val);
                cur = cur->next;
            }
            printf("\\\n");
        }

        if (t < T - 1)
            printf("\n");
    }

    return 0;
}
