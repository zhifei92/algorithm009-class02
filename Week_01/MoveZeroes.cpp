class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 1; j < nums.size(); j ++) {
            if (nums[i] != 0) {
                i++;
            } else if (nums[j] != 0) {
                nums[i++] = nums[j];
                nums[j] = 0;
            }
        }
    }
};