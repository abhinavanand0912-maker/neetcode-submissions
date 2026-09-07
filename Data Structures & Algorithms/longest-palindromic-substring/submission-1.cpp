class Solution {
public:
    int expand(int l,int r,string s){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return (r-l-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            int odd=expand(i,i,s);
            int even=expand(i,i+1,s);
            int len=max(odd,even);
            if(len>maxlen){
                maxlen=len;
                start=i-(len-1)/2;
            }
        }
        return s.substr(start,maxlen);
        
    }
};
