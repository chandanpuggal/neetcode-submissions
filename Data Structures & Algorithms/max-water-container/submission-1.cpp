class Solution {
public:
    // LeetCode: https://leetcode.com/problems/container-with-most-water/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=UuiTKBwPgAo

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
