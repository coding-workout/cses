#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  vector<int> weights(n);
  for (auto &x : weights) {
    cin >> x;
    sum += x;
  }
  long long ret = sum;
  for (int i = 1, e = (1 << n) - 1; i <= e; ++i) {
    long long s = 0;
    for (int j = 0; j < n; ++j)
      s += ((1 << j) & i) ? weights[j] : 0;
    ret = min(ret, abs(s - sum + s));
  }

  cout << ret << "\n";
  return 0;
}