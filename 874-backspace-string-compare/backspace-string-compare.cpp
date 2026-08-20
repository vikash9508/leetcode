class Solution {
public:
string build(string a)
{
    stack<char>st;
    for(char ch:a)
    {
        if(ch=='#')
        {
            if(!st.empty())
            st.pop();

        }
        else
        {
            st.push(ch);
        }
    }
    string result;
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}
    bool backspaceCompare(string s, string t) {
       return build(s)==build(t); 
    }
};