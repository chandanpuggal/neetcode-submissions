class Solution {
public:
    // LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=gqXU1UyA8pk

    // find the char which has occurred max times in current window
    int findMaxValue(unordered_map<char, int> charCount) {
        int maxVal = 0;

        for (auto it = charCount.begin(); it != charCount.end(); it++) {
            maxVal = max(maxVal, it->second);
        }
        
        return maxVal;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;
        int left = 0, right = 0, maxLength = 0, currLength = 0, offset, maxCharCount = 0;

        for (right = 0; right < s.length(); right++) {
            // char not found in map
            if (charCount.find(s[right]) == charCount.end()) {
                charCount[s[right]] = 1;
            } else {
                charCount[s[right]]++;
            }

            maxCharCount = findMaxValue(charCount);
            currLength = right - left + 1;
            offset = currLength - maxCharCount;

            // idea is, whatever is the offset should be either replacable by same char 'k'
            // times or move the window to adjust offset.
            if (offset > k) {
                charCount[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
