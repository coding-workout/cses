#include <iostream>

using namespace std;
static void solve() {
  int r, c;
  cin >> r >> c;
  long long strain_id = max(r, c);
  int seq = min(r, c);
  bool sm_is_row = r < c;
  long long len = 2 * strain_id - 1;
  // strain len: 1, 3, 5, 7, 9
  long long strain_start = (strain_id - 1) * (strain_id - 1);
  bool up = strain_id & 1;
  if ((sm_is_row && up) || (!sm_is_row && !up))
    seq = len - seq + 1;
  cout << strain_start + seq << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}