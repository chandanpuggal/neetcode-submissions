class Solution {
public:

    // LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=P6RZZMu_maU

    int longestConsecutive(vector<int>& nums) {
        // stored in ordered way
        map<int, bool> numsMap;

        for (int i = 0; i < nums.size(); i++) {
            numsMap[nums[i]] = true;
        }
        int maxCount = 0;
        int currCount = INT_MIN;
        int prev = INT_MIN;

        for (auto it = numsMap.begin(); it != numsMap.end(); it++) {
            // first iteration of Map
            if (prev == INT_MIN) {
                currCount = 1;
            } else {
                // If the consecutive numbers are found
                if (prev + 1 == it->first) {
                    currCount++;
                } else {
                    // consecutive are no more found
                    currCount = 1;
                }
            }
            prev = it->first;
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }
};
