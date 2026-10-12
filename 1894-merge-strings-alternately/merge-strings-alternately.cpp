
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        string ans = "";

        int i = 0;

        while (i < n && i < m) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }

        while (i < n) {
            ans.push_back(word1[i]);
            i++;
        }

        while (i < m) {
            ans.push_back(word2[i]);
            i++;
        }

        return ans;
    }
};
