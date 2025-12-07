#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        while (1) {
            int target[1001];
            scanf("%d", &target[0]);

            if (target[0] == 0) { 
                printf("\n");  // linha em branco após bloco
                break;
            }

            for (int i = 1; i < N; i++)
                scanf("%d", &target[i]);

            int stack[1001];
            int top = 0;
            int next = 1;  // próximo vagão vindo de A
            int possible = 1;

            for (int i = 0; i < N; i++) {
                int desired = target[i];

                // empilha até conseguir retirar o desejado
                while (next <= N && (top == 0 || stack[top - 1] != desired)) {
                    stack[top++] = next++;
                }

                // se o topo da pilha é o que queremos, retira
                if (top > 0 && stack[top - 1] == desired) {
                    top--;
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    
    return 0;
}
