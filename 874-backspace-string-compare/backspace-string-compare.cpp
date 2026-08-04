class Solution {
public:
bool isequal(stack<char>s1,stack<char>s2)
{
    if(s1.size()!=s2.size())
    return 0;
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
       stack<char>s1;
       stack<char>s2;
       for(int i=0;i<s.size();i++)
       {
        if(s[i]=='#')
        {
            if(!s1.empty())
            s1.pop();

        }
        else
        {
            s1.push(s[i]);
        }
       } 
        for(int i=0;i<t.size();i++)
       {
        if(t[i]=='#')
        {
            if(!s2.empty())
            s2.pop();

        }
        else
        {
            s2.push(t[i]);
        }
       } 

       return isequal(s1,s2);
    }
};