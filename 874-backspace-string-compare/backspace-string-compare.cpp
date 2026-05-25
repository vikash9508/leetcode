class Solution {
public:

bool areEqual(stack<char> s1, stack<char> s2)
{
    if(s1.size() != s2.size())
        return false;

    while(!s1.empty())
    {
        if(s1.top() != s2.top())
            return false;

        s1.pop();
        s2.pop();
    }
    return true;
}

bool backspaceCompare(string s, string t) {

    stack<char> st1, st2;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='#')
        {
            if(!st1.empty())
                st1.pop();
        }
        else
            st1.push(s[i]);
    }

    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='#')
        {
            if(!st2.empty())
                st2.pop();
        }
        else
            st2.push(t[i]);   
    }

    return areEqual(st1,st2);
}
};