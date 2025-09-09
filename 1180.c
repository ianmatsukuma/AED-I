int main() {
  int N;
  int X[1000];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }
  int menor = X[0];
  int posicao = 1;
  for (int i = 1; i < N; i++) {
    if (X[i] < menor) {
      menor = X[i];
      posicao = i + 1;
    }
  }
  printf("Menor valor: %d\n", menor);
  printf("Posicao: %d\n", posicao);

  return 0;
}
