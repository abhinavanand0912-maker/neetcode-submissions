class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int mx=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[i]<=heights[st.top()])){
                int h = heights[st.top()];
                st.pop();
                int right=i;
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                int width=right-left-1;
                int area=h*width;
                mx=max(mx,area);
            }
            st.push(i);
        }
        return mx;
    }
};
