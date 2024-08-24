#include <iostream>

int main() {
  using namespace std;
  long long n;
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n - 1; ++i) {
    int t;
    cin >> t;
    s += t;
  }
  cout << n * (n + 1) / 2 - s << "\n";

  return 0;
}