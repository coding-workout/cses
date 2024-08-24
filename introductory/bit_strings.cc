#include <iostream>

using namespace std;

constexpr static int M = 1e9 + 7;

long long count(int n) {
  if (n == 1)
    return 2;
  return (count(n / 2) * count(n - n / 2)) % M;
}

int main() {
  int n;
  cin >> n;
  cout << count(n) << "\n";

  return 0;
}