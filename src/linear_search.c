#include <stdio.h>
#include <stdlib.h>

struct {
  int key;
  int data;
} table[100];

int n;

int search(int key) {
  int i;

  i = 0;
  while (i < n) {
    if (table[i].key == key) {
      return (table[i].data); // found
    }
    i++;
  }
  return -1; // not found
}

void add(int key, int data) {
  if (n >= 100) {
    fprintf(stderr, "too much data\n");
    exit(1);
  }
  table[n].key  = key;
  table[n].data = data;
  n++;
}

int main(int argc, char *argv[]) {
  /* stub */
}
