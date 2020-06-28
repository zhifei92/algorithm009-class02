class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        vector<int> dp;
        for(int left = 0; left < col; left++) {
            for(int right = left; right < col; right++) {
                for(int i = 0; i < row; i++) {
                    if(dp.size() < row) dp.resize(dp.size() + 1);
                    dp[i] += matrix[i][right];
                }
                res = max(res, maxSubArray(dp, k));
                if(res == k) return k;
            }
            dp.clear();
        }
        return res;
    }

    int maxSubArray(vector<int>& arr, int k) {
        if(arr[0] == k) return k;
        int dp = arr[0], maxSum = dp;
        for(int i = 1; i < arr.size(); i++) {
            dp = max(dp, 0) + arr[i];
            if(dp > maxSum) maxSum = dp;
        }
        if(maxSum <= k) return maxSum;
        int minor = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            int s = 0;
            for(int j = i; j < arr.size(); j++) {
                s += arr[j];
                if(s > minor && s <= k) minor = s;
                if(minor == k) return k;
            }
        }
        return minor;
    }
};