#include <iostream>

int main() {
  using namespace std;
  int n;
  cin >> n;
  if (n == 2 || n == 3) {
    cout << "NO SOLUTION\n";
    return 0;
  }

  for (int i = (n & 1) ? n : n - 1; i > 0; i -= 2) {
    cout << i << " ";
  }
  for (int i = (n >> 1) << 1; i; i -= 2) {
    cout << i << " ";
  }
  return 0;
}