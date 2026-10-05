class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;

        int score = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                st.push(score);
                score = 0;
            } else {
                if (s[i-1] == '(') { //we found inner most "()" -> +1 point
                    score = st.top() + 1;
                } else {
                    // had content inside -> double it
                    score = st.top() + (2 * score);
                }
                st.pop();
            }
        }
        return score;
    }
};
