#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char val;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, char v) {
    if (root == NULL) {
        Node* n = (Node*) malloc(sizeof(Node));
        n->val = v;
        n->left = n->right = NULL;
        return n;
    }
    if (v < root->val)
        root->left = insert(root->left, v);
    else if (v > root->val)
        root->right = insert(root->right, v);
    return root;
}

int search(Node* root, char v) {
    if (root == NULL) return 0;
    if (v == root->val) return 1;
    if (v < root->val) return search(root->left, v);
    return search(root->right, v);
}

void inorder(Node* root, int *first) {
    if (!root) return;
    inorder(root->left, first);
    if (*first) { printf("%c", root->val); *first = 0; }
    else printf(" %c", root->val);
    inorder(root->right, first);
}

void preorder(Node* root, int *first) {
    if (!root) return;
    if (*first) { printf("%c", root->val); *first = 0; }
    else printf(" %c", root->val);
    preorder(root->left, first);
    preorder(root->right, first);
}

void postorder(Node* root, int *first) {
    if (!root) return;
    postorder(root->left, first);
    postorder(root->right, first);
    if (*first) { printf("%c", root->val); *first = 0; }
    else printf(" %c", root->val);
}

int main() {
    Node *root = NULL;
    char cmd[20];
    char x;

    while (scanf("%s", cmd) != EOF) {

        if (strcmp(cmd, "I") == 0) {
            scanf(" %c", &x);
            root = insert(root, x);
        }
        else if (strcmp(cmd, "P") == 0) {
            scanf(" %c", &x);
            if (search(root, x))
                printf("%c existe\n", x);
            else
                printf("%c nao existe\n", x);
        }
        else if (strcmp(cmd, "INFIXA") == 0) {
            int first = 1;
            inorder(root, &first);
            printf("\n");
        }
        else if (strcmp(cmd, "PREFIXA") == 0) {
            int first = 1;
            preorder(root, &first);
            printf("\n");
        }
        else if (strcmp(cmd, "POSFIXA") == 0) {
            int first = 1;
            postorder(root, &first);
            printf("\n");
        }
    }

    return 0;
}
