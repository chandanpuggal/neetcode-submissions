class Solution {
public:

    // LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=P6RZZMu_maU

    int longestConsecutive(vector<int>& nums) {
        map<int, bool> numsMap;

        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(nums[i]) == numsMap.end()) {
                numsMap[nums[i]] = true;
            } 
        }

        int prev = INT_MIN, maxCount = 0, currentCount = 0;

        for (auto it = numsMap.begin(); it != numsMap.end(); it++) {
            // starting case of Map with no Previous
            if (prev == INT_MIN) {
                currentCount = 1;
            }

            // found incremental value and increase currentCount 
            // else reset currentCount to 1 as it's first element
            if (it->first == prev + 1) {
                currentCount++;
            } else {
                currentCount = 1;
            }

            prev = it->first;
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }
};
