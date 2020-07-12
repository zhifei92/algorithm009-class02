class Solution {
public:
    int totalNQueens(int n) {
        size = (1 << n) - 1;
        solve(0, 0, 0);
        return cnt;
    }
    void solve(int row, int ld ,int rd) {
        if(size == row) {
            cnt++;
            return;
        }
        int pos = size & (~(row | ld | rd));
        while(pos != 0) {
            int p = pos & (-pos);
            pos -= p;
            solve(row | p, (ld | p) << 1, (rd | p) >> 1);
        }
    }
private:
    int cnt = 0;
    int size = 0;
};