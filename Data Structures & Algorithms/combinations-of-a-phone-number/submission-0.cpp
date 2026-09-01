class Solution {
public:
vector<string> mp={
            "","","abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };
        vector<string> ans;
        string curr;
    void solve(int i, string digits){
        if(i==digits.size()){
            ans.push_back(curr);
            return;
        }
        int k=digits[i]-'0';
        for(char ch : mp[k]){
            curr+=ch;
            solve(i+1,digits);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        solve(0,digits);
        return ans;
    }
};
