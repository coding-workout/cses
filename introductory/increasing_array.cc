#include <iostream>

int main() {
  using namespace std;
  long long ret = 0;
  int n;
  cin >> n;
  long long prev;
  cin >> prev;
  for (int i = 1; i < n; ++i) {
    long long x;
    cin >> x;
    ret += (x < prev) ? prev - x : 0;
    prev = max(prev, x);
  }
  cout << ret << endl;
  return 0;
}