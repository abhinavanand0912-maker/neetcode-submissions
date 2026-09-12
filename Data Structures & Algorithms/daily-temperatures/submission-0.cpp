class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);   // initialize result with 0s
    stack<int> st;              // stack stores indices

    for (int i = 0; i < n; i++) {
        // While current temperature is warmer than the day at stack top
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();   // index of previous colder day
            st.pop();
            result[prev] = i - prev; // difference in days
        }
        st.push(i); // push current day index
    }
    return result;
}

};
