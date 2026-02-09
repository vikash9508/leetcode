class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int index = 0, count = 0;

        while (index < s.size()) {
            if (s[index] == ' ') {
                int pos = temp.back() - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
                index++;   // IMPORTANT
            } 
            else {
                temp += s[index];
                index++;
            }
        }

        // Handle last word
        if (!temp.empty()) {
            int pos = temp.back() - '0';
            temp.pop_back();
            ans[pos] = temp;
            count++;
        }

        // Build answer
        string res;
        for (int i = 1; i <= count; i++) {
            res += ans[i];
            if (i != count) res += " ";
        }

        return res;
    }
};