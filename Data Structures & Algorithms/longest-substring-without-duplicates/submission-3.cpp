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
                // Example: in case like abba, you can't move start from 2 to 1 after 
                // finding conflict of 'a' after 'b'
                positionMap[s[i]] = i;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }

    // int lengthOfLongestSubstring(string s) {
    //     int start = 0, maxLength = 0, currLength = 0;
    //     unordered_map<char, int> positionMap;

    //     for (int i = 0; i < s.length(); i++) {
    //         if (positionMap.find(s[i]) == positionMap.end()) {
    //             positionMap[s[i]] = i;
    //         } else {
    //             start = max(start, positionMap[s[i]] + 1);
    //             positionMap[s[i]] = i;
    //         }

    //         currLength = i - start + 1;
    //         maxLength = max(maxLength, currLength);
    //     }
    //     return maxLength;
    // }
};
