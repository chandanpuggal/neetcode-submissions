class Solution {
public:
    // LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=U8XENwh8Oy8

    int search(vector<int>& nums, int target) {
        int index = -1;
        int left = 0, right = nums.size() - 1, mid = 0;

        while (left <= right) {
            mid = left + (right - left)/2;

            if (nums[mid] == target)
                return mid;

            // left portion is sorted
            if (nums[mid] >= nums[left])  {
                if ((nums[mid] >= target) && (nums[left] <= target)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if ((target >= nums[mid]) && (target <= nums[right])) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }      
        }
        return -1;
    }
};
