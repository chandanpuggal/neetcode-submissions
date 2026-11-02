class Solution {
public:

    // LeetCode: https://leetcode.com/problems/group-anagrams/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=vzdNOK2oB2E

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> stringMap;
        string sortedString;
        vector<vector<string>> finalStrings;

        for (int i = 0; i < strs.size(); i++) {
            sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());

            if(stringMap.find(sortedString) == stringMap.end()){ 
                vector<string> stringsVector;
                stringsVector.push_back(strs[i]);
                stringMap[sortedString] = stringsVector;
            } else {
                stringMap[sortedString].push_back(strs[i]);
            }
        }

        for (auto it = stringMap.begin(); it != stringMap.end(); it++) {
            finalStrings.push_back(it->second);
        }

        return finalStrings;
    }

};
