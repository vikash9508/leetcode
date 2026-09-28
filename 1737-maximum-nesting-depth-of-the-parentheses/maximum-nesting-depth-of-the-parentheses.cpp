class Solution {
public:
    int maxDepth(string s) {
      stack<char>st;
      size_t result=0;
      for(char ch:s)
      {
        if(ch=='(')
        {
            st.push('(');
        }
        else if(ch==')')
        {
            st.pop();
        }
        result=max(result,st.size());
      }  
      return result;
    }
};