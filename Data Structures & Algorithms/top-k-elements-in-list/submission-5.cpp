// desc order comparator function
bool compFunction(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;
        vector<pair<int,int>> numsVector;
        vector<int> result;
        int vectorPosition = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(nums[i]) == numsMap.end()) {
                numsMap[nums[i]] = 1;
            } else {
                numsMap[nums[i]]++;
            }
        }

        for (auto it = numsMap.begin(); it != numsMap.end(); it++) {
            numsVector.push_back(make_pair(it->first, it->second));
        }

        sort(numsVector.begin(), numsVector.end(), compFunction);

        while(k != 0) {
            result.push_back(numsVector[vectorPosition].first);
            vectorPosition++;
            k--;
        }
        return result;
    }
};
