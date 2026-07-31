class Solution {
public:
    void reverseString(vector<char>& s) {
        deque<char>dq;
        for(char ch:s)
        {
            dq.push_front(ch);
        }
        for(int i=0;i<s.size();i++)
        {
            s[i]=dq[i];
        }
    }
};