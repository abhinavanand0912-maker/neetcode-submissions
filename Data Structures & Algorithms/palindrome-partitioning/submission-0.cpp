class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    bool check(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string& s,int start){
        if(start==s.size()){ 
            ans.push_back(curr);
        }
        for(int end=start;end<s.size();end++){
            if(check(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                solve(s,end+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};
