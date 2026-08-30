class Solution {
public:
string minWindow(string s, string t) {
int n = s.size();

    if(t.size() > s.size())
        return "";

    vector<int> window(128, 0);
    vector<int> need(128, 0);

    for(char ch : t) {
        need[ch]++;
    }

    int count = 0;
    int left = 0;

    int minlen = INT_MAX;
    int start = 0;

    for(int right = 0; right < n; right++) {

        char x = s[right];
        window[x]++;

        if(need[x] > 0 && window[x] <= need[x]) {
            count++;
        }

        while(count == t.size()) {

            if(right - left + 1 < minlen) {
                minlen = right - left + 1;
                start = left;
            }

            char c = s[left];
            window[c]--;

            if(need[c] > 0 && window[c] < need[c]) {
                count--;
            }

            left++;
        }
    }

    if(minlen == INT_MAX)
        return "";

    return s.substr(start, minlen);
}

};
