class Solution {
public:
    // LeetCode: https://leetcode.com/problems/3sum/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: 

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> numbersMap;
        int sum;
        map<vector<int>, bool> vectMap;

        for (int i = 0; i < nums.size(); i++) {
            if (numbersMap.find(nums[i]) == numbersMap.end())
                numbersMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                sum = nums[i] + nums[j];
                auto it = numbersMap.find(0 - sum);
                if ((it != numbersMap.end()) && (it->second != i) && (it->second != j)) {
                    vector<int> numVector;
                    numVector.push_back(nums[i]);
                    numVector.push_back(nums[j]);
                    numVector.push_back(0-sum);
                    sort(numVector.begin(), numVector.end());
                    
                    if (vectMap.find(numVector) == vectMap.end()) {
                        result.push_back(numVector);
                        vectMap[numVector] = true;
                    }
                }
            }
        }
        return result;
    }
};
