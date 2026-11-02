class Solution {
public:

    // LeetCode: https://leetcode.com/problems/valid-anagram/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=9UtInBqnCgA

    // Sorting with complexity O(nlog(n))
    /*
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if (s.compare(t) == 0) // both strings are equal
            return true;
        else
            return false;
    }
    */ 

    // hashMap and count of each character
    // complexity O(n)
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        // unordered_map is better than ordered map
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (int i = 0; i < s.length(); i++) {
            if (sMap.find(s[i]) == sMap.end()) {
                sMap[s[i]] = 1;
            } else {
                sMap[s[i]]++;
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (tMap.find(t[i]) == tMap.end()) {
                tMap[t[i]] = 1;
            } else {
                tMap[t[i]]++;
            }
        }

        // compare function work internally like char or int comparaision.
        // This checks that:
            // Both maps have the same keys.
            // Each key has the same corresponding value.
        return (sMap == tMap);
    }
};
