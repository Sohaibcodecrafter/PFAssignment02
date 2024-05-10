#include <stdio.h>

// Function to calculate Collatz sequence length
int collatzLength(int n) {
  int length = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    length++;
  }
  return length;
}

// Function to find starting number with longest Collatz sequence
int longestCollatzSequence(int N) {
  int maxLength = 0;
  int startNum = 0;
  for (int i = 1; i < N; i++) {
    int length = collatzLength(i);
    if (length > maxLength) {
      maxLength = length;
      startNum = i;
    }
  }
  return startNum;
}

int main() {
  int N;
  printf("Enter a limit N: ");
  scanf("%d", &N);
  int startNum = longestCollatzSequence(N);
  int length = collatzLength(startNum);
  printf("Starting number with longest Collatz sequence: %d\n", startNum);
  printf("Length of longest Collatz sequence: %d\n", length);
  return 0;
}
