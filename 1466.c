#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int v) {
    if (root == NULL) return newNode(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

typedef struct {
    Node* data[600];   // até 500 níveis, sobra espaço
    int front, back;
} Queue;

void initQueue(Queue* q) {
    q->front = q->back = 0;
}

void push(Queue* q, Node* n) {
    q->data[q->back++] = n;
}

Node* pop(Queue* q) {
    return q->data[q->front++];
}

int empty(Queue* q) {
    return q->front == q->back;
}

int main() {
    int C, N, val;

    scanf("%d", &C);

    for (int c = 1; c <= C; c++) {
        scanf("%d", &N);

        Node* root = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &val);
            root = insert(root, val);
        }

        printf("Case %d:\n", c);

        // BFS
        Queue q;
        initQueue(&q);
        push(&q, root);

        int first = 1;

        while (!empty(&q)) {
            Node* cur = pop(&q);

            if (first) {
                printf("%d", cur->val);
                first = 0;
            } else {
                printf(" %d", cur->val);
            }

            if (cur->left) push(&q, cur->left);
            if (cur->right) push(&q, cur->right);
        }

        printf("\n\n"); // linha em branco após cada caso
    }

    return 0;
}
