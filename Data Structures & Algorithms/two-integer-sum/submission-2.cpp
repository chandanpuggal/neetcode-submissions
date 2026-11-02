class Solution {
public:

    // LeetCode: https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=KLlXCFG5TnA

    vector<int> twoSum(vector<int>& nums, int target) {
        return hashMapApproach(nums, target);
    }

    vector<int> bruteForce(vector<int>& nums, int target) {
        int i, j;
        vector<int> result = {};
        for (i = 0; i < nums.size(); i++)
        {
            for (j = i+1; j < nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }

    vector<int> hashMapApproach(vector<int>& nums, int target) {

        // Map which store the number and it's index
        unordered_map<int, int> numsPositionMap;
        vector<int> result;
        int firstNumber;

        for (int i = 0; i < nums.size(); i++) {
            firstNumber = target - nums[i];
            if (numsPositionMap.find(firstNumber) == numsPositionMap.end()) {
                numsPositionMap[nums[i]] = i;
            } else {
                result.push_back(numsPositionMap[firstNumber]);
                result.push_back(i);
            }
        }
        return result;
    }
};
