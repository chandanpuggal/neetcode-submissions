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

    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if (s.compare(t) == 0) // both strings are equal
            return true;
        else
            return false;
    }

    // hashMap and Count
    
};
