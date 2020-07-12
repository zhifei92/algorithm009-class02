class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals[0].size() == 0) return {};
        vector<vector<int>> merge;
        sort(intervals.begin(), intervals.end());
        merge.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            int left = intervals[i][0], right = intervals[i][1];
            if(left > merge.back()[1]) merge.push_back(intervals[i]);
            else merge.back()[1] = max(right, merge.back()[1]);
        }
        return merge;
    }
};