class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                ans = max(ans, heights[index] * width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int index = st.top();
            st.pop();

            int width;
            if (st.empty())
                width = n;
            else
                width = n - st.top() - 1;

            ans = max(ans, heights[index] * width);
        }

        return ans;
    }
};