public class Solution {
    public int MaxArea(int[] heights) {
        int left = 0, right = heights.Length - 1;
        int maxWater = 0, currentWater;

        while (left < right) {
            currentWater = (right - left) * Math.Min(heights[left], heights[right]);
            maxWater = Math.Max(maxWater, currentWater);

            if (heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
}
