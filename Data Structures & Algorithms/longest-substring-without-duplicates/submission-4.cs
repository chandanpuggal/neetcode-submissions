public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var positionMap = new Dictionary<char, int>();
        int maxLen = 0, currLen = 0;
        int lastPosition, start = 0;

        for (int i = 0; i < s.Length; i++) {
            if (positionMap.ContainsKey(s[i])) {
                lastPosition = positionMap[s[i]];
                if (lastPosition >= start) {
                    start = lastPosition + 1;
                    currLen = i - lastPosition;
                } else {
                    currLen++;
                }
            } else {
                currLen++;
            }
            positionMap[s[i]] = i;
            maxLen = Math.Max(maxLen, currLen);
        }
        
        return maxLen;
    }
}
