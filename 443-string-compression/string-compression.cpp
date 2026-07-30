class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int index=0;
        while(i<n)
        {
            char curr=chars[i];
            int count=0;
            while(i<n && chars[i]==curr)
            {
                count++;
                i++;
            }
            chars[index]=curr;
            index++;
            if(count>1)
            {
                string s=to_string(count);
                for(char &ch:s)
                {
                    chars[index]=ch;
                    index++;
                }
            }
           
        }
         return index;
    }
};