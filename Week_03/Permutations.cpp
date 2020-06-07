class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(nums, ans, res);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (isContain(res, nums[i])) continue;
            if (i > 0; nums[i] == nums[i - 1])
            res.push_back(nums[i]);
            helper(nums, ans, res);
            res.pop_back();
        }
        return;
    }

    bool isContain(vector<int>& res, int n) {
        return find(res.begin(), res.end(), n) != res.end();
    }
};