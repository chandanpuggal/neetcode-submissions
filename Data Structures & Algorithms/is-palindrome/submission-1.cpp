class Solution {

    // LeetCode: https://leetcode.com/problems/valid-palindrome/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=jJXJ16kPFWg

public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while ((left < s.length()) && (right >= 0) && (left < right)) {
            if (!isalnum(s[left])) {
                //cout << "invalid left" << endl;
                left++;
            }
            
            if (!isalnum(s[right])) {
                //cout << "invalid right" << endl;
                right--;
            }

            if (isalnum(s[left]) && isalnum(s[right])) {
                // mistake: I was adding islower instead of tolower
                if (tolower(s[left]) == tolower(s[right])) {
                    //cout << "valid match" << endl;
                    left++;
                    right--;
                } else {
                    //cout << "break: " << tolower(s[left]) << ", " <<  tolower(s[right]) << endl;
                    return false;
                }
            }
        }
        return true;
    }
};
