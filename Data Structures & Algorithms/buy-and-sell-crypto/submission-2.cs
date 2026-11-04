public class Solution {
    public int MaxProfit(int[] prices) {
        int buy = prices[0];
        int mProfit = 0;

        for (int i = 0; i < prices.Length; i++) {
            mProfit = Math.Max(mProfit, prices[i] - buy);
            buy = Math.Min(buy, prices[i]);
        }
        return mProfit;
    }
}
