class Solution {
public:

    // LeetCode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=nIVW4P8b1VA

    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid = 0;

        while (left < right) {
            mid = left + (right - left)/2;

            // either vector is sorted or the current subset of l, r vector is sorted
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
