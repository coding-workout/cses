#include <iostream>
#include <string>

int main() {
  using namespace std;
  string s;
  cin >> s;
  int ret = 1;
  char p = '\0';
  int cnts = 0;
  for (char c : s) {
    if (c == p)
      ++cnts;
    else {
      ret = max(ret, cnts);
      cnts = 1;
      p = c;
    }
  }
  ret = max(ret, cnts);
  cout << ret << endl;
}