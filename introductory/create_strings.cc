#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<string> ret;
void permute(vector<int> &cnts, string &s, int n) {
  for (int i = 0; i < 26; ++i) {
    if (cnts[i]) {
      s += 'a' + i;
      --cnts[i];
      permute(cnts, s, n);
      s.pop_back();
      ++cnts[i];
    }
  }
  if (s.size() == n)
    ret.push_back(s);
}
int main() {
  string str;
  vector<int> cnts(26);
  cin >> str;
  for (char c : str)
    ++cnts[c - 'a'];
  int n = str.size();
  str.clear();
  permute(cnts, str, n);
  cout << ret.size() << "\n";
  for (const auto &s : ret)
    cout << s << "\n";

  return 0;
}