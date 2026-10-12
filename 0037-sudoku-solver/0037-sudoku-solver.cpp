 
class Solution {
public:
    bool solve(vector<vector<char>>& board,
               bool rows[9][9],
               bool cols[9][9],
               bool boxes[9][9]) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;

                int box = (i / 3) * 3 + (j / 3);

                for (int d = 0; d < 9; d++) {
                    if (rows[i][d] || cols[j][d] ||
                        boxes[box][d]) {
                        continue;
                    }

                    board[i][j] = '1' + d;
                    rows[i][d] = true;
                    cols[j][d] = true;
                    boxes[box][d] = true;

                    if (solve(board, rows, cols, boxes)) {
                        return true;
                    }

                    // Backtrack
                    board[i][j] = '.';
                    rows[i][d] = false;
                    cols[j][d] = false;
                    boxes[box][d] = false;
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        // Record the existing digits
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int d = board[i][j] - '1';
                int box = (i / 3) * 3 + (j / 3);

                rows[i][d] = true;
                cols[j][d] = true;
                boxes[box][d] = true;
            }
        }

        solve(board, rows, cols, boxes);
    }
};
