class Solution {
public:
    string defangIPaddr(string address) {
        int index=0;
        string ans;
        for(int i=0;i<address.length();i++)
        {
            if(address[i]=='.')
            ans+="[.]";
            else
            ans+=address[i];
        }
        return ans;
    }
};