class Solution {
public:

    // LeetCode: https://leetcode.com/problems/group-anagrams/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=vzdNOK2oB2E

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> stringMap;
        string temp;
        
        for (int i = 0; i < strs.size(); i++) {
            temp = strs[i];
            sort(temp.begin(), temp.end());

            if (stringMap.find(temp) == stringMap.end()) {
                vector<string> vect;
                vect.push_back(strs[i]);
                stringMap[temp] = vect;
            } else {
                stringMap[temp].push_back(strs[i]);
            }
        }

        vector<vector<string>> result;

        for (auto it = stringMap.begin(); it != stringMap.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};
