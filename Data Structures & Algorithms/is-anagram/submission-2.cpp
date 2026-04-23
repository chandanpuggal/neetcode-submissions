class Solution {
public:

    // LeetCode: https://leetcode.com/problems/valid-anagram/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=9UtInBqnCgA

    // Sorting
    /*
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return !s.compare(t);
    }
    */

    // hashMap and Count
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        map<char, int> sMap;
        map<char, int> tMap;

        for (int i = 0; i < s.length(); i++) {
            if (sMap.find(s[i]) == sMap.end()) {
                sMap[s[i]] = 1;
            } else {
                sMap[s[i]]++;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (tMap.find(t[i]) == tMap.end()) {
                tMap[t[i]] = 1;
            } else {
                tMap[t[i]]++;
            }
        }

        return (sMap == tMap);
    }
};
