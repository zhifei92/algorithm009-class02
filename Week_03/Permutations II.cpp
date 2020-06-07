class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        helper(nums, ans, res, used);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, vector<bool>& used) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            res.push_back(nums[i]);
            used[i] = true;
            helper(nums, ans, res, used);
            res.pop_back();
            used[i] = false;
        }
        return;
    }
};