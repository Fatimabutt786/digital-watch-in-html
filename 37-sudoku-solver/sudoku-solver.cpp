class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) return false; // check column
            if(board[row][i] == c) return false; // check row
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false; // check 3x3 sub-box
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, row, col, c)) {
                            board[row][col] = c;

                            if(backtrack(board)) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false; // no valid digit found
                }
            }
        }
        return true; // all cells filled correctly
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};
