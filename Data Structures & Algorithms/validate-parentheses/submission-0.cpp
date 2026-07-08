class Solution {
public:

    // LeetCode: https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=WTzjTskDFMg

    bool matchingElement(char ch, char top) {
        if ((top == '(') && ch == ')')
            return true;
        
        if ((top == '[') && ch == ']')
            return true;
        
        if ((top == '{') && ch == '}')
            return true;
        
        return false;
    }

    bool isValid(string s) {
        stack<char> myStack;
        char top;

        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                myStack.push(s[i]);
            } else {
                if (myStack.size() == 0) {
                    return false;
                } else {
                    top = myStack.top();
                    if (!matchingElement(s[i], top)) {
                        return false;
                    }
                    myStack.pop();
                }
            }
        }
        if (myStack.size() == 0)
            return true;
        else
            return false;
    }
};
