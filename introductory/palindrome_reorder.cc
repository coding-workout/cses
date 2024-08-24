#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> cnts('Z' + 1);
  for (char c : s)
    cnts[c]++;
  int odd = 0;
  for (int i = 'A'; i <= 'Z'; ++i) {
    if (cnts[i] & 1) {
      if (odd > 0) {
        cout << "NO SOLUTION\n";
        return 0;
      }
      odd = i;
    }
  }

  auto it = s.begin();
  for (int c = 'A'; c <= 'Z'; ++c) {
    if (cnts[c] && c != odd) {
      fill(it, it + cnts[c] / 2, c);
      it += cnts[c] / 2;
    }
  }
  if (odd > 0) {
    fill(it, it + cnts[odd], odd);
    it += cnts[odd];
  }
  for (int c = 'Z'; c >= 'A'; --c) {
    if (cnts[c] && c != odd) {
      fill(it, it + cnts[c] / 2, c);
      it += cnts[c] / 2;
    }
  }
  cout << s << "\n";
  return 0;
}