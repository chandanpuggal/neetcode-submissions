class Solution {
public:
    // LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=wiGpQwVHdE0

    int lengthOfLongestSubstring(string s) {
        map<char, int> positionMap;
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            auto it = positionMap.find(s[i]);
            // if not found, just map char position in hashmap
            if (it == positionMap.end()) {
                positionMap[s[i]] = i;
            } else {
            // If found duplicate, move start to max position of start and move the duplicate char 
            // position to new position.
                start = max(start, it->second + 1);
                // in case like abba, you can't move start from 2 to 1 after 
                // finding conflict of 'a' after 'b'
                positionMap[s[i]] = i;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
