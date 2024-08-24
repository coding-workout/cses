#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ret = 0;
  for (long long f = 5; f <= n; f *= 5) {
    ret += n / f;
  }
  cout << ret << "\n";
  return 0;
}