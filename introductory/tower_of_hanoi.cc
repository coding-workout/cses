#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves;
void move(int from, int to, int n) {
  if (n == 1) {
    moves.push_back({from, to});
    return;
  }
  int other = 6 - from - to;
  move(from, other, n - 1);
  move(from, to, 1);
  move(other, to, n - 1);
}
int main() {
  int n;
  cin >> n;
  move(1, 3, n);
  cout << moves.size() << "\n";
  for (const auto &m : moves)
    cout << m.first << " " << m.second << "\n";
}