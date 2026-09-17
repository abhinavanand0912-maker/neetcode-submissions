class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<pair<int,int>> div(26,{-1, -1});
        for(int i=0;i<s.size();i++){
            int x= s[i] - 'a';
            if(div[x].first==-1){
                div[x].first=i;
            }
            div[x].second=i;
        }
        int last=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            last=max(last,div[x].second);
            if(i==last){
                ans.push_back(last-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};
