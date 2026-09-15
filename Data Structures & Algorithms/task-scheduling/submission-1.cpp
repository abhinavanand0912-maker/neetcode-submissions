class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto task : tasks){
            freq[task-'A']++;
        }
        int maxfreq=0;
        for(auto fre : freq){
            maxfreq=max(maxfreq,fre);
        }
        int countmax=0;
        for(auto fre : freq){
            if(fre==maxfreq) countmax++;
        }
        int ans = (maxfreq-1)*(n+1)+countmax;
        return max(ans, (int)tasks.size());
    }
};
