/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int count=0;
        int n=intervals.size();
        int s=0;
        int e=0;
        int ans=0;
        while(s<n){
            if(start[s]<end[e]){
                count++;
                s++;
                ans=max(count,ans);
            } else {
                e++;
                count--;
            }
        }
        return ans;
    }
};
