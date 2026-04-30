class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = 0, currentArea;

        while (left < right) {
            currentArea = (right - left) * min(heights[left], heights[right]);
            maxArea = max(maxArea, currentArea);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
