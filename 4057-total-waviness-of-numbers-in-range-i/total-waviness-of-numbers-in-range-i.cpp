class Solution {
public:
    int findwaves(int x) {
        int score = 0;
        string s = to_string(x);
        int n = s.length();

        if (n < 3)
            return 0;

        for (int j = 1; j < n - 1; j++) {
            if (s[j] < s[j - 1] && s[j] < s[j + 1])
                score++;
            else if (s[j] > s[j - 1] && s[j] > s[j + 1])
                score++;
        }

        return score;
    }

    int totalWaviness(int num1, int num2) {
        int score = 0;

        for (int i = num1; i <= num2; i++) {
            score += findwaves(i);
        }

        return score;
    }
};