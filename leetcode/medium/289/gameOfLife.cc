#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();
        int neighbors[3] = {0, 1, -1};
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int liveNeighbors = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (neighbors[i] != 0 || neighbors[j] != 0) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);
                            if ((r < m && r >= 0) && (c < n && c >= 0) &&
                                abs(board[i][j]) == 1) {
                                liveNeighbors++;
                            }
                        }
                    }
                }
                if ((board[row][col] == 1) &&
                    (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = -1;
                }
                if (board[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 2;
                }
            }
        }
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
