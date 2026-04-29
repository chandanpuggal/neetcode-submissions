class Solution {
public:

    // LeetCode: LC Premium locked
    // Video: https://www.youtube.com/watch?v=B1k_sxOSgv8

    char delimeter = '#';

    string encode(vector<string>& strs) {
        string result = "";
        string len;

        for (int i = 0; i < strs.size(); i++) {
            len = to_string(strs[i].length());
            result = result + len + delimeter + strs[i];
        }
        cout << "result: " << result << endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0, j = 0, currentLength = 0;
        string currentString = "";

        while (i < s.length()) {
            j = i;

            while (s[j] != delimeter) {
                j++;
            }
            currentLength = stoi(s.substr(i, j-i));

            cout << "currentLength: " << currentLength << endl;

            currentString = s.substr(j+1, currentLength);

            cout << "currentString: " << currentString << endl;

            i = j + currentLength + 1;

            result.push_back(currentString);
        }

        return result;
    }
};
