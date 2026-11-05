public class Solution {
    // LeetCode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=nIVW4P8b1VA

    public int FindMin(int[] nums) {
        int left = 0, right = nums.Length - 1;
        int mid = 0;

        while (left < right) {
            mid = (left + right)/2;

            if (nums[left] <= nums[right]) {
                return nums[left];
            }

            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
}
