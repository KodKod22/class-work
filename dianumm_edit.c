#include <stdio.h>

int main() {
  int N;

  printf("Enter number of rows\n");
  scanf("%d", &N);
  for (int k = 0; k <= N; k++)
  {
    for (int i = 0; i < N-k; i++)
      printf(" ");
    for (int i = k; i > 0; --i) {
      printf("%d", i);
    }
  }
    for (int i = 0; i <= k; ++i) {
      printf("%d", i);
    }
    printf("\n");
 for (int k = N-1; k >= 0; --k)
  {
    for (int i = 0; i < N-k; i++)
      printf(" ");
    for (int i = k; i > 0; --i) {
      printf("%d", i);
    }
    for (int i = 0; i <= k; ++i) {
      printf("%d", i);
    }
    printf("\n");
  }
  return 0;
}
