#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <numeric>
#pragma GCC optimize("Ofast")
using namespace std;

static string path;
static constexpr int N = 48;
static constexpr int S = 7;
static bitset<64> visited;
static long long calls;
int visit(const string &path, int idx, int r, int c, char d) {
#ifdef CNT
  ++calls;
#endif
  if (idx == N) {
    return (r == S - 1 && c == 0) ? 1 : 0;
  }
  if (r == S - 1 && c == 0 && idx < N)
    return 0;

  auto reachable = [](int r, int c) {
    return r >= 0 && r < S && c >= 0 && c < S && visited[(r << 3) | c] == false;
  };

  if ((!reachable(r + 1, c) && d == 'D') ||
      (!reachable(r - 1, c) && d == 'U')) {
    if (reachable(r, c - 1) && reachable(r, c + 1))
      return 0;
  }

  if ((!reachable(r, c + 1) && d == 'R') ||
      (!reachable(r, c - 1) && d == 'L')) {
    if (reachable(r + 1, c) && reachable(r - 1, c))
      return 0;
  }

  visited[(r << 3) | c] = true;
  char dir = path[idx];
  int ret = 0;
  if (dir != '?') {
    int nr = r + (dir == 'U' ? -1 : (dir == 'D' ? 1 : 0));
    int nc = c + (dir == 'L' ? -1 : (dir == 'R' ? 1 : 0));
    if (reachable(nr, nc)) {
      ret = visit(path, idx + 1, nr, nc, dir);
    }
  } else
    ret = (reachable(r + 1, c) ? visit(path, idx + 1, r + 1, c, 'D') : 0) +
          (reachable(r - 1, c) ? visit(path, idx + 1, r - 1, c, 'U') : 0) +
          (reachable(r, c - 1) ? visit(path, idx + 1, r, c - 1, 'L') : 0) +
          (reachable(r, c + 1) ? visit(path, idx + 1, r, c + 1, 'R') : 0);
  visited[(r << 3) | c] = false;
  return ret;
}

int main() {
  cin >> path;
  cout << visit(path, 0, 0, 0, '\0') << "\n";
#ifdef CNT
  cout << calls << " calls\n";
#endif
  return 0;
}
