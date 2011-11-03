#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long ELEM;

#define STACK_SIZE 100

ELEM stack[STACK_SIZE];
int n;

void error(char *s) {
  fprintf(stderr, "error: %s\n", s);
  exit(1);
}

void init() {
  n = 0;
}

void push(ELEM x) {
  if (n >= STACK_SIZE) {
    error("stack overflow\n");
  }
  stack[n++] = x;
}

ELEM pop() {
  if (n <= 0) {
    error("stack underflow\n");
  }
  return stack[--n];
}

int isEmpty() {
  return n == 0;
}

int main(int argc, char *argv[]) {
  int c;
  long x, a, b;

  init();
  while((c = getchar()) != EOF) {
    if (isdigit(c)) {
      ungetc(c, stdin);
      scanf("%ld", &x);
      push(x);
    } else {
      switch(c) {
        case '+':
          b = pop();
          a = pop();
          push(a + b);
          break;
        case '-':
          b = pop();
          a = pop();
          push(a - b);
          break;
        case '*':
          b = pop();
          a = pop();
          push(a * b);
          break;
        case '/':
          b = pop();
          a = pop();
          push(a / b);
          break;
        case '\n':
          if (!isEmpty()) {
            printf("Answer is: %ld\n", pop());
          }
          init();
          break;
        case ' ':
        case '\t':
          break;
        default:
          printf("invalid charastor inputed: %c\n", getchar());
          break;
      }
    }
  }
}
