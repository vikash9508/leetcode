class Solution {
public:
    bool isequal(stack<char>s1,stack<char>s2)
    {
        if(s1.size()!=s2.size())
        {
            return 0;
        }
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top()==s2.top())
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                return 0;
            }
        }
        return 1;
        
    }
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(auto ch:s)
        {
            if(ch=='#')
            {
                if(!st1.empty())
                st1.pop();
            }
            else
            {
                st1.push(ch);
            }
        }
         for(auto ch:t)
        {
            if(ch=='#')
            {
                if(!st2.empty())
                st2.pop();
            }
            else
            {
                st2.push(ch);
            }
        }
        return isequal(st1,st2);
    }
};