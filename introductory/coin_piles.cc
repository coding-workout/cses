#include <iostream>

using namespace std;

static void solve() {
  long long a, b;
  cin >> a >> b;
  long long A = 2 * b - a;
  long long B = 2 * a - b;
  cout << ((A >= 0 && B >= 0 && (A % 3 == 0) && (B % 3 == 0)) ? "YES" : "NO")
       << "\n";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}