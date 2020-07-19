class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> tails(nums.size());
        int res = 0;
        for(auto num : nums) {
            int i = 0, j = res;
            while(i < j) {
                int mid = i + (j - i) / 2;
                if(tails[mid] < num) i = mid + 1;
                else j = mid;
            }
            tails[i] = num;
            if(res == i) res++;
        }
        return res;
    }
};