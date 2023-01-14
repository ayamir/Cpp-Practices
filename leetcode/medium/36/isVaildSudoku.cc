#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[3][3][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                int num = c - '1';
                if (row[i][num] || col[j][num] || box[i / 3][j / 3][num]) {
                    return false;
                }
                row[i][num] = 1;
                col[j][num] = 1;
                box[i / 3][j / 3][num] = 1;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    auto ret = s.isValidSudoku(board);
    if (ret) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
