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

int main(int argc, char *argv[]) {
  /* stub */
}
