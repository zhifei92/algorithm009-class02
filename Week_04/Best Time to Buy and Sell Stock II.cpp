class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int profit = 0, buy = 0, sale = 0;
        int i = 0, len = prices.size() - 1;
        while(i < len) {
            while(i < len && prices[i] >= prices[i + 1]) i++;
            buy = prices[i];
            while(i < len && prices[i] <= prices[i + 1]) i++;
            sale = prices[i];
            profit += sale - buy;
        }
        return profit;
    }
};