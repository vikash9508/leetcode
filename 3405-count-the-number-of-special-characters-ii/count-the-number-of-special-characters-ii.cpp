class Solution {
public:
    int numberOfSpecialChars(string word) {
       int n=word.length();
       int count=0;
       vector<int>lsmall(26,-1);
       vector<int>fcapital(26,-1);
       for(int i=0;i<n;i++)
       {
        char ch=word[i];
        if(islower(ch))
        {
            lsmall[ch-'a']=i;
        }
        else
        {
            if(fcapital[ch-'A']==-1)
            fcapital[ch-'A']=i;
        }
       } 
       for(int i=0;i<26;i++)
       {
        if(lsmall[i]!=-1 && fcapital[i]!=-1 && lsmall[i] < fcapital[i])
        {
            count++;
        }
       }
       return count;
    }
};