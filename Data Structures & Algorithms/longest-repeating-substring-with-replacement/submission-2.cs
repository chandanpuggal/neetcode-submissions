public class Solution {

int getMaxFrequecny(Dictionary<char, int> map) {
        int max = 0;

        foreach (var p in map) {
            max = Math.Max(max, p.Value);
        }

        return max;
    }

    public int CharacterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxLen = 0, currLen = 0, maxCharCount = 0, offset = 0;
        Dictionary<char, int> countMap = new Dictionary<char, int>();

        while (right < s.Length) {
            if (!countMap.ContainsKey(s[right])) {
                countMap[s[right]] = 1;
            } else {
                countMap[s[right]]++;
            }
            maxCharCount = getMaxFrequecny(countMap);
            currLen = right - left + 1;
            offset = currLen - maxCharCount;

            if (offset > k) {
                countMap[s[left]]--;
                left++;
            }
            
            maxLen = Math.Max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
}
