class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // Check first and last row
        for(int i = 0; i < cols; i++) {
            if(board[0][i] == 'O')
                DFS(board, 0, i);
            if(board[rows - 1][i] == 'O')
                DFS(board, rows - 1, i);
        }

        // Check first and last column
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O')
                DFS(board, i, 0);
            if(board[i][cols - 1] == 'O')
                DFS(board, i, cols - 1);
        }

        // Flip the remaining 'O' to 'X' and '#' back to 'O'
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

private:
    void DFS(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();

        if(i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O')
            return;

        board[i][j] = '#';

        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }
};
