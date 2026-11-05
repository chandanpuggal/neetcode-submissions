public class Solution {
    public int Search(int[] nums, int target) {
        int left = 0, right = nums.Length - 1, mid = 0;

        while (left <= right) {
            mid = left + (right - left)/2;

            if (nums[mid] == target)
                return mid;

            // left side is sorted
            if (nums[mid] >= nums[left]) {
                if ((nums[mid] >= target) && (nums[left] <= target)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if ((nums[mid] <= target) && (nums[right] >= target)) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
           }
        }
    return -1;
    }
}
