class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int toFind = 0;
        for (int i = 0; i < nums.size(); i++) {
            toFind = target - nums[i];
            if (hash.find(toFind) != hash.end()) {
                return {hash[toFind], i};
            }
            hash[nums[i]] = i;
        }
        return{};
    }
};