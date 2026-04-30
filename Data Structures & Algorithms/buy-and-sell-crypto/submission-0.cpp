class Solution {
public:

    // LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=1pkOgXD63yU

    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minBuy = prices[0], currentProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            currentProfit = prices[i] - minBuy;
            maxProfit = max(maxProfit, currentProfit);
            minBuy = min(minBuy, prices[i]);
        }
        return maxProfit;
    }
};
