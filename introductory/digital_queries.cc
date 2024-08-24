#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static vector<unsigned long long> sums{0}, pow10{1};

static void solve() {
  unsigned long long k;
  cin >> k;
  for (int len = sums.size() - 1; len >= 1; --len) {
    if (k <= sums[len] && k > sums[len - 1]) {
      k -= sums[len - 1];
      unsigned long long number = pow10[len - 1] + ((k - 1) / len);
      int offset = (k - 1) % len + 1;
      cout << (number / pow10[len - offset]) % 10 << "\n";
      return;
    }
  }
}

int main() {
  for (unsigned long long k = 9, s = 0; s <= 1e18; k += 9) {
    auto e = pow10.back();
    s += k * e;
    sums.push_back(s);
    pow10.push_back(e * 10);
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();

  return 0;
}