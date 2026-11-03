class Solution {
public:
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
            
            index = index + delimPosition - index + 1;
            currentString = s.substr(index, currLen);
            strs.push_back(currentString);
            index = index + currLen;

            if (DEBUG)
                cout << currentString << ", ";
        }

        return strs;
    }
};
