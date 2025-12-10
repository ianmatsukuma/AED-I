#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;


Node* insert(Node* root, int v) {
    if (root == NULL) {
        Node* n = (Node*) malloc(sizeof(Node));
        n->val = v;
        n->left = n->right = NULL;
        return n;
    }
    if (v < root->val)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);
    return root;
}


void preorder_format(Node* root, int *first) {
    if (!root) return;

    if (*first) { 
        printf("%d", root->val);
        *first = 0;
    } else {
        printf(" %d", root->val);
    }

    preorder_format(root->left, first);
    preorder_format(root->right, first);
}


void inorder_format(Node* root, int *first) {
    if (!root) return;

    inorder_format(root->left, first);

    if (*first) { 
        printf("%d", root->val);
        *first = 0;
    } else {
        printf(" %d", root->val);
    }

    inorder_format(root->right, first);
}


void postorder_format(Node* root, int *first) {
    if (!root) return;

    postorder_format(root->left, first);
    postorder_format(root->right, first);

    if (*first) { 
        printf("%d", root->val);
        *first = 0;
    } else {
        printf(" %d", root->val);
    }
}


void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {

        int N, v;
        scanf("%d", &N);

        Node* root = NULL;

        
        for (int i = 0; i < N; i++) {
            scanf("%d", &v);
            root = insert(root, v);
        }

        printf("Case %d:\n", caso);

        int first;

     
        first = 1;
        printf("Pre.: ");
        preorder_format(root, &first);
        printf("\n");

      
        first = 1;
        printf("In..: ");
        inorder_format(root, &first);
        printf("\n");

     
        first = 1;
        printf("Post: ");
        postorder_format(root, &first);
        printf("\n");

        printf("\n");

        freeTree(root);
    }

    return 0;
}
