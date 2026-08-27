#include <string>
#include <vector>

class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (const string& s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.size(); // 1. Declare n
        
        while (i < n) {
            int j = i;
            while (j < n && s[j] != '#') {
                j++;
            }
            
            // 2. Pass (start_index, length)
            int len = stoi(s.substr(i, j - i)); 
            j++; // Skip the '#'
            
            ans.push_back(s.substr(j, len));
            i = j + len;
        }
        return ans;
    }
};