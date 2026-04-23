class Solution {
public:
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