class Solution {
public:

    // LeetCode: https://leetcode.com/problems/product-of-array-except-self/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=bNvIQI2wAjk

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        // Keeps product of numbers on it's left 
        vector<int> leftProduct(nums.size(), 0);

        // Keeps product of numbers on it's right 
        vector<int> rightProduct(nums.size(), 0);

        leftProduct[0] = 1;
        rightProduct[nums.size() - 1] = 1;
        int i = 1;

        while(i < nums.size()) {
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
            i++;
        }

        i = nums.size() - 2;
        while (i >= 0) {
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
            i--;
        }

        for (i = 0; i < nums.size(); i++) {
            result[i] = leftProduct[i] * rightProduct[i];
        }
        return result;
    }
};
