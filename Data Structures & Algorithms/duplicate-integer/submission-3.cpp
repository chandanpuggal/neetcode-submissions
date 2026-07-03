class Solution {
public:

    // LeetCode: https://leetcode.com/problems/contains-duplicate/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=3OamzN90kPg

    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> numsMap;

        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(nums[i]) == numsMap.end()) {
                numsMap[nums[i]] = true;
            } else {
                return true;
            }
        }

        return false;
    }
};