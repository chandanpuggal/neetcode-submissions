class Solution {
public:

    // LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=1pkOgXD63yU

    int maxProfit(vector<int>& prices) {
        int currProfit = 0, maxProfit = 0, minBuyPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            currProfit = prices[i] - minBuyPrice;
            maxProfit = max(maxProfit, currProfit);
            minBuyPrice = min(minBuyPrice, prices[i]);
        }
        return maxProfit;
    }

};
