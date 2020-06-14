class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        return reveal(board, click[0], click[1]);
    }
    vector<vector<char>>& reveal(vector<vector<char>>& board, int x, int y) {
        if(!inBoard(x, y, board)) return board;
        if(board[x][y] == 'E') {
            int count = 0;
            if(inBoard(x - 1, y, board) && board[x - 1][y] == 'M') count++;
            if(inBoard(x + 1, y, board) && board[x + 1][y] == 'M') count++;
            if(inBoard(x, y - 1, board) && board[x][y - 1] == 'M') count++;
            if(inBoard(x, y + 1, board) && board[x][y + 1] == 'M') count++;
            if(inBoard(x - 1, y - 1, board) && board[x - 1][y - 1] == 'M') count++;
            if(inBoard(x - 1, y + 1, board) && board[x - 1][y + 1] == 'M') count++;
            if(inBoard(x + 1, y - 1, board) && board[x + 1][y - 1] == 'M') count++;
            if(inBoard(x + 1, y + 1, board) && board[x + 1][y + 1] == 'M') count++;
            if(count > 0) {
                board[x][y] = '0' + count;
            } else {
                board[x][y] = 'B';
                reveal(board, x - 1, y - 1);
                reveal(board, x - 1, y);
                reveal(board, x - 1, y + 1);
                reveal(board, x, y - 1);
                reveal(board, x, y + 1);
                reveal(board, x + 1, y - 1);
                reveal(board, x + 1, y);
                reveal(board, x + 1, y + 1);
            }
        }

        return board;
    }
    bool inBoard(int x, int y, vector<vector<char>>& board) {
        return x >= 0 && y >=0 && x < board.size() && y < board[0].size();
    }
};