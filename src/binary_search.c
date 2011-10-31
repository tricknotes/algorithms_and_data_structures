struct {
  int key;
  int data;
} table[100];

int n;

int binary_search(int key) {
  int low, high, middle;

  low = 0;
  high = n - 1;

  while (low <= high) {
    middle = (low + high) / 2;
    if (key == table[middle].key) {
      return table[middle].data;
    } else if (key < table[middle].key) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
    return -1;
  }
}

int main(int argc, char *argv[]) {
  /* stub */
}
