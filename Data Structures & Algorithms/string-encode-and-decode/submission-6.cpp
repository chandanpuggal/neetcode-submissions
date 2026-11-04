class Solution {
public:

    // LeetCode: LC Premium locked
    // Video: https://www.youtube.com/watch?v=B1k_sxOSgv8
    
    // Example: Hello, World or 5#Hello, 43#23World
    // Encoded: 5#Hello5#World or 7#5#Hello10#43#23World

    const char delim = '#';
    bool DEBUG = 0;
    
    string encode(vector<string>& strs) {
        string finalString = "";
        int len = 0;

        for (int i = 0; i < strs.size(); i++) {
            len = strs[i].length();
            finalString = finalString + to_string(len) + delim + strs[i];
        }
        if (DEBUG)
            cout << finalString << endl;

        return finalString;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string currentString;
        int strLen = s.length();
        int currLen = 0;
        int index = 0;
        int delimPosition = 0;

        while (strLen != index) {
            delimPosition = index;
            while (s[delimPosition] != delim) {
                delimPosition++;
            }

            currLen = stoi(s.substr(index, delimPosition-index));
            currentString = s.substr(delimPosition + 1, currLen);
            strs.push_back(currentString);
            index = delimPosition + 1 + currLen; // next string starting len char

            if (DEBUG)
                cout << currentString << ", ";
        }

        return strs;
    }
};
