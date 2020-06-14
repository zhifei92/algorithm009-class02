class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, i = 0;
        while(child < g.size() && i < s.size()) {
            if(s[i] >= g[child]) child++;
            i++;
        }
        return child;
    }
};