class Solution {
public:
    // LeetCode: https://leetcode.com/problems/3sum/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=jzZsG8n2R9A&t=5s

    // HashMap and n^2 approach
    /*
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
    */

    // 3 pointer approach
    // sort and fix i
    // then move left & right to find sum
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int start = 0, end = 0, sum = 0;
        vector<vector<int>> result;
        map<vector<int>, bool> vectMap;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            start = i + 1;
            end = nums.size() - 1;
            while(start < end) {
                sum = nums[start] + nums[end] + nums[i];
                if (sum == 0) {
                    vector<int> curr = {nums[i], nums[start], nums[end]};
                    if (vectMap.find(curr) == vectMap.end()) {
                        result.push_back(curr);
                        vectMap[curr] = true;
                    }

                    while((start < end) && (nums[start] == nums[start+1]))
                        start++;

                    while((start < end) && (nums[end] == nums[end-1]))
                        end--;

                    start++;
                    end--;
                } else if (sum < 0) {
                    start++;
                } else
                    end--;
            }
        }
        return result;
    }
};
