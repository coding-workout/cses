#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned m = 1 << n;
  for (unsigned i = 0; i < m; ++i) {
    int k = i, mask = m >> 1;
    for (int j = 0; j < n; ++j) {
      if (k & mask) {
        cout << '1';
        k = (mask - 1) - (k & (mask - 1));
      } else {
        cout << '0';
      }
      mask >>= 1;
    }
    cout << '\n';
  }
}