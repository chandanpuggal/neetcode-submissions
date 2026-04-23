class Solution {
public:

    // LeetCode: https://leetcode.com/problems/top-k-frequent-elements/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: 

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numsCount;
        map<int, vector<int>> countToNums;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (numsCount.find(nums[i]) == numsCount.end()) {
                numsCount[nums[i]] = 1;
            } else {
                numsCount[nums[i]]++;
            }
        }

        for (auto it = numsCount.begin(); it != numsCount.end(); it++) {
            if (countToNums.find(it->second) == countToNums.end()) {
                vector<int> vect;
                vect.push_back(it->first);
                countToNums[it->second] = vect;
            } else {
                countToNums[it->second].push_back(it->first);
            }
        }

        for (auto it = countToNums.rbegin(); it != countToNums.rend(); it++) {
            // if (k == 0)
            //     return result;

            vector<int> vect = it->second;
            for (auto it1 = vect.begin(); it1 != vect.end(); it1++) {
                if (k == 0)
                    return result;                
                result.push_back(*it1);
                k--;
            }
        }
        return result;
    }
};
