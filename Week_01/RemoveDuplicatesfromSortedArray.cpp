class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (0 == nums.size())
            return 0;
        int i = 1;
        for (int j = 1, target = nums[0]; j < nums.size(); j++) {
            if (target != nums[j]) {
                target = nums[j];
                nums[i++] = target;
            }
        }
        nums.erase(nums.begin() + i, nums.end());
        return i;
    }
};