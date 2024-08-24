#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long s = (1 + n) * n / 2;
  if (s & 1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (n & 1) {
    cout << (n / 2 + 1) << "\n";
    cout << "1 2";
    for (int i = 4; i <= n; i += 4) {
      cout << " " << i << " " << i + 3;
    }
    cout << "\n" << n / 2 << "\n";
    cout << "3";
    for (int i = 5; i <= n; i += 4) {
      cout << " " << i << " " << i + 1;
    }
  } else {
    cout << n / 2 << "\n";
    for (int i = 1; i <= n; i += 4)
      cout << i << " " << i + 3 << " ";
    cout << "\n" << n / 2 << "\n";
    for (int i = 2; i <= n; i += 4)
      cout << i << " " << i + 1 << " ";
  }
  cout << "\n";
  return 0;
}