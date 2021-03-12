#include <cmath>
#include <iostream>

using namespace std;

void reverse_array(int[], int);
void swap(int *, int *);

int main(int argc, char *argv[]) {
  int array[] = {1, 3, 2, 5, 4};
  int length = sizeof(array) / sizeof(array[0]);
  reverse_array(array, length);
  for (auto i : array) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

void reverse_array(int arr[], int length) {
  for (int i = 0; i < length / 2 + 1; i++) {
    swap(arr[i], arr[length - i - 1]);
  }
}

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *b ^ *a;
  *a = *a ^ *b;
}
