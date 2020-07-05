class Solution {
public:
    Solution() {
        row = vector<set<char>>(9, {'1','2','3','4','5','6','7','8','9'});
        col = vector<set<char>>(9, {'1','2','3','4','5','6','7','8','9'});
        block = vector<set<char>>(9, {'1','2','3','4','5','6','7','8','9'});
    }

    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;

        vector<pair<int, int>> empty; // 收集需填数位置
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c == '.') empty.push_back({i, j});
                else {
                    row[i].erase(c);
                    col[j].erase(c);
                    block[(i / 3) * 3 + j / 3].erase(c);
                }
            }
        }
        backtrack(board, empty, 0);

    }

    bool backtrack(vector<vector<char>>& board, vector<pair<int, int>>& empty, int i) {
        if(i == empty.size()) return true;
        int x = empty[i].first, y = empty[i].second;
        int b = (x / 3) * 3 + y / 3;
        set<char> tmp, intersection;
        set_intersection(row[x].begin(), row[x].end(), col[y].begin(), col[y].end(), inserter(tmp, tmp.begin()));
        set_intersection(tmp.begin(), tmp.end(), block[b].begin(), block[b].end(), inserter(intersection, intersection.begin()));
        for(auto c : intersection) {
            row[x].erase(c);
            col[y].erase(c);
            block[b].erase(c);
            board[x][y] = c;
            if(backtrack(board, empty, i + 1)) return true;
            row[x].insert(c);
            col[y].insert(c);
            block[b].insert(c);
        }
        return false;
    }

private:
    vector<set<char>> row;
    vector<set<char>> col;
    vector<set<char>> block;
};