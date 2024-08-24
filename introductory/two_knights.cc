#include <algorithm>
#include <iostream>

using namespace std;
static long long ways(int n) {
  if (n <= 1)
    return 0;
  if (n == 2)
    return 6;
  long long total = n * n;
  total = total * (total - 1) / 2;
  long long attacks = (n - 2) * ((n - 2) * 2 + 2);
  attacks += (n - 1) * (max(0, n - 4) * 2 + 2 + 2 * ((n >= 4) ? 1 : 0));
  return total - attacks;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << ways(i) << "\n";
  }
}