class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }

    int mergesort(vector<int>& nums, int left, int right) {
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        int cnt = mergesort(nums, left, mid) + mergesort(nums, mid +1, right);
        merge(nums, left, mid, right, cnt);
        return cnt;
    }

    void merge(vector<int>& nums, int left, int mid, int right, int& cnt) {
        int i = left, k = 0, t = left;
        vector<int> tmp(right - left + 1, 0);
        for(int j = mid + 1; j <= right; j++) {
            while(t <= mid && nums[t] <= 2 * (long)nums[j]) t++;
            while(i <= mid && nums[i] < nums[j]) tmp[k++] = nums[i++];
            tmp[k++] = nums[j];
            cnt += mid - t + 1;
        }
        while(i <= mid) tmp[k++] = nums[i++];
        for(int& n : tmp) {
            nums[left++] = n;
        }
    }
};