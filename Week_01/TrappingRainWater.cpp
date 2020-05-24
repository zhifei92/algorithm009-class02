class Solution {
public:
    int trap(vector<int>& height)
    {
        if (height.size() < 3)
            return 0;
        stack<int> st;
        st.push(0);
        int ans = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = i - st.top() - 1;
                int high = min(height[st.top()], height[i]) - height[top];
                ans += high * distance;
            }
            st.push(i);
        }
        return ans;
    }
};