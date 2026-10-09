class Solution {
public:
    int minInsertions(string s) {
      int n=s.length();
      int i=0;
      int count=0;
      int result=0;

      while(i<n)
      {
        if(s[i]=='(')
        {
            count++;
            i++;
        }
        else
        {
            if(count>0)
            {
                count--;
            }
            else
            {
                result++;
            }
                if(s[i+1]==')'  &&  i+1<n)
                {
                    i+=2;
                }
                else
                {
                    i+=1;
                    result+=1;
                }
            
            
        }
      } 
      return result + 2*count; 
    }
};