class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int n = s1.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int left=0;
        for(char ch : s1){
            freq1[ch-'a']++;
        }
        for(int i=0;i<n;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2) return true;
        for(int right=n;right<s2.size();right++){
            freq2[s2[right]-'a']++;
            freq2[s2[left]-'a']--;
            left++;
            if(freq1==freq2) return true;
        }
        return false;
    }
};
