#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long ELEM;

#define QUEUE_SIZE 100

ELEM queue[QUEUE_SIZE];
int front;
int rear;

#define next(a) ((a + 1) % QUEUE_SIZE)

void error(char *s) {
  fprintf(stderr, "error: %s\n", s);
  exit(1);
}

void init() {
  front = rear = 0;
}

void enqueue(ELEM x) {
  if (next(rear) == front) {
    error("Queue is overfrow\n");
  }
  queue[rear] = x;
  rear = next(rear);
}

ELEM dequeue() {
  ELEM x;

  if (front == rear) {
    error("Queue is empty\n");
  }
  x = queue[front];
  front = next(front);
  return x;
}

int isEmpty() {
  return front == rear;
}

int main(int argc, char *argv[]) {
  int c;
  long x, a, b;

  init();
  while((c = getchar()) != EOF) {
    if (isdigit(c)) {
      ungetc(c, stdin);
      scanf("%ld", &x);
      enqueue(x);
    } else {
      switch(c) {
        case '+':
          b = dequeue();
          a = dequeue();
          enqueue(a + b);
          break;
        case '-':
          b = dequeue();
          a = dequeue();
          enqueue(a - b);
          break;
        case '*':
          b = dequeue();
          a = dequeue();
          enqueue(a * b);
          break;
        case '/':
          b = dequeue();
          a = dequeue();
          enqueue(a / b);
          break;
        case '\n':
          if (!isEmpty()) {
            printf("Answer is: %ld\n", dequeue());
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
