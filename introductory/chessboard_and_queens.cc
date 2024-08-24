#include <iostream>
#include <vector>

using namespace std;

static int queen(vector<string> &board, int row) {
  static int ret = 0;
  for (int c = 0; c < 8; ++c) {
    if (board[row][c] != '.')
      continue;
    bool ok = true;
    for (int j = 0; j < row && ok; ++j) {
      int d = row - j;
      if (board[j][c] == 'Q' || (c - d >= 0 && board[j][c - d] == 'Q') ||
          (c + d < 8 && board[j][c + d] == 'Q')) {
        ok = false;
      }
    }
    if (ok) {
      if (row == 7)
        ++ret;
      else {
        board[row][c] = 'Q';
        queen(board, row + 1);
        board[row][c] = '.';
      }
    }
  }
  return ret;
}

int main() {
  vector<string> board(8);
  for (auto &s : board) {
    cin >> s;
  }
  cout << queen(board, 0) << "\n";
  return 0;
}